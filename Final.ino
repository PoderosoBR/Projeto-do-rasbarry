#include <SPI.h>
#include <Ethernet.h>

int pin = 0; // analog pin
int tempc = 0,tempf=0; // temperature variables
int samples[8]; // variables to make a better precision
int maxi = -100,mini = 100; // to start max/min temperature
int i;

// 54-BF-64-F6-7F-7B
byte mac[]     = {0x80, 0xEE, 0x73, 0x58, 0xB4, 0xDB }; // Must be unique on local network
byte ip[]      = { 192,168,0,55 };                // Must be unique on local network
byte subnet[]  = { 255, 255, 255, 0 };
byte gateway[] = { 192,168,0,1 };

// ThingSpeak Settings
char thingSpeakAddress[] = "api.thingspeak.com";
String writeAPIKey = "V1N02IPF2D4Z4C2G";    // Write API Key for a ThingSpeak Channel
const int updateInterval = 10000;        // Time interval in milliseconds to update ThingSpeak   

// Variable Setup
long lastConnectionTime = 0; 
boolean lastConnected = false;
int failedCounter = 0;

// Initialize Arduino Ethernet Client
EthernetClient client;
//----------------------------------------------------------------------------------------------------------------fim variaveis ethernet
EthernetClient clientJAVA;
byte serverJAVA[] = { 192, 168, 0, 11 };

long DURACAO;
float DISTANCIA;

int V6 =6 ;
int V5 =5 ;

int NAtras = 2 ;// direita N
int NBtras =  3 ; //esquerda N
int NCtras =  4; // direito S
int NDtras = 7; // esquerda S
//----------------------------------------- parte 2
#define V10 10
#define V11 11
#define NAFrente 19
#define NBFrente 18
#define NCFrente 9
#define NDFrente 8

/// -----------------FIM VARIAVEIS Carrinho

// variaveis do sensor 
#define echoPin 14//Pino ECHO do sensor no pino analógica A1
#define trigPin 15 //Pino TRIG do sensor no pino analógica A0
long duracao;
long HR_dist=0;
int minimumRange=5;
int maximumRange=200;
/// -----------------FIM VARIAVEIS SEnsor




int estadoNuvem;
  int ValorSensor=0;


int Distancia(){
  digitalWrite(trigPin, LOW); //não envia som
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH); //envia som 
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); //não envia o som e espera o retorno do som enviado
  duracao = pulseIn(echoPin,HIGH); //Captura a duração em tempo do retorno do som.
 return  HR_dist = duracao*0.017; //Calcula a distância
}


void setup(){

  Serial.begin(9600);
  Ethernet.begin(mac, ip, gateway, subnet);
  delay(1000);
  Serial.print("ETHERNET SHIELD ip  is     : ");
  Serial.println(Ethernet.localIP()); 
   // Start Ethernet on Arduino
  startEthernet();


  //---------------------------------------------------------------



  pinMode(trigPin, OUTPUT); //define o pino TRIG como saída
  pinMode(echoPin, INPUT); //define o pino ECHO como entrada

  pinMode(V5,OUTPUT);
  pinMode(V6,OUTPUT);
  
  pinMode(V10,OUTPUT);
  pinMode(V11,OUTPUT);


  pinMode(NAtras,OUTPUT);
  pinMode(NBtras,OUTPUT);
  pinMode(NCtras,OUTPUT);
  pinMode(NDtras,OUTPUT);
  
  pinMode(NAFrente,OUTPUT);
  pinMode(NBFrente,OUTPUT);
  pinMode(NCFrente,OUTPUT);
  pinMode(NDFrente,OUTPUT);

  digitalWrite(NAtras,LOW);
  digitalWrite(NBtras,LOW);
  digitalWrite(NCtras,LOW);
  digitalWrite(NDtras,LOW);
  
  digitalWrite(NAFrente,LOW);
  digitalWrite(NBFrente,LOW);
  digitalWrite(NCFrente,LOW);
  digitalWrite(NDFrente,LOW);


}//------------------------------------------------------ fim setup

void loop(){
        
 while (!clientJAVA.connected()) {
         Serial.println("\nEsta desconectado do servidor do JAVA ----------------------------------------------\n");
         delay(500);
         clientJAVA.connect(serverJAVA, 8888);
 }

   if (clientJAVA.connected()) {
          
        ValorSensor= Distancia(); //chama a função para medir a distância

        clientJAVA.write(ValorSensor);   
      
        int escolha = clientJAVA.read();
        int velocidade = clientJAVA.read();
        
        int v = 100;
        analogWrite(V5,v);
        analogWrite(V6,180);
        
        /*    
              analogWrite(V10,v);
            analogWrite(V11,v);

              digitalWrite(NAFrente,HIGH);
              digitalWrite(NBFrente,LOW);
              digitalWrite(NCFrente,HIGH);
              digitalWrite(NDFrente,LOW);
          */
          int x=0,y=0,z=0,w=0;
          if(escolha == 1) x = 1;
          if(escolha == 2) y = 2;
          if(escolha == 3) z = 3;
          if(escolha == 4) w = 4;
             
          
          if(x == 1){
        
              
               digitalWrite(NAtras,LOW);// direita N
               digitalWrite(NBtras,HIGH); // esquerda N
               digitalWrite(NCtras,LOW); // direita S
               digitalWrite(NDtras,HIGH); // esquerda S
         
  
              
          
          }else if(y == 2){
            
            digitalWrite(NAtras,LOW );// direita N
            digitalWrite(NBtras,HIGH); // esquerda N
            digitalWrite(NCtras,HIGH); // direita S
            digitalWrite(NDtras,LOW); // esquerda S
         
         
         }else if(z == 3){
            
            digitalWrite(NAtras,HIGH );// direita N
            digitalWrite(NBtras,LOW); // esquerda N
            digitalWrite(NCtras,LOW); // direita S
            digitalWrite(NDtras,HIGH); // esquerda S
         
         
         
         
         
         
         }else if(w == 4){
            
            digitalWrite(NAtras,HIGH);// direita N
            digitalWrite(NBtras,LOW); // esquerda N
            digitalWrite(NCtras,HIGH); // direita S
            digitalWrite(NDtras,LOW); // esquerda S
         } else if(escolha == 100 ){
           
           if(ValorSensor > 30){
                        
              digitalWrite(NAtras,LOW);// direita N
              digitalWrite(NBtras,HIGH); // esquerda N
              digitalWrite(NCtras,LOW); // direita S
              digitalWrite(NDtras,HIGH); // esquerda S
            }else {
              
            digitalWrite(NAtras,HIGH );// direita N
            digitalWrite(NBtras,LOW); // esquerda N
            digitalWrite(NCtras,LOW); // direita S
            digitalWrite(NDtras,HIGH); // esquerda S
            }
        
        }else if(escolha == 300 ){
         
            digitalWrite(NAtras,LOW);
            digitalWrite(NBtras,LOW);
            digitalWrite(NCtras,LOW);
            digitalWrite(NDtras,LOW);

            
       }else{
        
          delay(1000);
          digitalWrite(NAtras,LOW);
          digitalWrite(NBtras,LOW);
          digitalWrite(NCtras,LOW);
          digitalWrite(NDtras,LOW);

      }

         
        

   }//  fim 
   













  
  tempc = ValorSensor;
  
  String analogPin0 = String(tempc);
  
  // Print Update Response to Serial Monitor
  if (client.available())
  {
    char c = client.read();
    Serial.print(c);
  }
  
  // Disconnect from ThingSpeak
  if (!client.connected() && lastConnected)
  {
    Serial.println();
    Serial.println("...disconnected.");
    Serial.println();
    
    client.stop();
  }
  
  // Update ThingSpeak
  if(!client.connected() && (millis() - lastConnectionTime > updateInterval))
  {
    updateThingSpeak("field1="+analogPin0);
  }
  
  lastConnected = client.connected();
}/// ---------------------------------------------------------------- fim loop

void updateThingSpeak(String tsData)
{
  if (client.connect(thingSpeakAddress, 80))
  { 
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");

    client.print(tsData);
    
    lastConnectionTime = millis();
    
    if (client.connected())
    {
      Serial.println("Connecting to ThingSpeak...");
      Serial.println();
      
      failedCounter = 0;
    }
    else
    {
      failedCounter++;
  
      Serial.println("Connection to ThingSpeak failed ("+String(failedCounter, DEC)+")");   
      Serial.println();
    }
    
  }
  else
  {
    failedCounter++;
    
    Serial.println("Connection to ThingSpeak Failed ("+String(failedCounter, DEC)+")");   
    Serial.println();
    
    lastConnectionTime = millis(); 
  }
}

void startEthernet()
{
  
  client.stop();

  Serial.println("Connecting Arduino to network...");
  Serial.println();  

  delay(1000);
  
  // Connect to network amd obtain an IP address using DHCP
  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("DHCP Failed, reset Arduino to try again");
    Serial.println();
  }
  else {
    Serial.println("Arduino connected to network using DHCP");
    Serial.println();
    Serial.println("Data being uploaded to THINGSPEAK Server.......");
    Serial.println();
  }
  
  delay(1000);
}

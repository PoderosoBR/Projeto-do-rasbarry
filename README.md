Monitoramento na IoT
Atividade da Disciplina de Sistemas Operacionais II
Embarcado utilizado: Rasbarry pi 3 e Arduino uno

Linguagem de Programação: Java e C

Ambiente de Desenvolvimento: Netbeans e AduinoIDE
Plataforma de Nuvem na IoT utilizada: ThingSpeak

Tutoriais utilizados:
https://alselectro.wordpress.com/2017/05/01/ethernet-shield-arduino-upload-lm35-data-to-thingspeak/

Resumo das Funcionalidades:

Funcionalidades no embarcado
  - É  um carrinho chassis que é controlado pelo rasbarry pi, a comunicacão é via fio ethernet;
  - O carrinho tem um sensor ultrasonico para se mover;
  - Codigo do Netbeans é feito com SOCKET e THREAD;
  - E ele passa o valor do sensor para tela do netbeans quanto para a nuvem ThingSpeak;
 
  
Funcionalidades na Plataforma de Nuvem na IoT
  - Mostra o valor do sensor por grafico ; 
  
Comentários sobre os Códigos:
        - Codigo do Netbeans é feito com SOCKET e THREAD, no projeto foi criado apenas uma THREAD que cria um servidor para o Arduino se
     comunica com ele ultilizando um shild ethernet, ou seja, faz comunicação de cliente e servidor;
        - Codigo do Arduino é que faz os calculos da distancia do sensor para os objetos e envia para Java e para ThingSpeak;
        - Podemos controla os motores que sao passado pelo comando de  java pra arduino;
       
        
     
Observações:

No Resumo das Funcionalidades podem ser utilizadas imagens.
Podem ser incluídos links para sites externos
Quanto mais detalhes forem apresentados melhor
Observem que este texto é escrito utilizando o arquivo README.md
Nos Comentários sobre os Códigos devem ser registrados os aspectos mais interessantes da prototipação, bibliotecas selecionadas, etc.

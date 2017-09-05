#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
//Declaremos los pines CE y el CSN
#define CE_PIN 9
#define CSN_PIN 10

#define PWM_R 4
#define PWM_L 3
//Variable con la dirección del canal que se va a leer
byte direccion[5] ={'c','a','n','a','l'}; 

//creamos el objeto radio (NRF24L01)
RF24 radio(CE_PIN, CSN_PIN);

//vector para los datos recibidos
int datos[1];

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
 //inicializamos el NRF24L01 
  radio.begin();
  //inicializamos el puerto serie
  
  
  //Abrimos el canal de Lectura
  radio.openReadingPipe(1, direccion);
  
    //empezamos a escuchar por el canal
  radio.startListening();
 Serial.println("Puerto escuchando!");
}
 
void loop() {
  Serial.println("ggg");
 uint8_t numero_canal;
// if ( radio.available(&numero_canal) )
 if ( radio.available())
 {    
     //Leemos los datos y los guardamos en la variable datos[]
     radio.read(datos,sizeof(datos));
     if(datos[0] == 1){
     Serial.println("Se recibio palma");
     analogWrite(4,120);
     analogWrite(3,0);
     analogWrite(17,120);
     analogWrite(16,0);
     
     }
     else if(datos[0] == 2){
     Serial.println("Se recibio puño");
     analogWrite(3,0);
     analogWrite(4,0);
     
     analogWrite(16,0);
     analogWrite(17,0);
     }

     else if(datos[0] == 3){
     Serial.println("Se recibio indice");
     analogWrite(3,120);
     analogWrite(4,0);
     
     analogWrite(16,0);
     analogWrite(17,120);
     }

     else if(datos[0] == 4){
     Serial.println("Se recibio pulgar");
     analogWrite(3,0);
     analogWrite(4,120);
     
     analogWrite(16,120);
     analogWrite(17,0);
     }

     else if(datos[0] == 5){
     Serial.println("Se recibio ok");
     analogWrite(3,120);
     analogWrite(4,0);
     
     analogWrite(16,120);
     analogWrite(17,0);
     }
     //reportamos por el puerto serial los datos recibidos
     
 }
 delay(100);
}


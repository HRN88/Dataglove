#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Gestos.h"

//*******************************CONSTANTES**************************
//Se declaran los pines para el modulo de comunicación
#define CE_PIN 9
#define CSN_PIN 10
#define on 13
#define umbral 60                                                                                                                                                                                  
//Se definen los pines para el ADC

//*******************************************************************

//Vector para definir la direccion del canal de transmision
byte direccion[5] = {'c', 'a', 'n', 'a', 'l'};

//Objeto NRF
RF24 radio(CE_PIN, CSN_PIN);

//Vector con los datos a enviar
int datos[1];
//pulgar, indice , medio
int senapulgar[] = {4,4,0};
int senaindice[] = {3,3,0};
int senapalma[] = {1,1,0};
int senapuno[] = {2,2,0};
int senaok[] = {5,5,0};

int vector[3] = {10,10,10};

Gesto puno, palma, indice, pulgar, ok;


void setup() {
  // put your setup code here, to run once:
  pinMode(on, OUTPUT);
  digitalWrite(on, HIGH);
  //Inicializacion del modulo NRF24L01
  radio.begin();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Prendido");
  delay(1000);
  Serial.println("Iniciando");
  delay(1000);
  radio.openWritingPipe(direccion);
  palma.setParams(563,515,0,umbral,senapalma);
  puno.setParams(724,795,0,umbral,senapuno);
  indice.setParams(725,540,0,umbral,senaindice);
  pulgar.setParams(570,785,0,umbral,senapulgar);
  ok.setParams(712,700,0,umbral,senaok);

}

void loop() {
  // put your main code here, to run repeatedly:
  int pul =  analogRead(A2);
  int indi = analogRead(A1);
  //Imprimir los valores adquiridos en la terminal
  //indice.datosSensores(pul, indi, 0);
  palma.clasifica(pul, indi, 0, vector);
  puno.clasifica(pul, indi, 0, vector);
  indice.clasifica(pul, indi, 0, vector);
  pulgar.clasifica(pul, indi, 0, vector);
  ok.clasifica(pul, indi, 0, vector);


  if(vector[0] == 1 && vector[1] == 1 && vector[2] == 0){
    datos[0] = 1;
    Serial.println("Se ha detectado palma");   
    }
  if(vector[0] == 2 && vector[1] == 2 && vector[2] == 0){
    datos[0] = 2;
    Serial.println("Se ha detectado puño"); 
    
  }
  if(vector[0] == 3 && vector[1] == 3 && vector[2] == 0){
    datos[0] = 3;
    Serial.println("Se ha detectado indice"); 
    
  }
  if(vector[0] == 4 && vector[1] == 4 && vector[2] == 0){
    datos[0] = 4;
    Serial.println("Se ha detectado pulgar"); 
    
  }
  if(vector[0] == 5 && vector[1] == 5 && vector[2] == 0){
    datos[0] = 5;
    Serial.println("Se ha detectado ok"); 
    
  }
  bool ok = radio.write(datos, sizeof(datos));
  delay(500);
//  Serial.print(vector[0]);
//  Serial.print(" ");
//  Serial.print(vector[1]);
//  Serial.print(" ");
//  Serial.print(vector[2]);
//  Serial.print(" ");
//  Serial.print(" ");
//  Serial.print(indi);
//  Serial.print(" ");
//  Serial.println(medi);


}

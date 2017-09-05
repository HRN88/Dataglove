
#include"Arduino.h"
#include"Gestos.h"

void Gesto::setParams(int pulgar, int indice, int medio, int umbral, int codigo[]){
  pulgar_= pulgar;
  indice_ = indice;
  medio_ = medio;
  umbral_ = umbral;
  codigo_[0] = codigo[0];
  codigo_[1] = codigo[1];
  codigo_[2] = codigo[2];
}

void Gesto::datosSensores(int cp, int ci, int cm){
  //Este metodo imprime los valores que se estan leyendo en tiempo real
  Serial.print("Pulgar: ");
  Serial.print(cp);
  Serial.print(" Indice: ");
  Serial.print(ci);
  Serial.print(" Medio: ");
  Serial.println(cm);
  
}
void Gesto::getParams(){
  //Solo si esta abierto el puerto de comunicacion para mostrar la informacion en la consola
  Serial.print("Pulgar = "); Serial.print(pulgar_); 
  Serial.print(" Indice = "); Serial.print(indice_);
  Serial.print(" Medio = "); Serial.print(medio_);
  Serial.print(" Umbral = "); Serial.println(umbral_);
}

void Gesto::clasifica(int pulgar, int indice, int medio, int vector[]){
  //Se realiza la comparacion de cada dedo con el valor configurado mas menos, un umbral.
  //Si se encuentra dentro de rango se asigna un 1 si no un 0
  int flags[3];
  //Para dedo pulgar
  if((pulgar <= pulgar_ + umbral_)&& (pulgar >= pulgar_ - umbral_)) flags[0] = 1;
  else flags[0] = 0;

   //Para dedo indice
  if((indice <= indice_ + umbral_)&& (indice >= indice_ - umbral_)) flags[1] = 1;
  else flags[1] = 0;

   //Para dedo medio
  if((medio <= medio_ + umbral_)&& (medio >= medio_ - umbral_)) flags[2] = 1;
  else flags[2] = 0;

  if(flags[0] == 1 && flags[1] == 1 && flags[2] == 1){
    vector[0] = codigo_[0];
    vector[1] = codigo_[1];
    vector[2] = codigo_[2];
  }
  



  
}


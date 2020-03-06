#include "Bateria.h"
#include "arduino.h"
Bateria::Bateria(int pin, float minV, float maxV){
  _pinAnalog = pin;
  pinMode(_pinAnalog,OUTPUT);

  _minVolt = minV;
  _maxVolt = maxV;
}
Bateria::Bateria(){};
void Bateria::fresh(){
  setVoltaje();
}

void Bateria::setVoltaje(){
  voltaje=analogRead(_pinAnalog)*5.0/1023.0; //Should be constants too
  setCarga();
  setState();
}

void Bateria::setCarga(){
  if(voltaje>_maxVolt){carga=100.0;}else if(voltaje<_minVolt){carga=0.0;}
  else{carga=(voltaje-_minVolt)/(_maxVolt-_minVolt)*100.0;}
}

void Bateria::setState(){
  if(voltaje < _minVolt){estado = BAT_LOW;}
  else if(voltaje > _maxVolt){estado = BAT_HIGH;}
  else{estado = BAT_OK;}
}

State Bateria::getState(){
  return estado;
}
float Bateria::getVoltaje(){
  return voltaje;
}

float Bateria::getCarga(){
  return carga;
}

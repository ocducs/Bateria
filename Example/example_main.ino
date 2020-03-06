#include <Bateria.h>

//Objeto bateria
int pinBat=0;
float minV=2.8;
float maxV=4.5;
Bateria miBat;

// timming
float pastMillis=0;
float actualMillis;

// programa
bool ledState=LOW;
int LED=8;
void setup() {
  Serial.begin(9600);
  //construir bateria
  miBat=Bateria(pinBat,minV,maxV);
  //fijar pinLED como salida
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  miBat.fresh();
  float voltaje=miBat.getVoltaje();
  float carga=miBat.getCarga();
  State estado=miBat.getState();

  switch(estado){
    case BAT_LOW:
      blinking(2000,200);break;
    case BAT_OK:
      blinking(500,500);break;
    case BAT_HIGH:
      blinking(200,1000);break;
  }
  analogWrite(LED,ledState);
  Serial.println(ledState);
  //Serial.println((String)voltaje+" "+(String)carga+" "+(String)estado+" "+(String)ledState);
}
void blinking(int t_off,int t_on){
  actualMillis=millis();
  if(ledState && actualMillis-pastMillis>t_on){
      ledState=!ledState;
      pastMillis=actualMillis;
  }
  else if(!ledState && actualMillis-pastMillis>t_off){
      ledState=!ledState;
      pastMillis=actualMillis;
  }
}

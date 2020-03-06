#ifndef Bateria_h
#define Bateria_h
enum State{BAT_LOW, BAT_OK, BAT_HIGH};
#include <arduino.h>

class Bateria
{
  private:
    int _pinAnalog;
    //    Voltaje al minimo de carga, máximo, voltaje en bateria, carga en bateria
    float _minVolt,_maxVolt,voltaje,carga;
    void setState();
    void setCarga();
    void setVoltaje();
  public:
    State estado;
    Bateria(int pin, float minV, float maxV);//constructor
    Bateria();//constructor
    void fresh();
    float getVoltaje();
    float getCarga();
    State getState();
};

#endif

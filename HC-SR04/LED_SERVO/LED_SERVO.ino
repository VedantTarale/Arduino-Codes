#include<Servo.h>
Servo s;
int servo_pos;
class LEDBlink{
    int led;
    unsigned int onTime;
    unsigned int offTime;
    int ledState;
    unsigned long previousMillis;
  public:
    LEDBlink(int led_pin,unsigned int oT, unsigned int ofT){
        led = led_pin;
        
    }
};
void setup() {

}

void loop() {
  
}

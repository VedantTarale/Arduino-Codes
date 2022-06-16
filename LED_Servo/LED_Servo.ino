#include <Servo.h>
class LED
{
private:
    int led;
    unsigned int onTime;
    unsigned int offTime;
    unsigned long previousMillis;
    int ledState;

public:
    LED(int led_pin, unsigned int oT, unsigned int offT)
    {
        led = led_pin;
        pinMode(led, OUTPUT);
        onTime = oT;
        offTime = offT;
        ledState = LOW;
        previousMillis = 0;
    }
    void update()
    {
        unsigned long currentMillis = millis();
        if ((ledState == HIGH) && (currentMillis - previousMillis >= onTime))
        {
            ledState = LOW;
            previousMillis = currentMillis;
            digitalWrite(led, LOW);
        }
        else if ((ledState == LOW) && (currentMillis - previousMillis >= offTime))
        {
            ledState = HIGH;
            previousMillis = currentMillis;
            digitalWrite(led, HIGH);
        }
    }
};
class servo_motor
{
private:
    Servo s;
    unsigned long previousMillis;
    int timeSet;

public:
    servo_motor(int pin)
    {
        s.attach(pin); // assignes a pin to the servo object
        s.write(0);    // sets servo to 0degs;
        timeSet = LOW;  //timeSet stores if the time at which the update method is called is assigned to previousMillis or not
    }
    int update(int val, unsigned long time)
    {
        s.write(val);
        if (timeSet == LOW)
        {
            previousMillis = time;
            timeSet = HIGH;
        }
        if ((millis() - previousMillis) >= 30)
            timeSet = LOW;
        if (s.read() == val && timeSet==LOW)
            return 1;
    }
};
LED led1(13, 1000, 1000);
servo_motor s1;
int readstate = 0;
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    int a;
    led1.update();
    
    if (Serial.available() > 0 && readstate == 0)
    {
        a = Serial.read();
        readstate = 1;
    }
    if (readstate == 1)
    {
        if (s1.update(a, millis())){
          readstate = 0;
          Serial.println("Servo Updated");
        }
    }
}

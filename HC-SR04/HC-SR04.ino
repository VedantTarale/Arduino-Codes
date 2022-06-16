const int trigger = 5;const int echo = 6; long duration; int distance;
void setup(){
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4,1);
  digitalWrite(7,0);
  Serial.begin(9600);
}
int ping(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;
  return distance;
  }
void loop(){
  Serial.println(ping());
  delay(20);
}

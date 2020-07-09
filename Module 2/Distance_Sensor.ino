int trig=3;
int echo=4;

void setup(){
  Serial.begin(4800);
}
void loop(){
  pinMode(trig,OUTPUT);
  long duration, Cm;
  //long microsecondsToCentimeters(float microseconds);
  //long microseconds;
  digitalWrite (trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration=pulseIn(echo,HIGH);
  Cm = microsecondsToCentimeters(duration);
  Serial.print("The distance is ");
  Serial.println(Cm);
  delay(5000);
}

long microsecondsToCentimeters (long microseconds)
{
   return microseconds /29 /2;
  }
  
  
    

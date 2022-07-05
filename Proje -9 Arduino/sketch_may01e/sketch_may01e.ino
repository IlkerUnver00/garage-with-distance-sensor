#include<Servo.h>
int R=11;
int G=13;
const int trigPin = 2;  
const int echoPin = 4;
const int trigPin2 = 8;  
const int echoPin2 = 10; 
Servo myservo,myservo2;
char Incoming_value;             
int tx=0;
int rx = 1;
void setup() 
{
  Serial.begin(9600);
  myservo.attach(6);
  myservo2.attach(12);
}
void loop()
{
  long duration, cm, duration2, cm2;    
pinMode(trigPin, OUTPUT);   
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);  
delayMicroseconds(20);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);  
duration = pulseIn(echoPin, HIGH); 
pinMode(trigPin2, OUTPUT);   
digitalWrite(trigPin2, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);  
delayMicroseconds(20);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);  
duration2 = pulseIn(echoPin2, HIGH);
cm2 = microsecondsToCentimeters(duration2); 
cm = microsecondsToCentimeters(duration); 
  
if ( cm > 20) 
{
myservo.write(0);

}
else if ( cm < 20 && cm > 5)   
{
  Serial.println("2");
for(int derece = 0; derece <= 90; derece=derece+10){   
myservo.write(derece);
delay(700);
analogWrite(R, 255);
    delay(400);
analogWrite(R, 0);
  delay(400);

 }
delay(2000);
Serial.println("1");
for(int derece2 = 90; derece2 >= 0; derece2=derece2-10){   
myservo.write(derece2);
delay(700);
analogWrite(G, 255);
    delay(400);
analogWrite(G, 0);
  delay(400);
 }

}
if ( cm2 > 18) 
{

myservo2.write(90);
}

else if ( cm2 <18 && cm2 > 5)   
{
    Serial.println("2");
for(int derece = 90; derece >= 0; derece=derece-10){   
myservo2.write(derece);
delay(700);
analogWrite(R, 255);
    delay(400);
analogWrite(R, 0);
  delay(400);

 }
delay(2000);
Serial.println("1");
for(int derece2 = 0; derece2 <= 90; derece2=derece2+10){   
myservo2.write(derece2);
delay(700);
analogWrite(G, 255);
    delay(400);
analogWrite(G, 0);
  delay(400);
 }
}
  if(Serial.available()>0)  
  {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);       
    Serial.print("\n");
    if((Incoming_value == '0')){   
         Serial.println("2");
for(int derece = 0; derece <= 90; derece=derece+10){   
myservo.write(derece);
delay(700);
analogWrite(R, 255);
    delay(400);
analogWrite(R, 0);
  delay(400);
 }
      delay(2000);
Serial.println("1");
for(int derece2 = 90; derece2 >= 0; derece2=derece2-10){   
myservo.write(derece2);
delay(700);
analogWrite(G, 255);
    delay(400);
analogWrite(G, 0);
  delay(400);
 }
    }
  }                            
 
}  
long microsecondsToCentimeters(long microseconds) {

return microseconds / 29 / 2;
}         

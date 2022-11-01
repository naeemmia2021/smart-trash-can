#include<Servo.h>
int trigpin1=8;
int echopin1=9;
int trigpin2=10;
int echopin2=11;
int lpin1=4;
int lpin2=5;
float distance1;
float duration1;
float distance2;
float duration2;
int count=0;
int count2=0;
int flag=0;
int flag2=0;
Servo servo;
int i;
int check=0;
void setup() {
  // put your setup code here, to run once:
servo.attach(6);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);
pinMode(trigpin2,OUTPUT);
pinMode(echopin2,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(check==0){
  servo.write(0);
  }

   
  digitalWrite(trigpin1,LOW);
  delay(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin1,LOW);
  duration1= pulseIn(echopin1, HIGH);
  distance1= (duration1*.034)/2;
  Serial.print("The distance1 is= ");
  Serial.print(distance1);
  Serial.print("cm \n");
  while(count < 15)
  {
      digitalWrite(trigpin1,LOW);
  delay(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin1,LOW);
  duration1= pulseIn(echopin1, HIGH);
  distance1= (duration1*.034)/2;
   if(distance1<20){
     flag++;
   }
  if(flag == 4)
  {
    for(i=0;i<=80;i+=10){
          servo.write(i);
          delay(100); 
            }
    break;
   
   }
   count++;
  }
   while(count2 < 15)
  {
      digitalWrite(trigpin1,LOW);
  delay(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin1,LOW);
  duration2= pulseIn(echopin1, HIGH);
  distance2= (duration2*.034)/2;
   if(distance2>20){
     flag2++;
   }
  if(flag2 == 4)
  {
    for(i=80;i>=0;i=i-10){
          servo.write(i);
          delay(100); 
            }
    break;
   
   }
   count2++;
  }
  flag=0;
  flag2=0;
  count=0;
  count2=0;
}
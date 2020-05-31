float  poids;
float  poids1;
float  poids2;
float precis=0.5;
float poidsvoulue=0;
int millepoids;
int millepoidsvoulue;
float poidslimite=poidsvoulue+0.002;
#include <Wire.h>
int inByte;
int inByte1;
int blo=false;
float dm;
int dt;

int enA = 10;
int in1 = 9;
int in2 = 8;
void setup() {
  // put your setup code here, to run once:
 Serial1.begin(2400);
 Serial2.begin(9600);
 //Serial.begin(9600);
  pinMode(enA, OUTPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
}

void loop() {
  dm=0;
  if (Serial1.available()>0)
  {  inByte = Serial1.read();
      poids=Serial1.parseFloat();}
     
 if (Serial2.available()>0) {
  inByte1 = Serial2.read();
//  Serial.print(inByte1);
  
  if (inByte1=='1') {
    poidsvoulue=poidsvoulue+0.1;
 // Serial.print(inByte1);
   String command1 = "t2.txt=\""+String(poidsvoulue,4)+"\"";
   Serial2.print(command1);
    endNextionCommand();
  }
    if (inByte1=='2') {
    poidsvoulue=poidsvoulue-0.1;
     String command2 = "t2.txt=\""+String(poidsvoulue,4)+"\"";
   Serial2.print(command2);
    endNextionCommand();
  }
 if (inByte1=='5') {
    poidsvoulue=poidsvoulue+0.01;
     String command5 = "t2.txt=\""+String(poidsvoulue,3)+"\"";
   Serial2.print(command5);
    endNextionCommand();
  }
  if (inByte1=='6') {
    poidsvoulue=poidsvoulue-0.01;
     String command6 = "t2.txt=\""+String(poidsvoulue,3)+"\"";
   Serial2.print(command6);
    endNextionCommand();
 }
   if (inByte1=='0') {
    precis=precis-0.1;
       String command10 = "t12.txt=\""+String(precis,3)+"\"";
   Serial2.print(command10);
    endNextionCommand();
 }
   if (inByte1=='4') {
   precis=precis+0.1;
      String command11 = "t12.txt=\""+String(precis,3)+"\"";
   Serial2.print(command11);
    endNextionCommand();
 }
    if (inByte1=='3') {
    blo=true;
   
     
     inByte = Serial1.read();
      poids1=Serial1.parseFloat();
      poids2=Serial1.parseFloat();
      poids=min(poids1,poids2);
     while ((poids<poidsvoulue)&&(blo==true)){
      if (Serial1.available()>0 )
     { inByte = Serial1.read();
      poids1=Serial1.parseFloat();
      poids2=Serial1.parseFloat();
      poids=min(poids1,poids2);
 millepoids=int (poids*1000);
 millepoidsvoulue=int (poidsvoulue*1000);
      
  dt=(poidsvoulue-poids)*300+precis;
 
  
  dm=abs(dt);
 

      if (dt==0){analogWrite(enA, 0);blo=false;}
       String command8 = "t3.txt=\""+String(poids,3)+"\"";
   Serial2.print(command8);
    endNextionCommand();
      
      
 

 if (dm<2){dm=2;}
 
     digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
// définit la vitesse à 200 sur la plage possible 0 ~ 255
analogWrite(enA, 200);
delay(dm);
analogWrite(enA, 0);
     delay(2);

     }

 }
 
 }
}}
void endNextionCommand()
{   Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);}

 

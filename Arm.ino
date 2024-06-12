#include <Servo.h>
#define trig 2
#define echo 4

#define MOTOR_ENA 10
#define MOTOR_ENB 11
#define MOTOR_IN1 9
#define MOTOR_IN2 8
#define MOTOR_IN3 13
#define MOTOR_IN4 12

Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;

int A=95;
int B=65;
int C=180;
int D=115;

#define SIR A3
#define MIR A4
#define LIR A5



void setup() 

{
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_ENB, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);

  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);

  Serial.begin(9600);

  pinMode(SIR, INPUT);
  pinMode(MIR, INPUT);
  pinMode(LIR, INPUT);

  servoA.attach(3);
  servoB.attach(5);
  servoC.attach(6);
  servoD.attach(7);
}

void loop()
{
  int SIRValue = analogRead(SIR);
  int MIRValue = analogRead(MIR);
  int LIRValue = analogRead(LIR);

  servoA.write(95);
  servoB.write(65);
  servoC.write(180);
  servoD.write(115);


  digitalWrite (trig,LOW);
  delayMicroseconds(2);
  digitalWrite (trig,HIGH);
  delayMicroseconds(10);
  digitalWrite (trig,LOW);
 
 long t = pulseIn (echo,HIGH);

 long inches = t / 74 / 2 ;
 long cm = t / 29 / 2 ;


 Serial.print(inches);
 Serial.print("in ");
 Serial.print(cm);
 Serial.print("cm");

 Serial.print(SIRValue );
 Serial.print("SIR   ");
 Serial.print(MIRValue);
 Serial.print("MIR   ");
 Serial.print(LIRValue);
 Serial.println("LIR   ");
 delay (10);

  if  (inches < 3 )
 {
    analogWrite (A2,130);
    MBS();
    delay(10);
 }

 
    else if (SIRValue<700 && MIRValue>700 && LIRValue>700  )
    {
      SIRM();
      delay (1000);
    }

    else if (SIRValue<700 && MIRValue<700 && LIRValue>700  )

    {
      MIRM();
      delay (1000);
    }

    else if (SIRValue<700 && MIRValue<700 && LIRValue<700  )

    {
      LIRM();
      delay (1000);
    }

    else 
    {
      analogWrite (A2,0);
      MBF();
    strtmeArm();
    delay(100);
    }
 }

void MBF() {
  // Move main belt 
  analogWrite(MOTOR_ENA,250);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);

}

void MBS() {
  // stop main belt
  analogWrite(MOTOR_ENA,0);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, HIGH);
}

void BF() {
  // Move main belt 
  analogWrite(MOTOR_ENB,250);
  digitalWrite(MOTOR_IN3, HIGH);
  digitalWrite(MOTOR_IN4, LOW);
}

void BS() {
  // stop main belt
  analogWrite(MOTOR_ENB,0);
  digitalWrite(MOTOR_IN3, HIGH);
  digitalWrite(MOTOR_IN4, HIGH);
}


void strtmeArm()
{
  servoA.write(95);
  servoB.write(65);
  servoC.write(180);
  servoD.write(115);
}


void SIRM()
{
for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

do 
  {
    servoB.write(B);
    servoD.write(D);
   
    D--;
    delay(10);
    
    B=B+3;
    delay(10); 
  }
  
  while 
        (D >= 90);
        (B <= 140);
        
        delay(1000);



for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


do 

  {
     servoB.write(B);
    servoD.write(D);
    D++;
    delay(5);
    B=B-3;
    delay(5);
  }
  while 
        (D <= 115);
        (B >= 65);
         delay(100);
for (C; C>= 120; C--) 
      {
       servoC.write(C);
       delay(10);
      }

    delay(1000);

   


for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

for (A; A>= 90; --A) 


      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


for (C; C<= 180; ++C) 
      {
       servoC.write(C);
       delay(10);
      }
    
    delay(1000);

}



void MIRM()
{
for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


do 
  {
    servoB.write(B);
    servoD.write(D);
   
    D--;
    delay(10);
    
    B=B+3;
    delay(10); 
  }
  
  while 
        (D >= 90);
        (B <= 140);
        
        delay(1000);



for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


do 

  {
     servoB.write(B);
    servoD.write(D);
    D++;
    delay(5);
    B=B-3;
    delay(5);
  }
  while 
        (D <= 115);
        (B >= 65);
         delay(100);

for (C; C>= 60; C--) 
      {
       servoC.write(C);
       delay(10);
      }

    delay(1000);


for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);
for (C; C<= 180; ++C) 
      {
       servoC.write(C);
       delay(10);
      }
    
    delay(1000);
  
}


void LIRM()
{
for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


do 
  {
    servoB.write(B);
    servoD.write(D);
   
    D--;
    delay(10);
    
    B=B+3;
    delay(10); 
  }
  
  while 
        (D >= 90);
        (B <= 140);
        
        delay(1000);



for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);


do 

  {
     servoB.write(B);
    servoD.write(D);
    D++;
    delay(5);
    B=B-3;
    delay(5);
  }
  while 
        (D <= 115);
        (B >= 65);
         delay(100);
for (C; C>= 0; C--) 
      {
       servoC.write(C);
       delay(10);
      }

    delay(1000);
   


for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

for (C; C<= 180; ++C) 
      {
       servoC.write(C);
       delay(10);
      }
    
    delay(1000);
  
}
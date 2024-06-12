#include <Servo.h>
#define trig 2         // Define pin for ultrasonic sensor trigger
#define echo 4        // Define pin for ultrasonic sensor echo

// Motor control pin definitions
#define MOTOR_ENA 10
#define MOTOR_ENB 11
#define MOTOR_IN1 9
#define MOTOR_IN2 8
#define MOTOR_IN3 13
#define MOTOR_IN4 12

// Initialize servo objects
Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;

// Initial positions of servos
int A=95;
int B=65;
int C=180;
int D=115;

// Infrared sensor pin definitions
#define SIR A3
#define MIR A4
#define LIR A5



void setup() 

{
  // Set motor control pins as outputs
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_ENB, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);
 // Set ultrasonic sensor pins
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);

  Serial.begin(9600);  // Start serial communication at 9600 baud rate
// Set infrared sensor pins as inputs
  pinMode(SIR, INPUT);
  pinMode(MIR, INPUT);
  pinMode(LIR, INPUT);
 // Attach servos to their respective pins
  servoA.attach(3);
  servoB.attach(5);
  servoC.attach(6);
  servoD.attach(7);
}

void loop()
{ 
  // Read values from infrared sensors
  int SIRValue = analogRead(SIR);
  int MIRValue = analogRead(MIR);
  int LIRValue = analogRead(LIR);
  
// Set initial positions of servos
  servoA.write(95);
  servoB.write(65);
  servoC.write(180);
  servoD.write(115);

// Trigger the ultrasonic sensor
  digitalWrite (trig,LOW);
  delayMicroseconds(2);
  digitalWrite (trig,HIGH);
  delayMicroseconds(10);
  digitalWrite (trig,LOW);
 
 long t = pulseIn (echo,HIGH);
  
// Convert time into distance
 long inches = t / 74 / 2 ;
 long cm = t / 29 / 2 ;

// Print distance and sensor values to serial monitor
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
  
// Decision making based on distance and sensor values
  if  (inches < 3 )
 {
    analogWrite (A2,130);  // Activate some actuator with value 130
    MBS();  // Stop the main belt
    delay(10);
 }

 
    else if (SIRValue<700 && MIRValue>700 && LIRValue>700  )
    {
      SIRM();  // Perform SIRM operation
      delay (1000);
    }

    else if (SIRValue<700 && MIRValue<700 && LIRValue>700  )

    {
      MIRM();  // Perform MIRM operation
      delay (1000);
    }

    else if (SIRValue<700 && MIRValue<700 && LIRValue<700  )

    {
      LIRM();  // Perform LIRM operation
      delay (1000);
    }

    else 
    {
      analogWrite (A2,0);  // Deactivate the actuator
      MBF();      // Move the main belt forward
    strtmeArm();  // Reset the arm positions
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
  // Reset servo arm positions to initial
  servoA.write(95);
  servoB.write(65);
  servoC.write(180);
  servoD.write(115);
}


void SIRM()   // Sequence for SIRM operation
{
for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);
 // Move servos B and D to a specific position
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


// Return servo A to initial position
for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

// Return servos B and D to initial positions
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

  // Move servo C to a specific position
for (C; C>= 120; C--) 
      {
       servoC.write(C);
       delay(10);
      }
    delay(1000);
  
// Repeat initial sequence for servo A
for (A; A<= 110; ++A) 
      {
       servoA.write(A);
       delay(20);
      }
    delay(1000);
  
// Return servo A to initial position
for (A; A>= 90; --A) 
      {
       servoA.write(A);
       delay(20);
      }

    delay(1000);

// Return servo C to initial position
for (C; C<= 180; ++C) 
      {
       servoC.write(C);
       delay(10);
      }
    
    delay(1000);

}



void MIRM()     // Sequence for MIRM operation (similar to SIRM)
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
// Move servo C to a different position compared to SIRM
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


void LIRM()   // Sequence for LIRM operation (similar to SIRM and MIRM)
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

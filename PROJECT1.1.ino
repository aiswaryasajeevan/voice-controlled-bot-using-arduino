//VOICE CONTROLLED BOT USING ARDUINO
//AUTHOR:AISWARYA SAJEEVAN

#include<SoftwareSerial.h>

int firstvalue;
float radius;//input the radius mine is 0.33
String secval;
#define IN1 12//left one
#define IN2 11
#define IN3 10//right one
#define IN4 9
#define EN1 6
#define EN2 5
volatile int counterA=0;
volatile int counterB=0;


//mentioning the hardware details/

const float stepcount=20.0;//20 slots in a disk//

int distosteps(float dis)
{
  int result;
  float circumference = (2*radius*3.14);//circumference in cm
  float rotation = dis/circumference;
  float f_result = rotation * stepcount;
  result =(int) f_result;
  return result;//resulting no of steps
}
void Left_ISR()
{
  counterA++;
  }

void Right_ISR()
{
  counterB++;
  } 



void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
 pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  //pinMode(EN2, OUTPUT);
 
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
  Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(2),Left_ISR,RISING); // TO trigger the left wheel
    attachInterrupt(digitalPinToInterrupt(3), Right_ISR,RISING); // To trigger the right wheel
    Serial.begin(9600);
}





   //code for the direction


 void MoveForward(int steps, int mspeed)
 {
  counterA=0;
  counterB=0;

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);


  while (steps > counterA && steps > counterB)
    {

        if (steps > counterA)
        {
            analogWrite(EN1, mspeed);
        }
        else
        {
            analogWrite(EN1, 0);
        }
        if (steps > counterB)
        {
            analogWrite(EN2, mspeed);
        }
        else
        {
            analogWrite(EN2, 0);
        }
    }

    // Stop when done
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
    counterA = 0; //  reset counter A to zero
    counterB = 0; //  reset counter B to zero
}

 


void MoveBackward(int steps, int mspeed)
 {
  counterA=0;
  counterB=0;

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);


  while (steps > counterA && steps > counterB)
    {

        if (steps > counterA)
        {
            analogWrite(EN1, mspeed);
        }
        else
        {
            analogWrite(EN1, 0);
        }
        if (steps > counterB)
        {
            analogWrite(EN2, mspeed);
        }
        else
        {
            analogWrite(EN2, 0);
        }
    }

   
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
    counterA = 0; //  reset counter A to zero
    counterB = 0; //  reset counter B to zero
}

  


void MoveRight(int steps, int mspeed)
 {
  counterA=0;
  counterB=0;

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);


  while (steps > counterA && steps > counterB)
    {

        if (steps > counterA)
        {
            analogWrite(EN1, mspeed);
        }
        else
        {
            analogWrite(EN1, 0);
        }
        if (steps > counterB)
        {
            analogWrite(EN2, mspeed);
        }
        else
        {
            analogWrite(EN2, 0);
        }
    }

    // Stop when done
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
    counterA = 0; //  reset counter A to zero
    counterB = 0; //  reset counter B to zero
}

  

  void MoveLeft(int steps, int mspeed)
 {
  counterA=0;
  counterB=0;

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);


  while (steps > counterA && steps > counterB)
    {

        if (steps > counterA)
        {
            analogWrite(EN1, mspeed);
        }
        else
        {
            analogWrite(EN1, 0);
        }
        if (steps > counterB)
        {
            analogWrite(EN2, mspeed);
        }
        else
        {
            analogWrite(EN2, 0);
        }
    }

    // Stop when done
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
    counterA = 0; //  reset counter A to zero
    counterB = 0; //  reset counter B to zero
}

  


void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() >0)
  {
    delay(10);
    String firstval = Serial.readStringUntil( ' ' );
    Serial.read();
    delay(3);
    String secval = Serial.readStringUntil( '\n' ); 
    Serial.read();
    int firstvalue  = firstval.toInt();
    
    
    }

    
       if (secval== "*Forward")
        {
            MoveForward(distosteps(firstvalue), 255);//255 is the max speed
        }
        else if (secval == "*Backward")
        {
            MoveBackward(distosteps(firstvalue), 255);
        }
        else if (secval == "*right")
        {
            MoveRight(distosteps(firstvalue), 255);
        }
        else if (secval== "*left")
        {
           MoveLeft(distosteps(firstvalue), 255);
        }
         
    
      
}

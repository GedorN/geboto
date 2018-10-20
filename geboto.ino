#include <Servo.h>
const int SERVO = 11;


const int EN1 = 9;
const int IN1 = 7;
const int IN2 = 6;

const int EN2 = 10;
const int IN3 = 5;
const int IN4 = 4;

const int TRIGGER = 2;
const int ECHO = 3;

const int LED = 8;

float period;
float distance_cm;

Servo myServo;
int val = 0;
int rate = 1;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(SERVO);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIGGER, OUTPUT);
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(10);

  pinMode(ECHO, INPUT);

  pinMode(LED, OUTPUT);
}

void loop() {



  if (val <= 0)
  {
    rate = 50;
  }
  else if (val >= 179)
  {
    rate = -50;
  }

  val += rate;
  myServo.write(val);
  delay(100);



  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);


  period = pulseIn(ECHO, HIGH);
  delayMicroseconds(10);


  distance_cm = (period * 0.0343) / 2;

  if (distance_cm <= 8)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }




  // put your main code here, to run repeatedly:
  /*myServo.write(179);
    delay(1000);
    myServo.write(90);
    delay(10000);
    myServo.write(0);
    delay(1000);
    myServo.write(90);
    delay(1000);*/
  //myServo.write(90);

}




void backward(int rate)
{
  //analogWrite(EN1, 0);
  //analogWrite(EN2, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, rate);




  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN2, rate * 0.77);

}


void foward(int rate)
{
  //analogWrite(EN1, 0);
  // analogWrite(EN2, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, rate);




  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, rate * 0.77);
}

void left(int rate)
{
  //analogWrite(EN1, 0);
  //digitalWrite(EN2, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, rate);




  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, rate * 0.77);
}

void right(int rate)
{
  //analogWrite(EN1, 0);
  // analogWrite(EN2, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, rate);




  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN2, rate * 0.77);
}
void breake()
{
  //digitalWrite(EN1, LOW);
  // digitalWrite(EN2, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);

  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);

  //digitalWrite(EN1, HIGH);
  // digitalWrite(EN2, HIGH);
}

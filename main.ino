// Sensor Pins
#define LL A4
#define L A3
#define C A2
#define R A1
#define RR A0

// Left Motor Pins
#define MLF 2 
#define MLB 4
#define MLSPEED 6

// Right Motor Pins
#define MRF 0
#define MRB 1
#define MRSPEED 5

void leftMotor(int speed)
{
  if (speed >= 0)
  {
    digitalWrite(MLF, HIGH);
    digitalWrite(MLB, LOW);
    analogWrite(MLSPEED, map(speed, 0, 100, 0, 255));
  }
  else
  {
    digitalWrite(MLF, LOW);
    digitalWrite(MLB, HIGH);
    analogWrite(MLSPEED, map(-speed, 0, 100, 0, 255));
  }
}

void rightMotor(int speed)
{
  if (speed >= 0)
  {
    digitalWrite(MRF, HIGH);
    digitalWrite(MRB, LOW);
    analogWrite(MRSPEED, map(speed, 0, 100, 0, 255));
  }
  else
  {
    digitalWrite(MRF, LOW);
    digitalWrite(MRB, HIGH);
    analogWrite(MRSPEED, map(-speed, 0, 100, 0, 255));
  }
}

void stop()       {leftMotor(0);  rightMotor(0);}
void hardForward(){leftMotor(100);rightMotor(100);}
void softForward(){leftMotor(50); rightMotor(50);}
void softLeft()   {leftMotor(-50);rightMotor(50);}
void softRight()  {leftMotor(50); rightMotor(-50);}
void hardLeft()   {leftMotor(100);rightMotor(0);}
void hardRight()  {leftMotor(0);  rightMotor(100);}

void setup()
{
  pinMode(LL, INPUT);
  pinMode(L, INPUT);
  pinMode(C, INPUT);
  pinMode(R, INPUT);
  pinMode(RR, INPUT);

  pinMode(MLF, OUTPUT);
  pinMode(MLB, OUTPUT);
  pinMode(MLSPEED, OUTPUT);

  pinMode(MRF, OUTPUT);
  pinMode(MRB, OUTPUT);
  pinMode(MRSPEED, OUTPUT);
}

void loop()
{
  int s = digitalRead(LL) * 10000 +  digitalRead(L) * 1000 +  digitalRead(C) * 100 + digitalRead(R) * 10 + digitalRead(RR);

  if(s==1 || s==11 || s==111 || s==1111) hardRight();
  else if(s==110 || s==10) softRight();
  else if(s==100 || s==1110) hardForward();
  else if(s==1100 || s==1000) softLeft();
  else if(s==10000 || s==11000 || s==11100 || s==11110) hardLeft();
  else if(s==11111) stop();
  else softForward();
}

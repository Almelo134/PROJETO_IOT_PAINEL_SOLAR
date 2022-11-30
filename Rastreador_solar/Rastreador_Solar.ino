#include <Servo.h>

Servo horizontal;

int horizontal_pos = 0;
int LDRE = A0;
int LDRD = A1;
int diferenca = 0;
int LDE = 0;
int LDD = 0;
int erro = 10;

void setup()
{
  pinMode(LDRE, INPUT);
  pinMode(LDRD, INPUT);
  horizontal.attach(3);
  delay(100);
  Serial.begin(9600);
}

void loop()
{
  LDE = analogRead(LDRE);
  LDD = analogRead(LDRD);

  if(LDE < 400 && LDD < 400)
  {
    while(horizontal_pos <= 140 && horizontal_pos  >= 15)
    {
      horizontal_pos ++;
      horizontal.write(horizontal_pos);
      delay(100);
    }
  }
  diferenca = LDE - LDD;

 if(diferenca > 10)
  {
    if(horizontal_pos <= 180)
    {
      horizontal_pos ++;
      horizontal.write(horizontal_pos);
    }
  }
  else if (diferenca < -10)
  {
    if(horizontal_pos >= 15)
    {
      horizontal_pos --;
      horizontal.write(horizontal_pos);
    }
  }
  Serial.print("LDRE: ");
  Serial.print(LDE);
  Serial.print("  LDRD: ");
  Serial.print(LDD);
  delay(100);
}

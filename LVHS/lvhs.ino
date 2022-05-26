#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo servo1;
Servo servo2;

int gRxPin=10;
int gTxPin=11;

SoftwareSerial BTSerial(gRxPin, gTxPin);

void setup() {
Serial.begin(38400);
BTSerial.begin(38400);
//servo1.attach(9);
//servo2.attach(10);
}

char val;

void serv(char val) {
  servo1.write(val - '0');
}

void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}

void back()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD); // rotate the motor anti-clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(BACKWARD); // rotate the motor anti-clockwise
}

void right()
{
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD);  // rotate the motor clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(FORWARD);  // rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);  // Define minimum velocity
  motor1.run(RELEASE); // stop the motor when release the button
  motor2.setSpeed(0);  // Define minimum velocity
  motor2.run(RELEASE); // rotate the motor clockwise
}

void loop() {
if (BTSerial.available()){
  val = BTSerial.read();
   switch (val)
   {
   case 'F':
     forward();
     break;
   case 'B':
     back();
     break;
   case 'L':
     left();
     break;
   case 'R':
     right();
     break;
   case 'f':
     Stop();
     break;
   case 'b':
     Stop();
     break;
   case 'r':
     Stop();
     break;
   case 'l':
     Stop();
     break;
   }
}
}

#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

AF_DCMotor motor1(4);
AF_DCMotor motor2(2);
Servo servo_1;
Servo servo_2;

int initspeed = 255;
int deg1 = 0;
int deg2 = 90;
int count = 10;
int dly = 50;
char val;

SoftwareSerial BTSerial(11, 12);

void setup() {
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
servo_1.attach(9);
servo_2.attach(10);
Serial.begin(38400);
BTSerial.begin(38400);
servo_1.write(deg1);
servo_2.write(deg2);
}

void loop() {
if (BTSerial.available()){
  val = BTSerial.read();
  Serial.println(val);
  motor1.setSpeed(initspeed);
  motor2.setSpeed(initspeed);
   switch (val)
   {
   case 'F':
     motor1.run(FORWARD);
     motor2.run(FORWARD);
     break;
   case 'B':
     motor1.run(BACKWARD);
     motor2.run(BACKWARD);
     break;
   case 'L':
     motor1.run(FORWARD);
     motor2.run(BACKWARD);
     break;
   case 'R':
     motor1.run(BACKWARD);
     motor2.run(FORWARD);  
     break;
   case 's':
     motor1.run(RELEASE);
     motor2.run(RELEASE);
     break;
   case '1':
     initspeed = 50;
     break;
   case '2':
     initspeed = 125;
     break;
   case '3':
     initspeed = 255;
     break;
   case 'X':
     servo_1.write(0);
     break;
   case 'O':
     servo_2.write(90);
     break;
   case 'a':
     count = 1;
     break;
   case 'b':
     count = 5;
     break;
   case 'c':
     count = 10;
     break;
   case 'N':
     deg1 = servo_1.read();
     if(deg1 < 180) {
      deg1+=count;
      servo_1.write(deg1);
      delay(dly);
      }
     break;
   case 'S':
     deg1 = servo_1.read();
     if(deg1 > 0) {
      deg1-=count;
      servo_1.write(deg1);
      delay(dly);
      }
     break;
   case 'W':
     deg2 = servo_2.read();
     if(deg2 > 0) {
      deg2-=count;
      servo_2.write(deg2);
      delay(dly);
      }
      break;
    case 'E':
     deg2 = servo_2.read();
     if(deg2 < 180) {
      deg2+=count;
      servo_2.write(deg2);
      delay(dly);
      }
      break;
    case 'P':
     digitalWrite(A0, HIGH);
     delay(500);
     digitalWrite(A0, LOW);
     digitalWrite(A1, HIGH);
     delay(1000);
     digitalWrite(A1, LOW);
     break;
   }}
}

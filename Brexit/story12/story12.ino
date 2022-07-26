/*
#include <NewPing.h>

#define TRIGGER_PIN  13  
#define ECHO_PIN     17  
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int sensorPin = A6;    
int sensorValue = 0;  
int Rspeed = 255;
int Lspeed = 255;
int brightestlight = 1000;
int brightestturn = 0;


void loop() {
   sensorValue = analogRead(sensorPin);
   
   Serial.println(sensorValue);
   delay(250);
   for (int turn = 0; turn < 10; turn ++){
   right(0);
   delay(840);
   sensorValue = analogRead(sensorPin);-
   if (sensorValue < brightestlight) {
   }
   Stop(0);
   forward(0);
    
}
sensorvalue = analogRead(sensorPin);
void forward(int Delasensorvalue = analogRead(sensorPin);y) {
  analogWrite(Renabler, Rspeed);
  analo
  gWrite(Lenabler, Lspeed);
  digitalWrite(Rforward, HIGH);
  digitalWrite(Lforward, HIGH);
  digitalWrite(Rreverse, LOW);
  digitalWrite(Lreverse, LOW);
  delay(Delay);
}

void Stop(int Delay) {
  digitalWrite(Renabler, HIGH);
  digitalWrite(Lenabler, HIGH);
  digitalWrite(Rforward, HIGH);
  digitalWrite(Lforward, HIGH);
  digitalWrite(Rreverse, HIGH);
  digitalWrite(Lreverse, HIGH);
  delay(Delay);
}

void right(int Delay) {
  analogWrite(Renabler, 0);
  analogWrite(Lenabler, 255);
  digitalWrite(Rforward, HIGH);
  digitalWrite(Lforward, HIGH);
  digitalWrite(Rreverse, LOW);
  digitalWrite(Lreverse, LOW);
  delay(Delay);
}
*/
int motor_left[] = {1, 2};
int motor_right[] = {7, 8};
const int RightSensor = A0;
const int LeftSensor = A1;
int SensorLeft;
int SensorRight;
int SensorDifference; 

void setup() {
int i; 
for(i = 0; i < 2; i++){ 
  pinMode(motor_left[i], OUTPUT); 
  pinMode(motor_right[i], OUTPUT); }
  pinMode(LeftSensor, INPUT); 
  pinMode(RightSensor, INPUT); 
  digitalWrite(A0, HIGH); 
  digitalWrite(A1, HIGH); 
  Serial.begin(9600); 
  Serial.println(" \nBeginning Light Seeking Behavior");

}

void loop() {

SensorLeft = 1023 - analogRead(LeftSensor); // This reads the value of the sensor, then saves it to the corresponding integer.
SensorRight = 1023 - analogRead(RightSensor); // This reads the value of the sensor, then saves it to the corresponding integer.
SensorDifference = abs(SensorLeft - SensorRight); 
Serial.print("Left Sensor = "); 
Serial.print(SensorLeft); 
Serial.print("\t"); 
Serial.print("Right Sensor = "); 
Serial.print(SensorRight); 
Serial.print("\t"); 
if (SensorLeft<500 && SensorRight<500) { motor_stop();
Serial.println("Stop"); }
if (SensorLeft > SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) {
  turn_left();
  Serial.println("Left"); 
}

if (SensorLeft < SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) { 
  turn_right();
  Serial.println("Right"); 

}

else if (SensorLeft>500 && SensorRight>500 && SensorDifference < 75) { // This is interpreted as if the difference between the two sensors is under 125 (Experiment to suit our sensors), Do this:
  drive_forward(); 
  Serial.println("Forward"); // This prints Forward when the robot would actually go forward.

}

Serial.print("\n");

} 
void motor_stop(){ 
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], LOW);
  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], LOW); 
  }

void drive_forward(){ 
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);
  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW); 
  }

void drive_backward(){ 
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);
  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], HIGH); 
  }

void turn_left(){ 
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], HIGH);
  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW); 
  }

void turn_right(){ 
  digitalWrite(motor_left[0], HIGH); 
  digitalWrite(motor_left[1], LOW);
  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], HIGH); 
}

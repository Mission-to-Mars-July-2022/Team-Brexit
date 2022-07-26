#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int LEFT_FEEDBACK = 3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ;
const int RIGHT_FEEDBACK = 2;
volatile int leftcounter = 0;
volatile int rightcounter = 0;
int Lforward = 11;
int Lreverse = 12;
int Rreverse = 8;
int Lenabler = 10;
int Renabler = 9;
int Rforward = 7;

int Lspeed = 255;
int Rspeed = 255;



//setup function runs once when you press reset or power the board
void setup()
{
  pinMode(Lreverse, OUTPUT);
  pinMode(Lforward, OUTPUT);
  pinMode(Rforward, OUTPUT);
  pinMode(Renabler, OUTPUT);
  pinMode(Lenabler, OUTPUT);
  pinMode(Rreverse, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
  Serial.begin(115200); 
  Serial.print(sonar.ping_cm());
}

void loop () {
  forward(0);
  delay(33);
  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if( (sonar.ping_cm() > 15) and (sonar.ping_cm() > 0)) {
    Stop(1000);
    reverse(4000);
    Stop(1000);
    forward(1500);
    Stop(1000);
    right(1700);
    forward(1590);
    Stop(1000);
    right(1700);
    forward(1750);
    Stop(1000);
    right(1700);
    forward(1600);
    Stop(1000);
    right(1700);
    reverse(600);
    Stop(20000);
   
    
 

  
 
  
  }

  
}
void forward(int Delay) {
  analogWrite(Renabler, Rspeed);
  analogWrite(Lenabler, Lspeed);
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

void left(int Delay) {
  analogWrite(Renabler, 255);
  analogWrite(Lenabler, 0);
  digitalWrite(Rforward, HIGH);
  digitalWrite(Lforward, HIGH);
  digitalWrite(Rreverse, LOW);
  digitalWrite(Lreverse, LOW);
  delay(Delay);
}

void reverse(int Delay) {
  digitalWrite(Renabler, HIGH);
  digitalWrite(Lenabler, HIGH);
  digitalWrite(Rforward, LOW);
  digitalWrite(Lforward, LOW);
  digitalWrite(Rreverse, HIGH);
  digitalWrite(Lreverse, HIGH);
  delay(Delay);
}

void LeftMotorISR() {
  leftcounter++;
}

void RightMotorISR() {
  rightcounter++;
}

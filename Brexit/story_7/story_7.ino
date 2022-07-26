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
void setup() {

  pinMode(Lreverse, OUTPUT);
  pinMode(Lforward, OUTPUT);
  pinMode(Rforward, OUTPUT);
  pinMode(Renabler, OUTPUT);
  pinMode(Lenabler, OUTPUT);
  pinMode(Rreverse, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
}

void loop  () {
  
    forward(1500);
    Stop(1000);
    right(1600);
    forward(1500);
    Stop(1000);
    right(1600);
    forward(1500);
    Stop(1000);
    right(1600);
    forward(1500);
    Stop(1000);
    right(1600);
    
  }  
 

  Serial.print("Left Counter");
  Serial.println(leftcounter);

  Serial.print("Right Counter");
  Serial.println(rightcounter);
  
  if (rightcounter > leftcounter) {   // vearing left
    Rspeed = 150;
    Lspeed = 255;
  }
  /*
  if (leftcounter > rightcounter) {    // vearing right
    Rspeed = 255;
    Lspeed = 150;
  }
*/
  if (leftcounter == rightcounter) {    // vearing right
    Rspeed = 210;
    Lspeed = 255;
  }
  if (rightcounter > 870) {
    Stop(100);
    exit(0);
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

void reverse() {
  digitalWrite(Renabler, HIGH);
  digitalWrite(Lenabler, HIGH);
  digitalWrite(Rforward, LOW);
  digitalWrite(Lforward, LOW);
  digitalWrite(Rreverse, HIGH);
  digitalWrite(Lreverse, HIGH);
}

void LeftMotorISR() {
  leftcounter++;
}

void RightMotorISR() {
  rightcounter++;
}

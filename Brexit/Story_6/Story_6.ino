const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;
volatile int leftcounter = 0;
volatile int rightcounter = 0;
int Lforward = 11;
int Lreverse = 12;
int Rreverse = 8;
int Lenabler = 10;
int Renabler = 9;
int Rforward = 7;

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
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
}

void loop () {
  digitalWrite(Renabler, HIGH);
  digitalWrite(Lenabler, HIGH);

  digitalWrite(Rforward, HIGH);
  digitalWrite(Lforward, HIGH);
  delay(10000);

  Serial.print("Left Counter");
  Serial.println(leftcounter);
  
  Serial.print("Right Counter");
  Serial.println(rightcounter);
}
void LeftMotorISR(){
  leftcounter++;
}
void RightMotorISR(){
rightcounter++;
}

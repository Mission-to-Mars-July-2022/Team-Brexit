int Rforward = 7;
int Lforward = 11;
int Lreverse = 12;
int Rreverse = 8;
int Lenabler = 10;
int Renabler = 9;


//setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Lreverse, OUTPUT);
  pinMode(Lforward, OUTPUT);
  pinMode(Rforward, OUTPUT);
  pinMode(Renabler, OUTPUT);
  pinMode(Lenabler, OUTPUT);
  pinMode(Rreverse, OUTPUT);
}

// the loop function runs over and over again forever

void loop() {
  digitalWrite(Renabler, HIGH); 
  digitalWrite(Lenabler, HIGH);    
  
  digitalWrite(Lforward, HIGH);  
  digitalWrite(Rforward, HIGH);   
  delay(10000);
  
                         
  
  digitalWrite(Rreverse, HIGH);  
  digitalWrite(Lreverse, HIGH);
  delay(1000);
  digitalWrite(Lforward, LOW);   
  digitalWrite(Rforward, LOW);
  delay(2000);  
  digitalWrite(Rreverse, LOW);  
  digitalWrite(Lreverse, LOW);
  
  digitalWrite(Renabler, LOW); 
  digitalWrite(Lenabler, LOW); 
}

int speedM1 = 3; 
int dirM1_A = 4;
int dirM1_B = 5;

int speedM2 = 8; 
int dirM2_A = 6;
int dirM2_B = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");



  pinMode(dirM1_A, OUTPUT);
  pinMode(dirM1_B, OUTPUT);
  pinMode(speedM1, OUTPUT);   
  
  pinMode(dirM2_A, OUTPUT);
  pinMode(dirM2_B, OUTPUT);
  pinMode(speedM2, OUTPUT);   
  
}

void loop() {
  
  digitalWrite(dirM1_A, HIGH);
  digitalWrite(dirM1_B, LOW);
  analogWrite(speedM1, 255);
  
  digitalWrite(dirM2_A, HIGH);
  digitalWrite(dirM2_B, LOW);
  analogWrite(speedM2, 255);

  /*
  digitalWrite(dirM5_A, HIGH);
  digitalWrite(dirM5_B, LOW);
  analogWrite(speedM5, 255);
  digitalWrite(dirM6_A, HIGH);
  digitalWrite(dirM6_B, LOW);
  analogWrite(speedM6, 255);
  */
  delay(2000);

  digitalWrite(dirM1_A, LOW);
  digitalWrite(dirM1_B, HIGH);
  analogWrite(speedM1, 255);
  
  digitalWrite(dirM2_A, LOW);
  digitalWrite(dirM2_B, HIGH);
  analogWrite(speedM2, 255);

  //digitalWrite(dirM1_A, LOW);
  //digitalWrite(dirM1_B, HIGH);
  //analogWrite(speedM1, 51);
  /*
  digitalWrite(dirM2_A, LOW);
  digitalWrite(dirM2_B, HIGH);
  analogWrite(speedM2, 255);
  digitalWrite(dirM3_A, LOW);
  digitalWrite(dirM3_B, HIGH);
  analogWrite(speedM3, 255);
  digitalWrite(dirM4_A, LOW);
  digitalWrite(dirM4_B, HIGH);
  analogWrite(speedM4, 255);
  digitalWrite(dirM5_A, LOW);
  digitalWrite(dirM5_B, HIGH);
  analogWrite(speedM5, 255);
  digitalWrite(dirM6_A, LOW);
  digitalWrite(dirM6_B, HIGH);
  analogWrite(speedM6, 255);
  */
  delay(2000);
}

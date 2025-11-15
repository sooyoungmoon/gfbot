int speedM1 = 2; 
int dirM1_A = 22;
int dirM1_B = 23;

int speedM2 = 3; 
int dirM2_A = 24;
int dirM2_B = 25;

int speedM3 = 4; 
int dirM3_A = 26;
int dirM3_B = 27;

int speedM4 = 5; 
int dirM4_A = 28;
int dirM4_B = 29;

int speedM5 = 6; 
int dirM5_A = 30;
int dirM5_B = 31;

int speedM6 = 7; 
int dirM6_A = 32;
int dirM6_B = 33;



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

  pinMode(dirM3_A, OUTPUT);
  pinMode(dirM3_B, OUTPUT);
  pinMode(speedM3, OUTPUT);  
  
  pinMode(dirM4_A, OUTPUT);
  pinMode(dirM4_B, OUTPUT);
  pinMode(speedM4, OUTPUT);
  
  pinMode(dirM5_A, OUTPUT);
  pinMode(dirM5_B, OUTPUT);
  pinMode(speedM5, OUTPUT);

  pinMode(dirM6_A, OUTPUT);
  pinMode(dirM6_B, OUTPUT);
  pinMode(speedM6, OUTPUT);   
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirM1_A, HIGH);
  digitalWrite(dirM1_B, LOW);
  analogWrite(speedM1, 150);  
  
  digitalWrite(dirM2_A, HIGH);
  digitalWrite(dirM2_B, LOW);
  analogWrite(speedM2, 150);

  digitalWrite(dirM3_A, HIGH);
  digitalWrite(dirM3_B, LOW);
  analogWrite(speedM3, 150);
  
  digitalWrite(dirM4_A, HIGH);
  digitalWrite(dirM4_B, LOW);
  analogWrite(speedM4, 150);
  
  digitalWrite(dirM5_A, HIGH);
  digitalWrite(dirM5_B, LOW);
  analogWrite(speedM5, 150);

  digitalWrite(dirM6_A, HIGH);
  digitalWrite(dirM6_B, LOW);
  analogWrite(speedM6, 150);
  
  delay(2000);

  digitalWrite(dirM1_A, LOW);
  digitalWrite(dirM1_B, HIGH);
  analogWrite(speedM1, 150);
  
  digitalWrite(dirM2_A, LOW);
  digitalWrite(dirM2_B, HIGH);
  analogWrite(speedM2, 150);

  digitalWrite(dirM3_A, LOW);
  digitalWrite(dirM3_B, HIGH);
  analogWrite(speedM3, 150);

  digitalWrite(dirM4_A, LOW);
  digitalWrite(dirM4_B, HIGH);
  analogWrite(speedM4, 150);

  digitalWrite(dirM5_A, LOW);
  digitalWrite(dirM5_B, HIGH);
  analogWrite(speedM5, 150);

  digitalWrite(dirM6_A, LOW);
  digitalWrite(dirM6_B, HIGH);
  analogWrite(speedM6, 150);

  delay(2000);
}

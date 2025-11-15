#include <Servo.h>
#include <Arduino.h>

float linear_velocity = 0.0;
float angular_velocity = 0.0;
const float wheel_separation = 0.2; // the distance between left and right motors 20 cm 

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
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0) {
    String message = Serial.readStringUntil('\n');
    parseMessage(message);    
    // control motors using linear and angular velocities
    float v_left = linear_velocity - angular_velocity * (wheel_separation / 2.0); 
    float v_right = linear_velocity + angular_velocity * (wheel_separation / 2.0);
    int dir_left = (v_left > 0)? 1: 0; // 1: forward, 0: backward
    int dir_right = (v_right > 0)? 1: 0; // 1: forward, 0: backward


    float v_left_abs = (v_left>0)? v_left : (-1.0) * v_left;
    float v_right_abs = (v_right>0)? v_right : (-1.0) * v_right;

    float vel_min_abs = 0.0; // m/s
    float vel_max_abs = 1.1;
    float new_min = 0; 
    float new_max = 255; 



    float v_left_norm = (v_left_abs - vel_min_abs) * (new_max - new_min) / (vel_max_abs - vel_min_abs) + new_min;
    float v_right_norm = (v_right_abs - vel_min_abs) * (new_max - new_min) / (vel_max_abs - vel_min_abs) + new_min;
    // Control motors on the left side 
       // normalize v_left to the range between 0~255
       // for each left motor,
         // set the direction if (v_left < 0), set it as backward. if not, set it as forward
         // set the speed 
          Serial.print("v_left: ");
          Serial.println(v_left);
          Serial.print("v_right: ");
          Serial.println(v_right);

          Serial.print("v_left_norm: ");
          Serial.println(v_left_norm);
          Serial.print("v_right_norm: ");
          Serial.println(v_right_norm);

         if (dir_left < 1) {
          digitalWrite(dirM1_A, LOW);
          digitalWrite(dirM1_B, HIGH);
          digitalWrite(dirM2_A, LOW);
          digitalWrite(dirM2_B, HIGH);
          digitalWrite(dirM3_A, LOW);
          digitalWrite(dirM3_B, HIGH);          
         }
         else {
          digitalWrite(dirM1_A, HIGH);
          digitalWrite(dirM1_B, LOW);                    
          digitalWrite(dirM2_A, HIGH);
          digitalWrite(dirM2_B, LOW);
          digitalWrite(dirM3_A, HIGH);
          digitalWrite(dirM3_B, LOW);          
         }
         analogWrite(speedM1, v_left_norm);
         analogWrite(speedM2, v_left_norm);
         analogWrite(speedM3, v_left_norm);

    // Contro motors on the right side
      // normalize v_right to the range between 0~255
      // for each right motor,
       // set the direction if (v_left < 0), set it as backward. if not, set it as forward
       // set the speed 
       if (dir_right < 1) {
        digitalWrite(dirM4_A, LOW);
        digitalWrite(dirM4_B, HIGH);
        digitalWrite(dirM5_A, LOW);
        digitalWrite(dirM5_B, HIGH);
        digitalWrite(dirM6_A, LOW);
        digitalWrite(dirM6_B, HIGH);
       }
       else {
        digitalWrite(dirM4_A, HIGH);
        digitalWrite(dirM4_B, LOW);        
        digitalWrite(dirM5_A, HIGH);
        digitalWrite(dirM5_B, LOW);
        digitalWrite(dirM6_A, HIGH);
        digitalWrite(dirM6_B, LOW);
       }
        analogWrite(speedM4, v_right_norm);
        analogWrite(speedM5, v_right_norm);
        analogWrite(speedM6, v_right_norm);
  }
}

void parseMessage(String message) { 
  int separatorIndex = message.indexOf(','); 
  if (separatorIndex > 0) 
  { 
    linear_velocity = message.substring(0, separatorIndex).toFloat(); 
    angular_velocity = message.substring(separatorIndex + 1).toFloat(); 
    Serial.print("linear_velocity: ");
    Serial.println(linear_velocity);
    Serial.print("angular_velocity: ");
    Serial.println(angular_velocity);
  }
  
}
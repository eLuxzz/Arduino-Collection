#define MOTOR_A_SPEED_PIN 3
#define MOTOR_B_SPEED_PIN 5
#define MOTOR_B_PIN1 6
#define MOTOR_B_PIN2 7
#define MOTOR_A_PIN1 8
#define MOTOR_A_PIN2 9



void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_A_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_A_PIN1, OUTPUT);
  pinMode(MOTOR_A_PIN2, OUTPUT);
  pinMode(MOTOR_B_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_B_PIN1, OUTPUT);
  pinMode(MOTOR_B_PIN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void forward(){
  digitalWrite(MOTOR_B_PIN1, HIGH);
  digitalWrite(MOTOR_B_PIN2, LOW);
  analogWrite(MOTOR_B_SPEED_PIN, 200);  

  digitalWrite(MOTOR_A_PIN1, HIGH);
  digitalWrite(MOTOR_A_PIN2, LOW);
  analogWrite(MOTOR_A_SPEED_PIN, 200); 
}
void backwards(){
  digitalWrite(MOTOR_B_PIN1, LOW);
  digitalWrite(MOTOR_B_PIN2, HIGH);
  analogWrite(MOTOR_B_SPEED_PIN, 200);  

  digitalWrite(MOTOR_A_PIN1, LOW);
  digitalWrite(MOTOR_A_PIN2, HIGH);
  analogWrite(MOTOR_A_SPEED_PIN, 200); 
}

void left(){
  analogWrite(MOTOR_B_SPEED_PIN, 100);  
  analogWrite(MOTOR_A_SPEED_PIN, 200); 
}

void right(){
  analogWrite(MOTOR_B_SPEED_PIN, 200);  
  analogWrite(MOTOR_A_SPEED_PIN, 100); 
}

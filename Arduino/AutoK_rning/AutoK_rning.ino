//Bluetooth
int led3 = 2;
int ledFlag3 = 0;
int led13 = 13;
int ledFlag13 = 0;
char character;

//Motor
#define MOTOR_A_SPEED_PIN 3 //Left motor
#define MOTOR_B_SPEED_PIN 5 //Right motor
#define MOTOR_B_PIN1 6
#define MOTOR_B_PIN2 7
#define MOTOR_A_PIN1 8
#define MOTOR_A_PIN2 9

//Sensor
int TRIGGER_PIN = 10;
int ECHO_PIN = 11;
int MAX_DISTANCE= 200;
long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_A_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_A_PIN1, OUTPUT);
  pinMode(MOTOR_A_PIN2, OUTPUT);
  pinMode(MOTOR_B_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_B_PIN1, OUTPUT);
  pinMode(MOTOR_B_PIN2, OUTPUT);

  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0)
  {
    Serial.println("Connected");
     Serial.println("Before switch");
    character = Serial.read();
    switch(character)
    {
      case 'l': //Left
        left();
        Serial.println("Left");
        break;
      
      case 'r': //Right
       right();
        break;
      
      case 'f': //Forward
        forward();
        break;
        
      case 'b': //Backwards
       backward();
        break;
   
      case 'e': //Left forward
        leftForward();
        break;
        
      case 'g': //Right forward
        rightForward();
        break;
        
      case 'a': //Left backwards
        leftBackward();
        break;
        
      case 'c': //Right backwards
       rightBackward();
       break;
     case 's':
       stop();
       break;

    } 
  }
  Serial.println("After switch/serial");
  delay(250);
  getDistance();
  if(distance < 4)
  {
    stop();  
  }
}
void getDistance(){
  digitalWrite(TRIGGER_PIN,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);

  duration=pulseIn(ECHO_PIN,HIGH);
  distance=(duration/2) / 29.1;
  Serial.println(String(distance));

  delay(100);
}

void autoDrive()
{
    getDistance();
    if(distance < 5)
    {
      stop();
      if(random(0,1) == 0)
      {
        left();
        delay(300);
      }else 
      {
        right();
        delay(300);
      }
      
    } 
    forward(); 
}

void stop()
{
  analogWrite(MOTOR_B_SPEED_PIN, 0);  
  analogWrite(MOTOR_A_SPEED_PIN, 0); 
}
void forward(){
  setForwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 255);  
  analogWrite(MOTOR_A_SPEED_PIN, 255); 
}
void backward(){
  setBackwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 255);  
  analogWrite(MOTOR_A_SPEED_PIN, 255); 
}

void left(){
  analogWrite(MOTOR_B_SPEED_PIN, 10);  
  analogWrite(MOTOR_A_SPEED_PIN, 255); 
}

void right(){
  analogWrite(MOTOR_B_SPEED_PIN, 255);  
  analogWrite(MOTOR_A_SPEED_PIN, 10); 
}

void leftForward(){
  
  setForwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 150);  
  analogWrite(MOTOR_A_SPEED_PIN, 255); 
  
}
void rightForward(){
  
  setForwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 255);  
  analogWrite(MOTOR_A_SPEED_PIN, 150); 
}
void leftBackward(){
  
  setBackwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 150);  
  analogWrite(MOTOR_A_SPEED_PIN, 255); 
  
}
void rightBackward(){
  
  setBackwardDirection();
  analogWrite(MOTOR_B_SPEED_PIN, 255);  
  analogWrite(MOTOR_A_SPEED_PIN, 150); 
}
void setForwardDirection()
{
  //Set motor direction
  digitalWrite(MOTOR_B_PIN1, HIGH);
  digitalWrite(MOTOR_B_PIN2, LOW);
  
  //Set motor direction
  digitalWrite(MOTOR_A_PIN1, HIGH);
  digitalWrite(MOTOR_A_PIN2, LOW);
  
}
void setBackwardDirection()
{
    //Set motor direction
  digitalWrite(MOTOR_B_PIN1, LOW);
  digitalWrite(MOTOR_B_PIN2, HIGH);
  
  //Set motor direction
  digitalWrite(MOTOR_A_PIN1, LOW);
  digitalWrite(MOTOR_A_PIN2, HIGH);
  
}

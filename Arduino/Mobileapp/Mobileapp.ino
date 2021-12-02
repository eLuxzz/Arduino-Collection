//Motor setup
#define MOTOR_A_SPEED_PIN 3
#define MOTOR_B_SPEED_PIN 5
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

//Testa led med bluetooth
int led3 = 2;
int ledFlag3 = 0;
int led13 = 13;
int ledFlag13 = 0;
char character;

void setup() {
  // put your setup code here, to run once:
  //Motor
  pinMode(MOTOR_A_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_A_PIN1, OUTPUT);
  pinMode(MOTOR_A_PIN2, OUTPUT);
  pinMode(MOTOR_B_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_B_PIN1, OUTPUT);
  pinMode(MOTOR_B_PIN2, OUTPUT);

  //Sensor
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  
  pinMode(led3, OUTPUT);  
  pinMode(led13, OUTPUT);  
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0)
  {
    Serial.println("Connected");
    character = Serial.read();
    switch(character)
    {
      case '3':
        if(ledFlag3 == 0)
        {
            digitalWrite(led3, HIGH);
            Serial.println("Led 3: ON");
            ledFlag3 = 1;
        }
        else if(ledFlag3 == 1)
          {
            digitalWrite(led3, LOW);
            Serial.println("Led 3: OFF");
            ledFlag3 = 0;
          }
        break;
      case 'c':
        if(ledFlag13 == 0)
        {
            digitalWrite(led13, HIGH);
            Serial.println("Led 3: ON");
            ledFlag13 = 1;
        }
        else if(ledFlag13 == 1)
          {
            digitalWrite(led13, LOW);
            Serial.println("Led 3: OFF");
            ledFlag13 = 0;
          }
        break;
    } 
    delay(50);   
  }
}

//Motor
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

//Sensor
void getDistance(){
  digitalWrite(TRIGGER_PIN,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);

  duration=pulseIn(ECHO_PIN,HIGH);
  distance=(duration/2) / 29.1;
  Serial.print("The distance is ");
  Serial.println(String(distance));

  delay(100);
}

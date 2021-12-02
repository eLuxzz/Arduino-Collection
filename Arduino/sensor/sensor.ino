int TRIGGER_PIN = 10;
int ECHO_PIN = 11;
int MAX_DISTANCE= 200;
long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  delay(100);
}
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
void loop() {

  getDistance();


}

int led3 = 2;
int ledFlag3 = 0;
int led13 = 13;
int ledFlag13 = 0;
char character;

void setup() {
  // put your setup code here, to run once:
  pinMode(led3, OUTPUT);  
  pinMode(led13, OUTPUT);  
  Serial.begin(9600);
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

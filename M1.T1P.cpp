int Pin_Of_Sensor = 2;
int Pin_Of_LED = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(Pin_Of_Sensor, INPUT);
  pinMode(Pin_Of_LED, OUTPUT);
  digitalWrite(Pin_Of_LED,LOW);
  digitalWrite(Pin_Of_Sensor,LOW);
  delay(1000);
}

void loop()
{
  if(digitalRead(Pin_Of_Sensor) == HIGH){
      digitalWrite(Pin_Of_LED, HIGH);
      Serial.println("High motion detected");
      delay(1000);
  } else {
    digitalWrite(Pin_Of_LED, LOW);
    Serial.println("Low motion detected");
    delay(1000);
  }
  delay(1000);
}
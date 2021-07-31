int Pin_Of_Sensor = 2;
int Pin_Of_LED = 3;

# use for the PIR Sensor
void setup()
{
  Serial.begin(9600);
  pinMode(Pin_Of_LED, OUTPUT);  
  pinMode(Pin_Of_Sensor, INPUT);
  digitalWrite(Pin_Of_Sensor, LOW);
  digitalWrite(Pin_Of_LED, LOW);
  attachInterrupt(digitalPinToInterrupt(Pin_Of_Sensor), Motion_Detection, CHANGE);
}

void loop()
{
  digitalWrite(Pin_Of_LED, LOW);
}

void Motion_Detection()
{
 Serial.println("High Motion detected");
 digitalWrite(Pin_Of_LED, HIGH);
 delay(1000);
}
int pin_of_Motion_sensor_1 = 2;
int pin_of_Motion_sensor_2 = 3;
int pin_of_LED_1 = 4;
int pin_of_LED_2 = 5;

void setup(){
  Serial.begin(9600);
  pinMode(pin_of_Motion_sensor_1, INPUT);
  pinMode(pin_of_Motion_sensor_2, INPUT);
  pinMode(pin_of_LED_1, OUTPUT);
  pinMode(pin_of_LED_2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin_of_Motion_sensor_1), Motion_detetction_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pin_of_Motion_sensor_2), Motion_detetction_2, CHANGE);
}

void loop()
{
  digitalWrite(pin_of_LED_1, LOW);
  delay(1000);
  digitalWrite(pin_of_LED_2, LOW);
  delay(1000);
}

void Motion_detetction_1()
{
  Serial.println("Motion_1 detected");
  digitalWrite(pin_of_LED_1, HIGH);
}
void Motion_detetction_2()
{
  Serial.println("Motion_2 detected");
  digitalWrite(pin_of_LED_2, HIGH);
}
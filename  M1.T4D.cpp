const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

int Pin_Of_LED_1 = 4; // D4 for the first led
int Pin_Of_LED_2 = 5; // D5 for the second led
int Pin_Of_LED_3 = 6; // D6 for the third led
int Pin_Of_LED_4 = 7; // d7 for fourth led

int Pin_Of_PIR_SENSOR_1 = 13; // D13 for the first PIR sensor
int Pin_Of_PIR_SENSOR_2 = 12; // D12 for the second PIR sensor
int Pin_Of_PIR_SENSOR_3 = 11; // D11 for the third PIR sensor
int Pin_Of_PIR_SENSOR_4 = 10; // D10 for the fourth PIR sensor

int First_State = LOW;
int Second_State = LOW;
int Third_State = LOW;
int Fourth_State = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(Pin_Of_LED_1,OUTPUT); // set the outputs
  pinMode(Pin_Of_LED_2,OUTPUT);
  pinMode(Pin_Of_LED_3,OUTPUT);
  pinMode(Pin_Of_LED_4,OUTPUT);
  // referrence: https://www.youtube.com/watch?v=2kr5A350H7E
  // Enable the group 0: D10 to D12
  PCICR |= B00000001;
  PCMSK0 |= B00111100; 
  // set the CTC mode
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  // set to the prescaler of 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  // Reset Timer1 and set compare set
  TCNT1= t1_load;
  OCR1A= t1_comp;
  // Enable Timer1 compare interrupt
  TIMSK1 = (1 << OCIE1A);
  // Enable global interrupts
  sei();
}

void loop()
{
  delay(3000);
}

ISR(PCINT0_vect)
{
  First_State = digitalRead(Pin_Of_PIR_SENSOR_1);
  Second_State = digitalRead(Pin_Of_PIR_SENSOR_2);
  Third_State = digitalRead(Pin_Of_PIR_SENSOR_3);
  Fourth_State = digitalRead(Pin_Of_PIR_SENSOR_4);
} 

void timer_trigger()
{
  if(First_State == HIGH)
  {
    Serial.println("The first PIR sensor was detected!");
    digitalWrite(Pin_Of_LED_1, HIGH);
  }
  digitalWrite(Pin_Of_LED_1, LOW);
  if(Second_State == HIGH)
  {
    Serial.println("The second PIR sensor was detected!");
    digitalWrite(Pin_Of_LED_2, HIGH);
  }
  digitalWrite(Pin_Of_LED_2, LOW);
  if(Third_State == HIGH)
  {
    Serial.println("The third PIR sensor was detected!");
    digitalWrite(Pin_Of_LED_3, HIGH);
  }
  digitalWrite(Pin_Of_LED_3, LOW);
  if(Fourth_State == HIGH)
  {
    Serial.println("The fourth PIR sensor was detected!");
    digitalWrite(Pin_Of_LED_4, HIGH);
  }
  digitalWrite(Pin_Of_LED_4, LOW);
}

ISR(TIMER1_COMPA_vect)
{
  timer_trigger();
}
   


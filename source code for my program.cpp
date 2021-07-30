int Light;
void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  Light = analogRead(A0);
  if(Light > 150){
    digitalWrite(13, HIGH);
    Serial.println("High Lightness");
  }else{
    digitalWrite(13, LOW);
    Serial.println("Low Lightness");
  }
  delay(1000);
}
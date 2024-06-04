
void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(analogRead(A0));
  delay(300);
  if(analogRead(A0)>900){
    digitalWrite(2, 1);
  }
  else
    digitalWrite(2, 0);
}

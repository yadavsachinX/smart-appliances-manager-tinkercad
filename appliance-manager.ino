const int voltagePin = A0;
const int relayPin = 7;
const int fanPin = 4;
const int acPin = 5;
const int heaterPin = 6;
const int buzzerPin = 2;
const int minThreshold = 100;
const int maxThreshold = 900;

void blinkRelayLedslow(){
  digitalWrite(relayPin, HIGH);
  delay(900);
  digitalWrite(relayPin, LOW);
  delay(900);
}

void blinkRelayLedsfast(){
  digitalWrite(relayPin, HIGH);
  delay(100);
  digitalWrite(relayPin, LOW);
  delay(100);
}


void setup(){
  pinMode(relayPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);
  pinMode(acPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  int sensorValue = analogRead(voltagePin);
  Serial.print("Voltage Level: ");
  Serial.println(sensorValue);

  if (sensorValue >= minThreshold && sensorValue <= maxThreshold) {
   digitalWrite(relayPin, HIGH);
   digitalWrite(heaterPin, HIGH);
   digitalWrite(acPin, HIGH);
   digitalWrite(fanPin, HIGH);
   digitalWrite(buzzerPin, LOW);
   Serial.println("Voltage Normal - All Loads ON");
  } else if (sensorValue < 100 && sensorValue > 60) {
   digitalWrite(relayPin, HIGH); 
   digitalWrite(heaterPin, LOW);
   digitalWrite(acPin, HIGH);
   digitalWrite(fanPin, HIGH);
   digitalWrite(buzzerPin, LOW);
   Serial.println("Low Voltage - Heater OFF");
  } else if (sensorValue < 60) {
    blinkRelayLedslow();
    digitalWrite(heaterPin, LOW);
    digitalWrite(acPin, LOW);
    digitalWrite(fanPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Voltage Too Low - All Appliances OFF");
  } else if (sensorValue > maxThreshold) {
   blinkRelayLedsfast();    
   digitalWrite(heaterPin, LOW);
   digitalWrite(acPin, LOW);
   digitalWrite(fanPin, LOW);
   digitalWrite(buzzerPin, HIGH);
   Serial.println("Overvoltage - All Appliances OFF");
  }

delay(400);

}
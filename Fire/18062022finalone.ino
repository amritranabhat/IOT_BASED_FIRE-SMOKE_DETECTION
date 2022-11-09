int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A0;
int sensorPin = A1;
int sensorThres = 500;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(sensorPin,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);

Serial.println("Flame Sensor");

int sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 100)

{

Serial.println("Fire Detected");

Serial.println("LED on");

digitalWrite(redLed,HIGH);
digitalWrite(greenLed,LOW);
tone(buzzer,1000,200);

}
else
{
digitalWrite(redLed,LOW);
digitalWrite(greenLed,HIGH);
noTone(buzzer);
}
delay(100);

}

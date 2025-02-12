const int PIRPin = 2;    
const int LEDPin = 12;   
volatile bool motionDetected = false; 

void motionISR() {
  motionDetected = true; 
}

void setup() {
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PIRPin), motionISR, RISING); 
}

void loop() {
  if (motionDetected) {
    digitalWrite(LEDPin, HIGH);
    Serial.println("Led on, Motion detected.");
    delay(500);  
    digitalWrite(LEDPin, LOW);
    Serial.println("Led off, No Motion");
    motionDetected = false; 
  }
}

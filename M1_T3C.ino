const int PIRPin = 2;      
const int TiltPin = 3;     
const int LEDPin = 12;     

volatile bool motionDetected = false;
volatile bool tiltDetected = false;

void motionISR() {
  motionDetected = true;
}

void tiltISR() {
  tiltDetected = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);
  pinMode(TiltPin, INPUT_PULLUP); 
  pinMode(LEDPin, OUTPUT);

  
  attachInterrupt(digitalPinToInterrupt(PIRPin), motionISR, RISING);
  attachInterrupt(digitalPinToInterrupt(TiltPin), tiltISR, FALLING);
}

void loop() {
  if (motionDetected) {
    digitalWrite(LEDPin, HIGH);
    Serial.println("LED ON: Motion Detected.");
    delay(500);
    digitalWrite(LEDPin, LOW);
    Serial.println("LED OFF: No Motion");
    motionDetected = false;
  }

  if (tiltDetected) {
    digitalWrite(LEDPin, HIGH);
    Serial.println("LED ON: Tilt Detected.");
    delay(500);
    digitalWrite(LEDPin, LOW);
    Serial.println("LED OFF: No Tilt");
    tiltDetected = false;
  }
}

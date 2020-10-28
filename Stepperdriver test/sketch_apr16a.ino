// Define stepper motor connections and steps per revolution:
#define dirPin 8
#define stepPin 9
#define stepsPerRevolution 200

float step_count = 0;
float count = 0;

const float mlRotate = 0.665;
const float desVolume = 1000.00;
float desRotate = (desVolume/mlRotate)*200;
float compair = 10000;
void setup() {
  Serial.begin (9600);
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.println ("Hello");
  Serial.println (desRotate);
}
void loop() {
  
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, LOW);
  if (step_count <= desRotate){
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
    step_count += 1;
  }
  else
    Serial.println ("done");

    if (step_count == compair) {
      //count +=1;
      Serial.println (step_count);
      //step_count = 0;
      compair += 10000;
    }

 
}

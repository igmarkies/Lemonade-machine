// Define stepper motor connections and steps per revolution:
#define enable 2
#define dirPin 3
#define stepPin 4
#define stepsPerRevolution 200

float step_count = 0;
float count = 0;

const float mlRotateS = 0.665;   //Sirup pump
const float mlRotateW = 1.0;       //Water pump
const float desVolume = 1000.00;
float mlSirup = desVolume/8;
float sirupRotate = (mlSirup/mlRotateS)*stepsPerRevolution;
float mlWater = desVolume - mlSirup;
float waterRotate = (mlWater/mlRotateW)*stepsPerRevolution;
float compair = 10000;
void setup() {
  Serial.begin (9600);
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.println ("Hello");
  Serial.println (sirupRotate);
}
void loop() {
  
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, LOW);
  if (step_count <= sirupRotate){
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

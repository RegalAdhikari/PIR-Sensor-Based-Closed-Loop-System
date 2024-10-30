// Define the PIR sensor pin
const int pirPin = 2;  // Connected to digital pin 2
const int motor1 = 4;
const int motor2 = 7;
const int led1 = 9;
const int led2 = 10;
int flag = 0;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set the PIR pin as input
  pinMode(pirPin, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Wait for the PIR sensor to calibrate (usually 30 seconds)
  Serial.println("PIR Sensor Initializing...");
  delay(30000);  // Wait for 30 seconds
  Serial.println("PIR Sensor Ready!");
}

void loop() {
  // Read the PIR sensor value
  int pirValue = digitalRead(pirPin);
  Serial.println(pirValue);
  if(pirValue == 1){
    Serial.println("Motion detected");
  }else{
    Serial.println("No Motion detected");
  }
  if(pirValue == 1 && flag == 0){
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(motor1, HIGH);
      digitalWrite(motor2, LOW);
      flag = 1;
      delay(100000000000);
  }

  if(pirValue != 1 && flag ==1){
      
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      flag = 0;
  }

  
}
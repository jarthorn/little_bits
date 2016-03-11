//littleBits dump truck that moves forward with a DC motor and tips with a servo motor
int button = A0;
int motor = 5;
int servo = 9;

// setup is run once on board start
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
}

int truckBedStart = 128;

//main application loop
void loop() {
  //reset servo to start position
  analogWrite(servo, truckBedStart);
  int buttonValue =  analogRead(button);//value from 0-1023
  if (buttonValue > 500) {
    //put code to drive the dump truck here
    drive(25);
    tip();
  }
}

//drive the truck forward by the given distance
void drive(int distance) {
  analogWrite(motor, 255);
  delay(distance*100);
  analogWrite(motor, 0);
}

//raise gate to dump truck contents
void tip() {
  //slowly raise the gate
  for (int i = truckBedStart; i > 0; i--) {
    analogWrite(servo, i);
    delay(10);
  }
  //wait for contents to pour out of truck
  delay(2000);
  //lower gate back to start position
  analogWrite(servo, truckBedStart);
  
}

void debug(int buttonValue, int motorSpeed) {
  Serial.print("Button: ");
  Serial.print(buttonValue);
  Serial.print(" Motor: ");
  Serial.println(motorSpeed);
}


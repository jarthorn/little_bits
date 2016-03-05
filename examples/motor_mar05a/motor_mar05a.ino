int button = A0;
int motor = 5;
int servo = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  //reset servo to start position
  analogWrite(servo, 128);
  // put your main code here, to run repeatedly:
  int buttonValue =  analogRead(button);
  if (buttonValue > 500) {
    drive(25);
    tip();
    drive(25);
  }
}

void drive(int distance) {
  analogWrite(motor, 255);
  delay(distance*100);
  analogWrite(motor, 0);
}

void tip() {
  for (int i = 128; i > 0; i--) {
    analogWrite(servo, i);
    delay(10);
  }
  delay(2000);
  analogWrite(servo, 128);
  
}

void debug(int buttonValue, int motorSpeed) {
  Serial.print("Button: ");
  Serial.print(buttonValue);
  Serial.print(" Motor: ");
  Serial.println(motorSpeed);
}


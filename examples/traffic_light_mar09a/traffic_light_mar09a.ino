int button = A0;
int green = 1;
int amber = 5;
int red = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(green, OUTPUT);
  pinMode(amber, OUTPUT);
  pinMode(red, OUTPUT);
}

//this loop runs forever after the device starts
void loop() {
  greenLight();
  //check if pedestrian crosswalk button is pressed
  int buttonValue =  analogRead(button);
  if (buttonValue > 500) {
    amberLight();
    delay(4000);//4 seconds
    redLight();
    delay(10000);//10 seconds
  }
  //now it will loop back to green light at the top
}

void greenLight() {
  digitalWrite(green, HIGH);
  digitalWrite(amber, LOW);
  digitalWrite(red, LOW);
}
void amberLight() {
    digitalWrite(amber, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
}
void redLight() {
    digitalWrite(red, HIGH);
    digitalWrite(amber, LOW);
    digitalWrite(green, LOW);
}


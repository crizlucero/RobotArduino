const int pinPot = 0;
const int pinMotorLa = 5;
const int pinMotorLb = 6;

const int pinMotorRa = 4;
const int pinMotorRb = 3;
void goForward(){
  digitalWrite(pinMotorLa, HIGH);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, HIGH);
  digitalWrite(pinMotorRb, LOW);
  delay(1000);
}

void goBack(){
  digitalWrite(pinMotorLb, HIGH);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorRb, HIGH);
  digitalWrite(pinMotorRa, LOW);
  delay(1000);
}

void Stop(){
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorRb, LOW);
  digitalWrite(pinMotorRa, LOW);
  delay(1500);
}

void turnRight(){
  digitalWrite(pinMotorLa, HIGH);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, LOW);
  digitalWrite(pinMotorRb, HIGH);
  delay(1000);
}
void turnLeft(){
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorLb, HIGH);
  digitalWrite(pinMotorRa, HIGH);
  digitalWrite(pinMotorRb, LOW);
  delay(1000);
}

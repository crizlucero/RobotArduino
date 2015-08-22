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
}

void goBack(){
  digitalWrite(pinMotorLb, HIGH);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorRb, HIGH);
  digitalWrite(pinMotorRa, LOW);
}

void Stop(){
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorRb, LOW);
  digitalWrite(pinMotorRa, LOW);
}

void turnRight(){
  digitalWrite(pinMotorLa, HIGH);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, LOW);
  digitalWrite(pinMotorRb, HIGH);
}
void turnLeft(){
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorLb, HIGH);
  digitalWrite(pinMotorRa, HIGH);
  digitalWrite(pinMotorRb, LOW);
}

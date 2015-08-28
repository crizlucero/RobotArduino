#include <VirtualWire.h>
#include <Wire.h>

//#include "Acelerometro.h"
#include "Motores.h"
#include "RF.h"

const byte ENVIO_PULSO = 11;
const byte RECIBIR_PULSO = 12;
//Sensor
const byte sensorPin = 7;

void setup() {
  Serial.begin(9600);
  //Sensor
  pinMode(sensorPin, INPUT);
  //Acelerometro
  /*  Wire.begin();
   Wire.beginTransmission(MPU);
   Wire.write(0x6B);
   Wire.write(0);
   Wire.endTransmission(true);*/
  //Motor
  pinMode(pinMotorLa, OUTPUT);
  pinMode(pinMotorLb, OUTPUT);
  pinMode(pinMotorRa, OUTPUT);
  pinMode(pinMotorRb, OUTPUT);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, LOW);
  digitalWrite(pinMotorRb, LOW);
  //RF recive
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(ENVIO_PULSO);
  vw_set_rx_pin(RECIBIR_PULSO);
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  //RFSender();
  RFReceiver();
  delay(4000);
  /*delay(5000);
  if (digitalRead(sensorPin) == 0) {
    goForward();
    delay(1000);
  }
  else{
    goBack();
    delay(1000);
    turnLeft();
    delay(1000);
  }
  Stop();*/
  //Acelerometro
  //Acelerometro();
}

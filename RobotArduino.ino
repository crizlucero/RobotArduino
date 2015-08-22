#include <VirtualWire.h>
#include <Wire.h>

#include "Acelerometro.h"
#include "Motores.h"
#include "RF.h"

const byte ENVIO_PULSO = 11;
const byte RECIBIR_PULSO = 12;
//Sensor
const byte sensorPin = 7;

void setup() {

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
  vw_set_rx_pin(RECIBIR_PULSO);
  vw_set_tx_pin(ENVIO_PULSO);
  //vw_set_ptt_pin(Rtransmit_en_pin);
  vw_setup(2000);   // Bits per sec

  vw_rx_start();       // Start the receiver PLL running*/

  Serial.begin(9600);
}

void loop() {
  //RFSender();
  //RFReceiver();
  
  if (digitalRead(sensorPin) == 0) {
    goForward();
  }
  else{
   // goBack();
    //delay(500);
    turnLeft();
  }
  //Acelerometro
  //Acelerometro();
}

int sensorLecture() {
  Serial.println(digitalRead(sensorPin));
  delay(500);
  return 0;//distance;
}





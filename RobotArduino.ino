#include <VirtualWire.h>
#include <Wire.h>

#include "Acelerometro.h"
#include "Motores.h"
//#include "RF.h"

//Sensor
const byte sensorPin = 7;

int latestVal = 0;
int maxVal = 0;
int minVal = 1024;

void setup() {

  //Sensor
  pinMode(sensorPin, INPUT);
  //Acelerometro
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  //Motor
  pinMode(pinMotorLa, OUTPUT);
  pinMode(pinMotorLb, OUTPUT);
  pinMode(pinMotorRa, OUTPUT);
  pinMode(pinMotorRb, OUTPUT);
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, LOW);
  digitalWrite(pinMotorRb, LOW);
  //RF sender
 /* vw_set_tx_pin(Stransmit_pin);
  vw_set_rx_pin(Sreceive_pin);
  vw_set_ptt_pin(Stransmit_en_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);   // Bits per sec
  //RF recive
  vw_set_tx_pin(Rtransmit_pin);
  vw_set_rx_pin(Rreceive_pin);
  vw_set_ptt_pin(Rtransmit_en_pin);
  vw_setup(2000);   // Bits per sec

  vw_rx_start();       // Start the receiver PLL running*/

  Serial.begin(9600);
}

void loop() {
  /*if (digitalRead(sensorPin) == 0) {
    goForward();
    }else{
    goBack();
    delay(1000);
    turnLeft();
    }*/
  //Acelerometro
  Acelerometro();
}

int sensorLecture() {
  //float volts = digitalRead(sensorPin) * 0.0048828125;
  //float distance = 65.495 * pow(volts, -1.1904);
  Serial.println(digitalRead(sensorPin));
  delay(500);
  return 0;//distance;
}



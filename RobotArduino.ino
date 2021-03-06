#include <VirtualWire.h>
#include <Wire.h>

const int transmit_pin = 12;
const int receive_pin = 11;

uint8_t comando[VW_MAX_MESSAGE_LEN];
uint8_t comandoLenght = VW_MAX_MESSAGE_LEN;

char ID = 'B';
char GID = 'B';

char OrientacionActual = 'N';


//Sensor
const byte sensorPin = 7;

//#include "Acelerometro.h"
#include "Motores.h"
//#include "RF.h"

void setup() {
  Serial.begin(9600);
  //Sensor
  Serial.println("Setup");
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
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  RFSender();
  RFReceiver();
  //  delay(2000);
  //Serial.println(digitalRead(sensorPin));
  if(digitalRead(sensorPin) == 0){
    goForward();
    //Stop();
  }
  else{
    goBack();
    turnLeft();
    Stop();
  }
  //Acelerometro
  //Acelerometro();
}

void RFReceiver() {
  //enviarPregunta();
  if (vw_wait_rx_max(5000)) {
    if (vw_get_message(comando, &comandoLenght))
    {
      Serial.println("Se recibio un mensaje");
      char IDRemitente = (char)comando[1];
      char Alrededor[8] = {
        (char)comando[3], (char)comando[4], (char)comando[5], (char)comando[6], (char)comando[7], (char)comando[8], (char)comando[9], (char)comando[10]                                    };
      char X = (char)comando[12];
      char Y = (char)comando[13];
      Serial.println((char)comando[0]);
      if ((char)comando[0] == 'U') {
        if ((char)comando[2] == ID) {
          switch ((char)comando[11]) {
          case 'N':
            switch (OrientacionActual) {
            case 'N':
              if ((char)comando[4] != 1) {
                if ((char)comando[4] == 0) {
                  if (digitalRead(sensorPin) == 0) {
                    goForward();
                  }
                  else {
                    goBack();
                    turnLeft();
                  }
                }
                else {
                  goForward();
                }
              }
              else if ((char)comando[3] == 2) {
                // gira izquierda
                turnLeft();
                // avanza
                goForward();
              }
              else {
                //gira derecha
                turnRight();
                //avanza
                goForward();
              }
              break;
            case 'S':
              turnLeft();
              turnLeft();
              break;
            case 'E':
              turnLeft();
              break;
            case 'O':
              turnRight();
              break;
            }

            break;
          case 'S':
            switch (OrientacionActual) {
            case 'S':
              if ((char)comando[9] != 1) {
                if ((char)comando[9] == 0) {
                  if (digitalRead(sensorPin) == 0) {
                    goForward();
                  }
                  else {
                    goBack();
                    turnLeft();
                  }
                }
                else {
                  goForward();
                }
              }
              else if ((char)comando[10] == 2) {
                // gira izquierda
                turnLeft();
                // avanza
                goForward();
              }
              else {
                //gira derecha
                turnRight();
                //avanza
                goForward();
              }
              break;
            case 'N':
              turnLeft();
              turnLeft();
              break;
            case 'O':
              turnLeft();
              break;
            case 'E':
              turnRight();
              break;
            }
            break;
          case 'E':
            switch (OrientacionActual) {
            case 'E':
              if ((char)comando[6] != 1) {
                if ((char)comando[6] == 0) {
                  if (digitalRead(sensorPin) == 0) {
                    goForward();
                  }
                  else {
                    goBack();
                    turnLeft();
                  }
                }
                else {
                  goForward();
                }
              }
              else if ((char)comando[10] == 2) {
                // gira izquierda
                turnLeft();
                // avanza
                goForward();
              }
              else {
                //gira derecha
                turnRight();
                //avanza
                goForward();
              }
              break;
            case 'O':
              turnLeft();
              turnLeft();
              break;
            case 'S':
              turnLeft();
              break;
            case 'N':
              turnRight();
              break;
            }
            break;
          case 'O':
            switch (OrientacionActual) {
            case 'O':
              if ((char)comando[7] != 1) {
                if ((char)comando[7] == 0) {
                  if (digitalRead(sensorPin) == 0) {
                    goForward();
                  }
                  else {
                    goBack();
                    turnLeft();
                  }
                }
                else {
                  goForward();
                }
              }
              else if ((char)comando[5] == 2) {
                // gira izquierda
                turnLeft();
                // avanza
                goForward();
              }
              else {
                //gira derecha
                turnRight();
                //avanza
                goForward();
              }
              break;
            case 'E':
              turnLeft();
              turnLeft();
              break;
            case 'N':
              turnLeft();
              break;
            case 'S':
              turnRight();
              break;
            }
            break;
          }
          OrientacionActual = (char)comando[4];
          Serial.println("Instruccion para mi");
          //            avanzar = true;
        }
      }
      if ((char)comando[0] == 'B') {
        Serial.println("Instruccion para todos");
        //        avanzar = true;
      }

      else {
        Serial.println("Mensaje dañado");
      }

    }
    else{
      Serial.println("Mensaje no descifrado");
    }
  }
  else {
    Serial.println("Expiro el tiempo de espera, hay que reintentar");
  }


}

void RFSender() {
  char msg[7] = {
    'h', 'e', 'l', 'l', 'o', ' ', '#'
  };

  //  msg[6] = count;
  //digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
}




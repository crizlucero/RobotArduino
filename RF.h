char ID = 'B';
char GID = 'B';

byte comando[VW_MAX_MESSAGE_LEN];
byte comandoLenght = VW_MAX_MESSAGE_LEN;

void RFSender() {
  char msg[7] = {
    'h', 'e', 'l', 'l', 'o', ' ', '#'    };

  //  msg[6] = count;
  //digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
}


void RFReceiver() {
    //enviarPregunta();
    if(vw_wait_rx_max(2000)){


      if (vw_get_message(comando, &comandoLenght))
      {
        Serial.println("Se recibio un mensaje");
        char tipoMensaje = (char)comando[0];
        Serial.println(tipoMensaje);
        if(tipoMensaje == 'U'){
          if(comando[2] == ID){
            Serial.println("Instruccion para mi");
//            avanzar = true;
          }
        }
        if(tipoMensaje == 'B'){
          Serial.println("Instruccion para todos");
  //        avanzar = true;
        }
      }
      else{
        Serial.println("Mensaje dañado");
      }

    }
    else{
      Serial.println("Expiro el tiempo de espera, hay que reintentar");
    }

}



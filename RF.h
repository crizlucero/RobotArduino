//Transmit
const int Sled_pin = 11;
const int Stransmit_pin = 12;
const int Sreceive_pin = 2;
const int Stransmit_en_pin = 3;

//Receive
const int Rled_pin = 6;
const int Rtransmit_pin = 12;
const int Rreceive_pin = 11;
const int Rtransmit_en_pin = 3;

void RFSender() {
  char msg[7] = {'h', 'e', 'l', 'l', 'o', ' ', '#'};

  msg[6] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(1000);
  count = count + 1;
}
void RFReceiver() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;

    digitalWrite(led_pin, HIGH); // Flash a light to show received good message
    // Message with a good checksum received, print it.
    Serial.print("Got: ");

    for (i = 0; i < buflen; i++)
    {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
    }
    Serial.println();
    digitalWrite(led_pin, LOW);
  }
}

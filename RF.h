void RFSender() {
  char msg[7] = {
    'h', 'e', 'l', 'l', 'o', ' ', '#'  };

  //  msg[6] = count;
  //digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
  //digitalWrite(led_pin, LOW);
  //count = count + 1;
}


void RFReceiver() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if(vw_wait_rx_max(5000)){
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      int i;

      //digitalWrite(led_pin, HIGH); // Flash a light to show received good message
      // Message with a good checksum received, print it.
      Serial.print("Got: ");

      for (i = 0; i < buflen; i++)
      {
        Serial.print(buf[i], HEX);
        Serial.print(' ');
      }
      Serial.println();
      // digitalWrite(led_pin, LOW);
    }
  }
  else{
    Serial.println("Valio");
  }
}


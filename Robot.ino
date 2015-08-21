#include <VirtualWire.h>

char *controller;

const int pinPot = 0;
const int pinMotorLa = 5;
const int pinMotorLb = 6;

const int pinMotorRa = 4;
const int pinMotorRb = 3;

const byte sensorPin = 7;

int latestVal=0;
int maxVal=0;
int minVal=1024;

void setup() {
  Serial.begin(9600);
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
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(8);
  vw_setup(4000);// speed of data transfer Kbps
  //RF recive
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(9);
  vw_setup(4000);  // Bits per sec
  vw_rx_start();       // Start the receiver PLL running
}

void loop() {
  int sl = sensorLecture();
  //RFSender
  controller="1"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,HIGH);
  controller="0";
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,LOW);
  delay(2000);
  //RFReceiver
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    if(buf[0]=='1'){


      digitalWrite(13,1);
    }
    if(buf[0]=='0'){
      digitalWrite(13,0);
    }
  }
  //  Emisor();
  //Receptor();
}

/*void Emisor(){
 // First, stop listening so we can talk.
 radio.stopListening();

 // Take the time, and send it.  This will block until complete
 unsigned long time = millis();
 Serial.print("Enviando  ");
 Serial.println(time);
 bool ok = radio.write( &time, sizeof(unsigned long) );

 if (ok){
 Serial.println("ok...");
 }
 else{
 Serial.println("failed");
 }

 // Now, continue listening
 radio.startListening();
 // Wait here until we get a response, or timeout (250ms)
 unsigned long started_waiting_at = millis();
 bool timeout = false;
 while ( ! radio.available() && ! timeout ){
 if (millis() - started_waiting_at > 200 ){
 timeout = true;
 }
 }
 // Describe the results
 if ( timeout )
 {
 Serial.println("Failed, response timed out");
 }
 else
 {
 // Grab the response, compare, and send to debugging spew
 unsigned long got_time;
 radio.read( &got_time, sizeof(unsigned long) );

 // Spew it
 Serial.print("Respuesta = ");
 Serial.println(got_time);
 }

 // Try again 1s later
 delay(500);
 }

 void Receptor(){
 // if there is data ready
 if ( radio.available() )
 {
 // Dump the payloads until we've gotten everything
 unsigned long got_time;
 bool done = false;
 while (!done)
 {
 // Fetch the payload, and see if this was the last one.
 done = radio.read( &got_time, sizeof(unsigned long) );
 Serial.print("Dato Recibido =");
 Serial.println(got_time);
 // Delay just a little bit to let the other unit
 // make the transition to receiver
 delay(20);
 }

 // First, stop listening so we can talk
 radio.stopListening();

 // Send the final one back.
 radio.write( &got_time, sizeof(unsigned long) );
 Serial.println("Enviando Respuesta");

 // Now, resume listening so we catch the next packets.
 radio.startListening();
 }
 }*/

int sensorLecture(){
  float volts = analogRead(sensorPin)*0.0048828125;
  float distance = 65.495*pow(volts, -1.1904);
  delay(500);
  return distance;
}

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

void turnLeft(){
  digitalWrite(pinMotorLa, HIGH);
  digitalWrite(pinMotorLb, LOW);
  digitalWrite(pinMotorRa, LOW);
  digitalWrite(pinMotorRb, HIGH);
}
void turnRight(){
  digitalWrite(pinMotorLa, LOW);
  digitalWrite(pinMotorLb, HIGH);
  digitalWrite(pinMotorRa, HIGH);
  digitalWrite(pinMotorRb, LOW);
}















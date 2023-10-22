#include <SoftwareSerial.h>    // https://www.youtube.com/watch?v=5SmKOUHhmWk&ab_channel=BitwiseAr Video que me ayudó bastante
SoftwareSerial BT(10,11);      //Pines RX y TX del Arduino, TX del HC-05 se conecta al pin 10 y RX al pin 11 

void setup() {
 Serial.begin(9600);          //Se inicia el puerto serie
 Serial.println("Listo");
 BT.begin(38400);              //Se inicia el puerto serie BT
}

void loop() {
  if(BT.available()){         //Si llega un dato por el puerto BT se envia al monitor serial
    Serial.write(BT.read());
  }
  if(Serial.available()){     //Si llega un dato por el monitor serial se envia al puerto BT
    BT.write(Serial.read());
  }
}

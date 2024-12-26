#include <SoftwareSerial.h>

/* plug in apc220 at pin 8-GND with apc pcb pointing away from Arduino
*/

const int vrs = 101;
const int rxPin = 10;  //rx pin is tx pin on apc
const int txPin = 11;  //tx pin is rx pin on apc
const int setPin = 8;  //set pin
const int enPin = 12;  // no use
const int fiveV = 13;  // 5V to the APC220
int counter=0;


SoftwareSerial apc220(rxPin, txPin);  // Crt softserial port and bind tx/rx to appropriate PINS


void setupSoftAPC(void) {
  pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);
  pinMode(fiveV, OUTPUT);     // 5V
  digitalWrite(fiveV, HIGH);  // turn on 5V
  delay(50);
  pinMode(enPin, OUTPUT);     // ENABLE
  digitalWrite(enPin, HIGH);  //
  delay(100);
  apc220.begin(9600);
}

void setup() {
  Serial.begin(9600);
  Serial.print("APC version: ");
  Serial.println(vrs);
  Serial.println(__DATE__);
  setupSoftAPC();
}

void loop() {
  apc220.println("¡ALERTA! Vuestros datos son Vulnerables");
  delay(1000);  //espera 1 segundo después de cada envío a todos los receptores
  counter++;    //se incrementa en uno el contador de envíos
  Serial.print ("nº de envios:");
  Serial.println (counter);
}

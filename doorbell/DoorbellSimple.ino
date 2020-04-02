
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(A3, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(A0, LOW);
  digitalWrite(A3, HIGH);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello");

  mySwitch.enableReceive(0);
}

void loop() {
    if (mySwitch.available()) {
        int value = mySwitch.getReceivedValue();
        Serial.println(value);
    }

    mySwitch.resetAvailable();
}

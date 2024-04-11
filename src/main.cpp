#include <Arduino.h>
#include "SRF05.h"
int echo = 34;

SRF05 SRF1(33, echo);
SRF05 SRF2(35, echo);
SRF05 SRF3(37, echo);
SRF05 SRF4(39, echo);
void setup() {
  SRF1.setCorrectionFactor(1.035);
  SRF1.setModeAverage(10);

  SRF2.setCorrectionFactor(1.035);
  SRF2.setModeAverage(10);

  SRF3.setCorrectionFactor(1.035);
  SRF3.setModeAverage(10);

  SRF4.setCorrectionFactor(1.035);
  SRF4.setModeAverage(10);
  Serial.begin(9600);
}

void loop() {
  int x;
  int y;
  if(SRF1.getCentimeter() + SRF4.getCentimeter() > 172 && SRF1.getCentimeter() + SRF4.getCentimeter() < 192) {
    x = SRF1.getCentimeter();
  }
  if(SRF2.getCentimeter() + SRF3.getCentimeter() > 233 && SRF1.getCentimeter() + SRF4.getCentimeter() < 253) {
    y = SRF2.getCentimeter();
  }
  Serial.println("X: " + String(x) + "Y: " + String(y));
}

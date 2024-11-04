
#include "HC-SR04.h"
#include "Arduino.h"

#define SOUND_SPEED 0.034 // cm/uS

HC_SR04::HC_SR04(int triggerPin, int echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int HC_SR04::getDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);


    unsigned long duration = pulseIn(echoPin, HIGH);

    Serial.println(duration);
    return static_cast<int>(duration * SOUND_SPEED / 2);

}

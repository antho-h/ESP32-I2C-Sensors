#include <Arduino.h>
#include "Wire.h"
#include "HC-SR04.h"


#define I2C_DEV_ADDR 0x56

unsigned long lastSync = 0;

HC_SR04 sensors[4] = {
        HC_SR04(25, 26),
        HC_SR04(5, 17),
        HC_SR04(4, 16),
        HC_SR04(27, 14)
};

int i2c_data_array[4] = {0, 0, 0, 0}; // front, right, back, left




void onRequest(){
    Wire.write((uint8_t*)i2c_data_array, sizeof(i2c_data_array));
}

void syncDistances() {
    for (int i = 0; i < 4; i++) {
        i2c_data_array[i] = sensors[i].getDistance();
        Serial.printf("distances[%d]: %d\n", i, i2c_data_array[i]);
    }
    Serial.println();
}


void setup() {
    Wire.onRequest(onRequest);
    Wire.begin((uint8_t)I2C_DEV_ADDR);
    Serial.begin(115200);
}

void loop(){
    unsigned long currentMillis = millis();
    if (currentMillis - lastSync >= 100) {
        lastSync = currentMillis;
        syncDistances();
    }
    delay(1);

}


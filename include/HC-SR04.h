#ifndef ESP32_I2C_SENSORS_HC_SR04_H
#define ESP32_I2C_SENSORS_HC_SR04_H

class HC_SR04 {
public:
    HC_SR04(int triggerPin, int echoPin);
    int getDistance();
private:
    int triggerPin;
    int echoPin;
};

#endif //ESP32_I2C_SENSORS_HC_SR04_H

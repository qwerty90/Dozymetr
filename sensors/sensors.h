#ifndef SENSORS_H
#define SENSORS_H

#ifdef PC
    using namespace std;
    #include<iostream>
    #include <stdint.h>
    #include <cstring>
	#include <cstdio>
#include <assert.h>
#else
    #include "mbed.h"
#endif


enum sensorType_t {
    TEMP,
    HUM,
    PRESURE,
    DUST,
    ALTITU,
    YOUR_SENSOR_TYPE1,
    MAX_SENSORS
};


struct sensor
{
    static bool usedSensors[MAX_SENSORS];
    uint8_t sensorType;

    sensor(uint8_t _sensorType, float (*_getValue)(), void (*_init)() = dummyInit);

    sensor():sensorType(0),init(dummyInit),readValue(dummyGetVal),value(-99.9),valueText(){};

    float getValue(void);
    void getValueInText(char*text)const {memcpy(text,valueText,5);}

    void (*init)(void);

    ~sensor(){};

private:

    float (*readValue)(void);
    float value;
    char valueText[5];
    static void dummyInit(){};
    static float dummyGetVal(void){return -99.9;};

    sensor(const sensor & obj){*this = obj;};

};


#endif

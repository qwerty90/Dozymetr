/*
 * config.cpp
 *
 *  Created on: 11.01.2017
 *      Author: root
 */

#include "sensors/sensors.h"
#include "sensors/temperature/tempSensor.h"
#include "utils/utils.h"
#include "network/network.h"
#include "config.h"

sensor sensors[MAX_SENSORS];

void configureSensors(void)
{
    sensors[TEMP] = sensor(TEMP,getTemp,initTemp);
#ifdef PC
    sensors[HUM] = sensor(HUM,pctest::testWilg);

#endif
}


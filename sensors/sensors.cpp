#include "sensors.h"

bool  sensor::usedSensors[MAX_SENSORS] = {false};


float sensor::getValue(void)
{
    value = readValue();
    if (value > 40.0f)
        value = 40.0;
    else if(value <-30.0f)
        value = -30.0;

    value = float(int(value*10)/10.0);
    sprintf(valueText, "%f.1", value);
    return value;
}

sensor::sensor(uint8_t _sensorType,float (*_getValue)(), void (*_init)())
{
    sensorType = _sensorType;
    usedSensors[sensorType] = true;
    init=_init;
    readValue=_getValue;

    value = readValue();
    value = float(int(value*10)/10.0);
    sprintf(valueText, "%2.1f", value);
}

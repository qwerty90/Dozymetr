#include "tempSensor.h"

#ifndef PC
#include "DS1820.h"
#include "mbed.h"
DS1820 ds18b20(D11);
#endif

void initTemp()
{
#ifndef PC
    ds18b20.setResolution(12);
#endif
}
float getTemp()
{
    float tempora_temp;
#ifndef PC
    ds18b20.convertTemperature(true, DS1820::all_devices);
    tempora_temp = ds18b20.temperature();
#else
    tempora_temp = 12.34;
#endif
    return tempora_temp;
}

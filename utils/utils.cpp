/*
 * utils.cpp
 *
 *  Created on: 17.01.2017
 *      Author: root
 */
#include "../config.h"
#include "../sensors/sensors.h"

extern sensor sensors[MAX_SENSORS];

void initSensors()
{
    for (int i = 0; i< MAX_SENSORS; i++)
    {
        if(true == sensor::usedSensors[i])
            sensors[i].init();
    }
}
void getValues()
{
    for (int i = 0; i< MAX_SENSORS; i++)
    {
        if(true == sensor::usedSensors[i])
            sensors[i].getValue();
    }
}

void parseValues(char *link, const char * api_key)
{
    char buffer[80]="GET /update?key=";
    strcat(buffer,api_key);
    for (int i = 0; i< MAX_SENSORS; i++)
    {
        if(true == sensor::usedSensors[i])
        {
            strcat(buffer,"&field");
            const int buff_len = strlen(buffer);
            buffer[buff_len]=sensors[i].sensorType + '1';
            buffer[buff_len+1]='=';
            char text[6] ={0};
            sensors[i].getValueInText(text);

            strcat(buffer,text);
        }
    }
    strcat(buffer,"\r\n");
    strcpy(link,buffer);
}



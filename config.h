/*
 * config.h
 *
 *  Created on: 11.01.2017
 *      Author: root
 */

#ifndef SENSORS_CONFIG_H_
#define SENSORS_CONFIG_H_
#include "sensors/sensors.h"

#define SSID  					"KrwawySloik"
#define WIFI_PASSWORD  			"ogorkowaurna007"
#define API_KEY  				"OQ9SH7F2BSYNMO54"
#define MESURE_INTERWAL_MIN		10


#define MESURE_INTERWAL (MESURE_INTERWAL_MIN)*60
extern sensor sensors[MAX_SENSORS];
void configureSensors(void);

#endif /* SENSORS_CONFIG_H_ */

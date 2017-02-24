#ifndef NETWORK_H_
#define NETWORK_H_


#include "../sensors/sensors.h"

void connectNetwork(const char *ssid, const char * pass);
void sendDataToServer(const char *buffer);

#endif

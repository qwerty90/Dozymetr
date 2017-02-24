#include "ESP8266/ESP8266.h"
#include "network.h"


#ifndef PC
#include "mbed.h"
ESP8266 esp(A7, A2);
#else
#include <cstring>
using namespace std;
ESP8266 esp;
extern void wait (int t);
#endif

static void connectToServer();
static void closeConnection();

void connectNetwork(const char *ssid, const char * pass)
{
    esp.init(ssid,pass);
}

void sendDataToServer(const char *buffer)
{
    connectToServer();

    esp.sendData(buffer);
    wait(3);
    closeConnection();
}


void connectToServer()
{
    esp.connectToServer();
    wait(3);
}
void closeConnection()
{
    esp.closeConnection();
}

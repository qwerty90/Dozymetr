#include "sensors/sensors.h"
#include "network/network.h"
#include "utils/utils.h"
#include "config.h"

int main()
{
    configureSensors();

    initSensors();

    connectNetwork(SSID,WIFI_PASSWORD);

    while(1) 
    {
        getValues();

        char dataToSend[100]={0};
        parseValues(dataToSend, API_KEY);
        sendDataToServer(dataToSend);
        
        wait(MESURE_INTERWAL);

#ifdef PC
        static int i = 0;
        if(i++ > 1)
            return 0;
#endif

    }


}

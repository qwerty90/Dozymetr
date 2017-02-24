#ifndef ESP8266_H
#define ESP8266_H

#ifndef PC
#include "mbed.h"
#endif
class ESP8266
{
public:

#ifndef PC
  ESP8266(PinName tx, PinName rx, int br = 115200);
#endif
  ~ESP8266();
void init(const char * SSID,const char * PASSWORD);
void SendCMD(char * s);
void SendRaw(const char * s);
void Reset(void);
void RcvReply(char * r, int to);
void Join(const char * id, const  char * pwd);
void SetMode(char mode);
void SetMultiple(void);

void connectToServer(void) ;
void closeConnection(void);
void sendData(const char * buff) ;

private:
#ifndef PC
Serial comm;
#endif
void AddEOL(char * s);
void AddChar(char * s, const char c);
};
  
#endif

#include "ESP8266.h"

#ifndef PC

#include "mbed.h"


ESP8266::ESP8266(PinName tx, PinName rx, int br) :	comm(tx, rx,br) {

}
#else

#include <cstdio>
#include <cstring>
extern void wait(int i);

#endif

ESP8266::~ESP8266() { }

void ESP8266::AddEOL(char * s) {
    int k;
    k = strlen(s); // Finds position of NULL character
    s[k] = '\r'; // switch NULL for <CR>
    s[k + 1] = '\n'; // Add <LF>
    s[k + 2] = 0; // Add NULL at the end
}

void ESP8266::AddChar(char * s, const char c) {
    int k;
    k = strlen(s);
    s[k] = c;
    s[k + 1] = 0;
}
void ESP8266::SendRaw(const char * s)
{
#ifndef PC
    comm.puts(s);
#else
    printf("%s", s);
#endif
}

void ESP8266::SendCMD(char * s) {
    AddEOL(s);
    SendRaw(s);
}


void ESP8266::Reset(void) {
    const char *rs = "AT+RST\r\n";
    SendRaw(rs);
}

void ESP8266::RcvReply(char * r, int to) {
#ifndef PC
    Timer t;
    bool ended = false;
    char c;
    
    strcpy(r, "");
    t.start();
    while(!ended)
    {
        if(comm.readable())
        {
            c = comm.getc();
            AddChar(r, c);
            t.start();
        }
        if(t.read_ms() > to)
        {
                ended = true;
        }
    }
    AddChar(r, 0x00);
#endif
}

void ESP8266::Join(const char * id, const  char * pwd) {
    char cmd[150];
    strcpy(cmd, "AT+CWJAP=\"");
    strcat(cmd, id);
    strcat(cmd, "\",\"");
    strcat(cmd, pwd);
    AddChar(cmd, '\"');
    SendCMD(cmd);
}



//Defines wifi mode; Parameter: mode; 1= STA, 2= AP, 3=both
void ESP8266::SetMode(char mode) {
    char cmd[12];
    strcpy(cmd, "AT+CWMODE=");
    mode = mode + 0x30; // Converts number into corresponding ASCII character
    AddChar(cmd, mode); // Completes command string
    SendCMD(cmd);
}

void ESP8266::SetMultiple(void) {
    const char *rs = "AT+CIPMUX=1\r\n";
    SendRaw(rs);
}

void ESP8266::connectToServer(void) 
{
    const char *rs = "AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80\r\n";
    SendRaw(rs);
}
void ESP8266::closeConnection(void)
{
    const char *rs = "AT+CIPCLOSE\r\n";
    SendRaw(rs);
}


void ESP8266::sendData(const char * dataToSend)
{
    char buffer[100]={0};
    int len = strlen(dataToSend);
    sprintf (buffer, "AT+CIPSEND=4,%d", len);
    SendCMD(buffer);
    wait(1);

    SendRaw(dataToSend);
}

void ESP8266::init(const char * SSID,const char * PASSWORD)
{
    Reset();
    wait(2);
    SetMode(1);
    wait(2);
    Join(SSID,PASSWORD); 
    wait(8);
    SetMultiple();
    wait(2);
}

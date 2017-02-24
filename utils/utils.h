/*
 * utils.h
 *
 *  Created on: 17.01.2017
 *      Author: root
 */

#ifndef UTILS_H_
#define UTILS_H_

#ifdef PC
inline void wait(float i){}
inline void wait(int i){}

#endif
namespace pctest
{
    inline float testWilg(void){return 45.56;}
}
void initSensors();
void getValues();

void parseValues(char *link, const char * api_key);



#endif /* UTILS_H_ */

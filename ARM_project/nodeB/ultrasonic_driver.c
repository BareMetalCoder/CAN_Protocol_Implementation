///*  Ultrasonic Sensor Driver  */
//
//#include <LPC21xx.H>
//
//#include"can_header.h"
//
//
//#define TRIG (1<<5)				//---> connect trig to P0.5 
//
//#define ECHO ((IOPIN0>>6)&1)	//---> connect echo to P0.6
//
//
//float read_distance(void){
//
//	unsigned int p;
//
//	float dist;
//
//	
//
//	//VPBDIV=1;
//
//	IOSET0|=TRIG;
//
//	delay_us(10);
//
//	IOCLR0|=TRIG;
//
//		
//
//	T1PC=0;
//
//	//T1PR=15-1;
//
//	T1PR=60-1;
//
//	T1TC=0;
//
//
//	while(ECHO==0);
//
//
//	T1TCR=1;
//
//
//	while(ECHO){
//
//		if(T1TC>25000)
//
//			break;
//
//	}
//
//	T1TCR=0;
//
//	
//
//	//p=T1TC*1000;			//convert into microsecond
//
//	p=T1TC;
//
//	dist=((float)p*0.0343)/2;
//
//	//dist=(float)p/58;
//
//	return dist;
//
//}
//
//































#include<LPC21xx.h>
#include"can_header.h"

#define trigger (1<<5)
#define echo ((IOPIN0>>6)&1)
void ultrasonic_init()
{
	IODIR0|=trigger;
	IOCLR0|=trigger;
}
u32 ultrasonic_sensor()
{
	u32 echotime=0;
	float distance=0;
	
	IOSET0|=trigger;
	delay_us(10);
	IOCLR0|=trigger;
	
		while(echo==0);				 
			T1PC=0;
			T1PR=15-1;
			T1TC=0;
			T1TCR=1;
			while(echo)
			{
				if(T1TC>25000)
				break;
			}
			T1TCR=0;

			echotime=T1TC;

			distance=(0.0343*echotime)/2;
			return distance;
		}

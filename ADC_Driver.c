#include<lpc21xx.h>
#include"header.h"
#define DONE ((ADDR>>31)&1)
void adc_init(void)
{
	/*PINSEL setting*/
	PINSEL1|=0x4000000;//p0.29 -> AIN02
	/* ADC setting usings ADCR */
	ADCR=0x00200400;
}

u16 adc_read(u8 ch_num)
{
	u16 result=0;
	/* channel selection */
	ADCR|=(1<<ch_num);
	/* start ADC */
	ADCR|=(1<<24);
	/* moniter Done flag*/
	while(DONE==0);
	/*stop ADC*/
	ADCR^=(1<<24);
	 /*diselect ch_num*/
	ADCR^=(1<<ch_num);
	/*extract result */
	result=(ADDR>>6)&0x3ff;
	return result;
}

		

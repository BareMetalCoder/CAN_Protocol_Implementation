#include<lpc21xx.h>
#include<lpc21xx.h>
#define sw1 ((IOPIN0>>13)&1)
#define sw2 ((IOPIN0>>14)&1)
#define sw3 ((IOPIN0>>15)&1)
main()
{
	
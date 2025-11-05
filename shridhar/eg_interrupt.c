#include<lpc21xx.h> 
#include"header.h"
#define led (1<<17)
u32 cnt2; 
main()
{
	config_VIC_for_extern();
	en_extern_interrupt();
	while(1)
	{
		cnt2++;
	}
}

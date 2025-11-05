#include"header.h"
u32 main_cnt;
main()
{
uart0_init(9600);
config_VIC_for_uart0();
en_uart0_interrupt();
while(1)
{
	main_cnt++;   //default task of main
}
}

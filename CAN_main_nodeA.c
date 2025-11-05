#include"header.h"
CAN1 V1;
main()
{
	can1_init();
	V1.id=0x123;
	V1.rtr=0;               //data freme
	V1.dlc=8;
	V1.byteA=0x44332211;
	V1.byteB=0x88776655;
	can1_tx(V1);           //send dataframe
}

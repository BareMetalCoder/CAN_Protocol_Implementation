#include<lpc21xx.h>
#include"header.h"

void i2c_init(void)
{
	PINSEL0|=0x50;
	I2SCLH=I2SCLL=75;   //100 kbps
	I2CONSET=(1<<6);	//enable i2c peripheral
}

//--------I2c byte write frame--------------

#define SI ((I2CONSET>>3)&1)
void i2c_byte_write_frame(u8 sa,u8 mr,u8 data)
{
	/* generate start condition*/
	I2CONSET=(1<<5);  //STA=1
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	I2CONCLR=(1<<5);  //STA=0
	if(I2STAT!=0x8)
	{	
		uart0_tx_string("error start end\r\n");
		goto exit;
	}
	/*send sa+w & check ACK*/
	I2DAT=sa;  //sa+w
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	if(I2STAT==0x20)
	{
		uart0_tx_string("error :as+w\r\n");
		goto exit;
	}
	/*send m/r addr & check ack*/
	I2DAT=mr;  //sa
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	if(I2STAT==0x30)
	{
		uart0_tx_string("error:m/r addr \r\n");
		goto exit;
	}
	/*send data & ceck ack*/
	I2DAT=data;  //data
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	if(I2STAT!=0x30)
	{
		uart0_tx_string("error:data:\r\n");
		goto exit;
	}
	/*generate stop condition */
	exit:
		I2CONSET=(1<<4);   //STO=1
		I2CONCLR=(1<<3);   //clr SI
}

//---------I2C read frame---------------------

u8 i2c_byte_read_frame(u8 sa,u8 mr)
{
	/* generate start condition*/
	u8 temp;
	I2CONSET=(1<<5);  //STA=1
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	I2CONCLR=(1<<5);  //STA=0
	if(I2STAT!=0x8)
	{	
		uart0_tx_string("error start condition\r\n");
		goto exit;
	}
	/*send sa+w & check ack*/
	I2DAT=sa;   //sa+w
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	if(I2STAT==0x20)
	{
		uart0_tx_string("error sa+w\r\n");
		goto exit;
	}
	/*send m/r addr & check acl*/
	I2DAT=mr;  //m/r addr
	I2CONCLR=(1<<3);   //clr SI
	while(SI==0);
	if(I2STAT==0x30)
	{
		uart0_tx_string("error:m/r addr\r\n");
		goto exit;
	}
	/*generate restart condition */
	I2CONSET=(1<<5);  //STA=1
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	I2CONCLR=(1<<5);
	if(I2STAT!=0x10)
	{
		uart0_tx_string("Error restart condition\r\n");
		goto exit;
	}
	/*send sa+r & check ack */
	I2DAT=sa|1;  //SA+R
	I2CONCLR=(1<<3);  //clr SI
	while(SI==0);
	if(I2STAT==0x48)
	{
		uart0_tx_string("error sa+r\r\n");
		goto exit;
	}
	/*read data from the slave & generate NACK*/
	I2CONCLR=(1<<3);  //clr SI 
	while(SI==0);
	temp=I2DAT;  //collect rxd data
	 
	 /*generate stop condition */
	 exit:
	 I2CONSET=(1<<4);  // STo=1;
	 I2CONCLR=(1<<3);  //clr SI
	 return temp;
}

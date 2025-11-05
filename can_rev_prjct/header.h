#include<lpc21xx.h>
typedef unsigned int u32;
typedef  int s32;
typedef unsigned char u8;
typedef char s8;
typedef struct CAN_msg {
u32 id;
u32 byteA;
u32 byteB;
u8 rtr;
u8 dlc;
} CAN1;
void CAN1_init(void);
void CAN1_tx(CAN1 v);
void CAN1_rx(CAN1 *);
void lcd_data(u8);
void lcd_cmd(u8);
void lcd_init(void);
void lcd_string( s8 *);
void delay_sec(u32);
void delay_ms(u32);
u32 adc_read(u8);
void adc_init(void);
void can2_intr(void);
void en_sw_intr(void);
 u32 ultrasonic(void);
 void integer(unsigned int);









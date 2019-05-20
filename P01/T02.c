#include "stdhead.h"
#include "reg52.h"
#include "i2c.h"
uc  code se[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	                                     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0};
typedef unsigned char u8;
typedef unsigned int u32;

void delay1(ui i)
{
	while(i--);
}
void main()
{
	char t;
	bit flag=0;
	t=At24c02Read(0xa0);
	if(t>=9) t=0;   
		t=t+1;
	 if(t>=5) flag=1;
	At24c02Write(0xa0,t);
	we(0);
	while(1)
	{        
		   if(flag)
		   {
		   P0=se[t];
		delay1(10000);
		    P0=0;
		delay1(10000);
		   }
		   else P0=se[t];
		 
	}
	
	
}
//void delay(u8 t)
//{       u8 i;
//	while(t--)
//	{
//		for( i=0;i<150;i++)  ;
//		
//	}
//}
//u8 keynum;
//void keyscan()
//{
//	P1=0x0f;
//	if(P1!=0x0f)
//	{
//		switch(P1>>4)
//		{
//			case 1:keynum=1;
//		}		
//	}
//	
//}
//void turn(u8 t)
//{
//	F=1;
//	delay(t);
//	F=0;
//	delay(t);
//}
//void main()
//{       u8 j=15;
//	u32 time=0 ;
//	while(1)
//	{
//	turn(j);
//	
//		
//	}
//		
//}

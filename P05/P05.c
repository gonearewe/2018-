 #include "reg52.h"
 #include "stdhead.h"
uc  code se[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	                                     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0};
ui time=0,times=0,p=1;
//uc set1=100,set2=100,set3=100,set4==100;
bit dir1,dir2,dir3,dir4;					     
typedef unsigned char u8;
typedef unsigned int u32;
uc flag=0,time4=0;
 void delay1(ui i)
{
	while(i--);
}
void err()                               //error
{
	  SBUF='e';
	while(!TI);
	TI=0;
	   SBUF='r';
	while(!TI);
	TI=0;
	  SBUF='r';
	while(!TI);
	TI=0;
	  SBUF='o';
	while(!TI);
	TI=0;
	  SBUF='r';

}

int f()                                                //uart pros
{
	ui y;
	uc degree=0;
	 while(RI==0) ;
	 
		y=SBUF;
		 RI=0;
		 if(y=='s')
		 {
//			while(RI==0);
//				y=SBUF;
//			 RI=0;
//			 switch(y)
//			 {
//				 case '1':  
//				case '2':
//				case '3':
//				case '4':
//				default:err();
//			 }
			 while(RI==0);
			y=SBUF;
			 RI=0;
			 if(y=='d')
			 {
				while(RI==0);
				y=SBUF;
				RI=0;
				 degree=100*(y-'0');
				while(RI==0);
				y=SBUF;
				RI=0;
				 degree=10*(y-'0')+degree;
				 while(RI==0);
				y=SBUF;
				RI=0;
				 degree=y-'0'+degree;
				 if(degree>180) err();
				 else return degree;
			 }
			 else err();
		 }
		 else err();
}
	
void main()
{
	uart();
	while(1)
	display(3,f());
	
}
	
//void pwm() interrupt 3
//{
//	  TH0=(65536-1000*200)/256;
//	TL0=(65536-1000*200)%256;
//	 time4++; times++;
//	if(time4>set1)
//		dir1=1;
//	else dir1=0;
//	if(time4>set2)
//		dir2=1;
//	else dir2=0;
//	if(time4>set3)
//		dir3=1;
//	else dir3=0;
//	if(time4>set4)
//		dir4=1;
//	else dir4=0;
//	if(time4==100) time4=0;
//	if(times%100)  set1--,set2--;,set3--;,set4--;;
//	if(set1<=5) set1=5;
//	if(set2<=5) set2=5;
//	if(set3<=5) set3=5;
//	if(set4<=5) set4=5;
//}	

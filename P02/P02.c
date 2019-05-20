#include "reg52.h"
 #include "stdhead.h"
uc  code se[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	                                     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0};
ui time=0,times=0,p=1;
ui set=100;
bit dir;					     
typedef unsigned char u8;
typedef unsigned int u32;
uc flag=0,time4=0;
 void delay1(ui i)
{
	while(i--);
}
int f(int i)
{
   int n=0;
	
	while(8-i>0) n=pow(2,i)+n,i++;
	return n;
	
}
void f1()
{
	u8 l=8,h=16,cnt=1,u=0;
   ET0=0;	
   P2=0xff ;
	while(1)
	{  	
		
		while(l!=(cnt>>1))
		{
			switch(cnt)
			{
				
				case 2:u=0x81;
				case 4:u=0xc3;
				case 8:u=0xe7;
				
			}
		P2=~(l|h|u);
		
		delay1(300000);
		l>>=1;
		h<<=1;
		}
		cnt<<=1;
		l=8;
		h=16;
	}
	while(1)
	{
		while(l!=(cnt>>1))
		{
			switch(cnt)
			{
				
				case 2:u=0x81;
				case 4:u=0xc3;
				case 8:u=0xe7;
				
			}
		P2=l|h|u;
		
		delay1(300000);
		l>>=1;
		h<<=1;
		}
		cnt<<=1;
		l=8;
		h=16;
	}
		
	
}
void f2()
{
	
	  timer0(200);
	
}
void f3()
{
	  int i,j,aw;
	
	for(j=8;i>=0;j--)
	{
      if(j==0) break;
	    for(i=0;i<j;i++)
	   {
		aw=f(j)+pow(2,i);
		aw=~aw;
		 P2=aw;
		delay1(1e4);
			
	   }

	 }
	
	 
    for(j=8;i>=0;j--)
	{
      if(j==0) break;
	    for(i=0;i<j;i++)
	   {
		aw=f(j)+pow(2,i);
		 P2=aw;
		delay1(1e4);
			
	   }

	 }
//{       uc t=0,cnt=7,l=1,j=0xff;
//	  bit f3flag=1,z=0;
//	ET0=0;
//	while(1)
//	{       if(z==0) 
//		if(f3flag)P2=~((l<<t ) | j) ;
//		else  P2=(l<<t ) | j ;
//		t++;
//		delay1(1000);
//		if(t>cnt)   
//		{			
//			t=0;
//			j<<=cnt;
//			cnt--;
//			if(cnt==0)
//				f3flag=0;
//		}
//	}
}	
//void f4()
//{
//	ET0=0;
//	timer1(200);
//	uc t=1,z=0;
//	bit flag;
//	while(key()==-1);
//	z=keynum;
//	 P2=t<<keynum;
//	keynum=-1;
//	while(key()==-1);
//	if(keynum==8)  flag=1;
//	else flag=0;
//	
//	 z=0;
//}	
	

void main()
{      
	//k1=1;
//	k2=1;
//	k3=1;
//	k4=1;
	while(1)
	{

		E:;
		if(k1==0)
		{   delay1(1000);
			if(k1==0)
				flag=1;
		}
		else if(k2==0)
		{   delay1(1000);
			if(k2==0)
				flag=2;
		}
		else if(k3==0)
		{   delay1(1000);
			if(k3==0)
				flag=3;
		}
		else if(k4==0)
		{   delay1(1000);
			if(k4==0)
				flag=4;
		}
		
		if(flag!=0)
		{
		switch(flag)
		{
			case 1:f1(); break;
			case 2:f2();  break;
			case 3:f3();  break;
			case 4:f4();  break;
			
		}
		flag=0;
		delay1(10000);
		}
	}
}
void f2int() interrupt 1
{       time++;
        TH0=(65536-1000*200)/256;
	TL0=(65536-1000*200)%256;
	if(time%50==0)  p=p<<1;
	P2=~p;
	delay1(1000);
	 P2=0xff;
	delay1(2000);
	
}	

void pwm() interrupt 3
{
	  TH0=(65536-1000*200)/256;
	TL0=(65536-1000*200)%256;
	 time4++; times++;
	if(time4>set)
		dir=1;
	else dir=0;
	if(time4==100) time4=0;
	if(times%100)  set--;
	if(set<=5) set=5;
}	
	
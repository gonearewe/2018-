
 #include "stdhead.h"
 typedef unsigned char u8;
  typedef unsigned short u16;
typedef unsigned int u32;
sbit IRIN=P3^2;
u8 table[5]={0};
u8 IrValue[6];
u8 Time;
u16 num=0;
bit flag=0;

void delay1(ui t) 
{
	  while(t--);
}
 void IrInit()
{
	IT0=1;
	EX0=1;
	EA=1;	

	IRIN=1;
}
int  dat(ui t)
 {
	 switch(t)
	 {       case   242:return -2;
		 case   243:return 1;
		 case   231:return 2;
		 case   233:return 2;
		 case  161:return 3;
		 case  58:return 5;
		 case  165:return 6;
		 case 189:return 7;
		 case 173:return 8;
		 case 181:return 9;
		 case 247:return 4;
		 case   230:return -1;
		 
	 }
 }

 void main()
 {
	 timer0(200);
	 IrInit();
	while(IrValue[2]!=-2)
	{
	if(flag)
	{       
		if(dat(IrValue[2])==-1) t=t/10;
		 else
			num=num*10+dat(IrValue[2]);
	}
	}
 void ReadIr() interrupt 0
{
	u8 j,k;
	u16 err;
	Time=0;					 
	delay1(700);	
	if(IRIN==0)		
	{	 
		 flag=1;
		err=1000;				
		/*������������Ϊ����ѭ���������һ������Ϊ�ٵ�ʱ������ѭ������ó�������ʱ
		�������������*/	
		while((IRIN==0)&&(err>0))	//�ȴ�ǰ��9ms�ĵ͵�ƽ��ȥ  		
		{			
			delay1(1);
			err--;
		} 
		if(IRIN==1)			//�����ȷ�ȵ�9ms�͵�ƽ
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //�ȴ�4.5ms����ʼ�ߵ�ƽ��ȥ
			{
				delay1(1);
				err--;
			}
			for(k=0;k<4;k++)		//����4������
			{				
				for(j=0;j<8;j++)	//����һ������
				{

					err=60;		
					while((IRIN==0)&&(err>0))//�ȴ��ź�ǰ���560us�͵�ƽ��ȥ
					{
						delay1(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //����ߵ�ƽ��ʱ�䳤�ȡ�
					{
						delay1(10);	 //0.1ms
						Time++;
						err--;
						if(Time>30)
						{
							return;
						}
					}
					IrValue[k]>>=1;	 //k��ʾ�ڼ�������
					if(Time>=8)			//����ߵ�ƽ���ִ���565us����ô��1
					{
						IrValue[k]|=0x80;
					}
					Time=0;		//����ʱ��Ҫ���¸�ֵ							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}
void exit() interrupt 1
{
	  display(3,num);
}
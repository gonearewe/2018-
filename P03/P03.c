#include "reg52.h"
 #include "stdhead.h"
 uc y=0,dat,t=0;
void f()
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
void main()
{
	
	  uart();
	  while(RI==0) ;
		
		y=SBUF;
	RI=0;
	   if( y==0xa0)
	   {
		   while(RI==0) ;
		   
		    y=SBUF;
		   RI=0;
		   t=y;
		   switch(y)
		   { 	case 1:P2=0xfe;break;
			   case 2:P2=0xfd;break;
			   case 3:P2=0xfb;break;
			   default :f();goto E;
		   }
		   while(RI==0) ;
		   
		    y=SBUF;
		   RI=0;
		   t=y+t;
		   while(y--)
		   {
			   while(RI==0);
			   
				   dat=SBUF;
				  RI=0;
				SBUF=dat;
				   
				   while(!TI);
			   
		   }
		    while(RI==0) ;
		    y=SBUF;
		   RI=0;
		   if(y!=t)   f();goto E;
		     while(RI==0) ;
		    y=SBUF;
		   RI=0;
		   if(y!=0xaa)   f();
		  
		   
			   
	   }
	   else {f();led7=0;}
	   
	    E:;
	while(1);	  
	
}
//a0 01 03 c1 c2 c3 04 aa	
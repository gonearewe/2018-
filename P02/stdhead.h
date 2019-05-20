#ifndef _STDHEAD_
#define _STDHEAD_
#include <reg52.h>
#include <math.h>
#include <intrins.h>
typedef unsigned int ui;
typedef unsigned char uc;
sbit k2=P3^0;
sbit k1=P3^1;
sbit k3=P3^2;
sbit k4=P3^3;
sbit led0=P2^0;
sbit led1=P2^1;
//sbit SDA=P2^0;
//sbit SCL=P2^1;
sbit led2=P2^2;
sbit led3=P2^3;
sbit led4=P2^4;
sbit led5=P2^5;
sbit led6=P2^6;
sbit led7=P2^7;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit beep=P1^5;

void we(char i);

void timer0(ui t);
void timer1(ui t);
void uart ();
void display(uc j,ui t);

int key();
#endif
					     
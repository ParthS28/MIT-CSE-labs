#include <LPC17xx.h>
unsigned int i,l,j,c=0;
int main(void)
{
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0X0;
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
			c--;
		//if 12bit GPIO2 set down counter
		else
			c++;
		//else up counter
		if(c==-1)
			c=0xFF;
		//go back to FF if -1
		LPC_GPIO0->FIOPIN=c<<4;
		if(c == 0X100)
			c=0X00;
		//go back to 0x00 once it crosses 0xFF
		for(l = 1; l < 100000 ; l++);
		//pause loop 
	}
}

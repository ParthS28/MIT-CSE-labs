#include<LPC17xx.h>
unsigned int i,j,c=0;
unsigned long LED = 0x00000010;
int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	while(1)
	{
		LPC_GPIO0->FIOPIN=c<<4;
		for(i=0;i<100000;i++);
		//pause loop
		c++;
		if(c == 0x100)
			c=0x00;
		//continous counter
		//goes to 0x00 once it crosses 0xFF
	}
}

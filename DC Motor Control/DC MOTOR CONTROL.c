/* Connections */
/* J8 -> ST-DC-CNTRL  */

#include <lpc17xx.h>   


void delay_ms(unsigned int ms)
{
   unsigned int i,j;

   for(i=0;i<ms;i++)
     for(j=0;j<20000;j++);

}

/* start the main program */
int main() 
{
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL4 = 0x000000;  //Configure the PORT2 Pins as GPIO;
    LPC_GPIO2->FIODIR = 0xffffffff;  //Configure the PORT2 pins as OUTPUT;

  while(1)
    {
				LPC_GPIO2->FIOSET = 0x50; 
			LPC_GPIO2->FIOCLR = 0x60;
		
      delay_ms(5000);

				LPC_GPIO2->FIOCLR = 0x50; 
				LPC_GPIO2->FIOSET = 0x60; 
	   
      delay_ms(5000);
			

    }
}

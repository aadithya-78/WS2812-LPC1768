#include "LPC17xx.h"
#include "stdutils.h"
#include "systick.h"
#include "ws2812b.h"

volatile uint32_t temp;

void _delay(uint32_t del);

void pllfeed()
{
LPC_SC->PLL0FEED=0x000000AA;
LPC_SC->PLL0FEED=0x00000055; 
} 
 
void setpll()
{
uint16_t n,m,d;
n=2;
m=25;
d=3;
LPC_SC->PLL0CON=0x00000001; pllfeed();
LPC_SC->PLL0CON=0x00000000; pllfeed();
LPC_SC->CLKSRCSEL =1;
LPC_SC->PLL0CFG=((n-1)<<16)|(m-1); pllfeed();
LPC_SC->PLL0CON=0x00000001; pllfeed();
LPC_SC->CCLKCFG=d-1;
while ((LPC_SC->PLL0STAT&0x04000000)==0);
LPC_SC->PLL0CON=0x00000003; pllfeed();
SystemCoreClockUpdate(); 
}



int main (void) 
{
SystemInit();
setpll();
LPC_SC->PCONP |= ( 1 << 15 ); 
LPC_GPIO3->FIODIR |= 1 << 26; 

SysTick_Init();
SysTick_Start();	
uint64_t start_time = SysTick_GetMsTime();
	
RGB_t leds[8] = {0};
	
WS2812B ws2812b = {
.leds = leds,
.num_leds = 8,
};	
	
leds[0].b = 255;
leds[1].g = 255;
leds[2].r = 255;
leds[3].b = 255;
leds[4].g = 255;
leds[5].g = 255;
leds[6].r = 255;
while(1)
{
if(SysTick_GetMsTime() - start_time >= 1000){
	 WS2812B_write(&ws2812b);

	start_time = SysTick_GetMsTime();
	
}

}

}

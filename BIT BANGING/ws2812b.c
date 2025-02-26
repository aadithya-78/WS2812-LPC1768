#include <LPC17xx.h>
#include "ws2812b.h"

static inline void send_zero(){
	LPC_GPIO3->FIOSET |= (1<<26);
	//420 ns
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	
	LPC_GPIO3->FIOCLR |= (1<<26);
	//800ns
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP(); 
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	

}

static inline void send_one(){
	LPC_GPIO3->FIOSET |= (1<<26);
	
		//800ns
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP(); 
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();
	
LPC_GPIO3->FIOCLR |= (1<<26);
	
	//420 ns
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();


}


void WS2812B_write(WS2812B* ws2812b){
	for(uint16_t i=0;i< ws2812b->num_leds; i++){
		RGB_t led = ws2812b->leds[i];
		
		for(uint8_t bit=0;bit<8;bit++){
			if(led.g & 0x80){
				send_one();
			} else {
				send_zero();
			}
		}
		
		for(uint8_t bit=0;bit<8;bit++){
			if(led.r & 0x80){
				send_one();
			} else {
				send_zero();
			}
		}
		
		for(uint8_t bit=0;bit<8;bit++){
			if(led.b & 0x80){
				send_one();
			} else {
				send_zero();
			}
		}
		
		
	}
	
//RET Code 
	for(uint16_t i=0; i<600; i++){
		__NOP();__NOP();
	}
	
	
	
}
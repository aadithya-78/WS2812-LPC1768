#ifndef INC_WS2812B_H
#define INC_WS2812B_H

#include <stdint.h>

typedef struct RGB_t{
uint8_t r;
uint8_t g;
uint8_t b;

} RGB_t;

typedef struct WS2812B_t{
RGB_t* leds;
uint8_t num_leds ;	
} WS2812B;


void WS2812B_write(WS2812B* ws2812b); // defining fucntion prototype

#endif
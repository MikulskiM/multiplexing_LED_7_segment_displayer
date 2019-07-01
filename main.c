/*
 * main.c
 *
 *  Created on: 30 cze 2019
 *      Author: Marek Mikulski
 *
 *	Ta wersja programu wyœwietla 1 na pierwszym wyœwietlaczy 7-segmentowym
 *
 *	po³¹czenia:			(anody wyœwietlaczy)
 *	PD7 -> dp			PC1 -> w1
 *	PD6 -> g			PC2 -> w2
 *	PD5 -> f			PC3 -> w3
 *	...					PC4 -> w4
 *	PD1 -> b			0 na wyjœciu w³¹cza dany displayer
 *	PD0 -> a
 *	0 na wyjœciu w³¹cza dany segment LED
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>			// we will use it in next versions

#include "seven_segment_display.h"	// we will use it in next versions

#define A_SEGMENT (1<<PD0)	// PD2 pin will be the 'c' segment in 7 segment LED display
#define B_SEGMENT (1<<PD1)	// PD1 pin will be the 'b' segment in 7 segment LED display
#define C_SEGMENT (1<<PD2)	// PD2 pin will be the 'c' segment in 7 segment LED display
#define D_SEGMENT (1<<PD3)	// PD2 pin will be the 'c' segment in 7 segment LED display
#define E_SEGMENT (1<<PD4)	// PD1 pin will be the 'b' segment in 7 segment LED display
#define F_SEGMENT (1<<PD5)	// PD2 pin will be the 'c' segment in 7 segment LED display
#define G_SEGMENT (1<<PD6)	// PD1 pin will be the 'b' segment in 7 segment LED display
#define DP_SEGMENT (1<<PD7)	// PD2 pin will be the 'c' segment in 7 segment LED display

#define W1 (1<<PC1)	// PC1 pin -> w1 (display's anode)
#define W2 (1<<PC2)	// PC2 pin -> w2 (display's anode)
#define W3 (1<<PC3)	// PC1 pin -> w1 (display's anode)
#define W4 (1<<PC4)	// PC2 pin -> w2 (display's anode)

int main(){

	DDRD |= A_SEGMENT | B_SEGMENT | C_SEGMENT | D_SEGMENT | E_SEGMENT | F_SEGMENT | G_SEGMENT | DP_SEGMENT;
	// ustawiam piny jako wyœcie
	// analogicznie mog³em zrobic DDRD = 0xFF czyli wszystkie bity tego portu jako jedynki
	DDRC |= W1 | W2 | W3 | W4;		// ustawiam piny jako wyœcie


//	PORTD = 0xFF;
//	PORTD &= ~B_SEGMENT;	// ustawiam stan niski na bit wyjœciowy 'B_SEGMENT'
//	PORTD &= ~C_SEGMENT;	// ustawiam stan niski na bit wyjœciowy 'C_SEGMENT'
//
//	PORTC &= ~W1;
//	PORTC |= W2;
//	PORTC |= W3;
//	PORTC |= W4;

//	uint8_t cy1 = 1;
//	uint8_t cy2 = 4;
//	uint8_t cy3 = 8;
//	uint8_t cy4 = 5;

	while(1){

		PORTD = 0xFF;
		PORTD &= ~(C_SEGMENT | B_SEGMENT);
		PORTC = 0xFF;
		PORTC &= ~W1;
		_delay_ms(2);

		PORTD = 0xFF;
		PORTD &= ~(C_SEGMENT | B_SEGMENT | G_SEGMENT | F_SEGMENT);
		PORTC = 0xFF;
		PORTC &= ~W2;
		_delay_ms(2);

		PORTD = 0x00;
		PORTD |= DP_SEGMENT;
		PORTC = 0xFF;
		PORTC &= ~W3;
		_delay_ms(2);

		PORTD = 0xFF;
		PORTD &= ~(C_SEGMENT | A_SEGMENT | G_SEGMENT | F_SEGMENT | D_SEGMENT);
		PORTC = 0xFF;
		PORTC &= ~W4;
		_delay_ms(2);

	}


	return 0;
}

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

	DDRD |= B_SEGMENT;	// ustawiam pin 'B_SEGMENT' jako wyœcie
	DDRD |= C_SEGMENT;  // ustawiam pin 'C_SEGMENT' jako wyœcie
	DDRD |= A_SEGMENT;	// ustawiam pin 'A_SEGMENT' jako wyœcie
	DDRD |= D_SEGMENT;  // ustawiam pin 'D_SEGMENT' jako wyœcie
	DDRD |= E_SEGMENT;	// ustawiam pin 'E_SEGMENT' jako wyœcie
	DDRD |= F_SEGMENT;  // ustawiam pin 'F_SEGMENT' jako wyœcie
	DDRD |= G_SEGMENT;	// ustawiam pin 'G_SEGMENT' jako wyœcie
	DDRD |= DP_SEGMENT;  // ustawiam pin 'DP_SEGMENT' jako wyœcie
	DDRC |= W1;		// ustawiam pin 'w1' jako wyœcie
	DDRC |= W2;		// ustawiam pin 'w2' jako wyœcie
	DDRC |= W3;		// ustawiam pin 'w3' jako wyœcie
	DDRC |= W4;		// ustawiam pin 'w4' jako wyœcie

	PORTD &= ~B_SEGMENT;	// ustawiam stan niski na bit wyjœciowy 'B_SEGMENT'
	PORTD &= ~C_SEGMENT;	// ustawiam stan niski na bit wyjœciowy 'C_SEGMENT'
	PORTD |= A_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'A_SEGMENT'
	PORTD |= D_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'D_SEGMENT'
	PORTD |= E_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'E_SEGMENT'
	PORTD |= F_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'F_SEGMENT'
	PORTD |= G_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'G_SEGMENT'
	PORTD |= DP_SEGMENT;	// ustawiam stan wysoki na bit wyjœciowy 'DP_SEGMENT'

	PORTC &= ~W1;
	PORTC |= W2;
	PORTC |= W3;
	PORTC |= W4;

	return 0;
}

/*
 * main.c
 *
 *  Created on: 30 cze 2019
 *      Author: Marek Mikulski
 *
 *	Ta wersja programu wy�wietla 1 na pierwszym wy�wietlaczy 7-segmentowym
 *
 *	po��czenia:			(anody wy�wietlaczy)
 *	PD7 -> dp			PC1 -> w1
 *	PD6 -> g			PC2 -> w2
 *	PD5 -> f			PC3 -> w3
 *	...					PC4 -> w4
 *	PD1 -> b			0 na wyj�ciu w��cza dany displayer
 *	PD0 -> a
 *	0 na wyj�ciu w��cza dany segment LED
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

	DDRD |= B_SEGMENT;	// ustawiam pin 'B_SEGMENT' jako wy�cie
	DDRD |= C_SEGMENT;  // ustawiam pin 'C_SEGMENT' jako wy�cie
	DDRD |= A_SEGMENT;	// ustawiam pin 'A_SEGMENT' jako wy�cie
	DDRD |= D_SEGMENT;  // ustawiam pin 'D_SEGMENT' jako wy�cie
	DDRD |= E_SEGMENT;	// ustawiam pin 'E_SEGMENT' jako wy�cie
	DDRD |= F_SEGMENT;  // ustawiam pin 'F_SEGMENT' jako wy�cie
	DDRD |= G_SEGMENT;	// ustawiam pin 'G_SEGMENT' jako wy�cie
	DDRD |= DP_SEGMENT;  // ustawiam pin 'DP_SEGMENT' jako wy�cie
	DDRC |= W1;		// ustawiam pin 'w1' jako wy�cie
	DDRC |= W2;		// ustawiam pin 'w2' jako wy�cie
	DDRC |= W3;		// ustawiam pin 'w3' jako wy�cie
	DDRC |= W4;		// ustawiam pin 'w4' jako wy�cie

	PORTD &= ~B_SEGMENT;	// ustawiam stan niski na bit wyj�ciowy 'B_SEGMENT'
	PORTD &= ~C_SEGMENT;	// ustawiam stan niski na bit wyj�ciowy 'C_SEGMENT'
	PORTD |= A_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'A_SEGMENT'
	PORTD |= D_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'D_SEGMENT'
	PORTD |= E_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'E_SEGMENT'
	PORTD |= F_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'F_SEGMENT'
	PORTD |= G_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'G_SEGMENT'
	PORTD |= DP_SEGMENT;	// ustawiam stan wysoki na bit wyj�ciowy 'DP_SEGMENT'

	PORTC &= ~W1;
	PORTC |= W2;
	PORTC |= W3;
	PORTC |= W4;

	return 0;
}

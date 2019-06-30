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
 *	PD1 -> b
 *	PD0 -> a
 */

#include <avr/io.h>
#include <avr/interrupt.h>			// we will use it in next versions

#include "seven_segment_display.h"	// we will use it in next versions

#define B_SEGMENT (1<<PD1)	// PD1 pin will be the 'b' segment in 7 segment LED display
#define C_SEGMENT (1<<PD2)	// PD2 pin will be the 'c' segment in 7 segment LED display
#define W1 (1<<PC1)	// PC1 pin -> w1 (display's anode)

int main(){

	DDRD |= B_SEGMENT;	// ustawiam pin 'B_SEGMENT' jako wy�cie
	DDRD |= C_SEGMENT;  // ustawiam pin 'C_SEGMENT' jako wy�cie
	DDRC |= W1;		// ustawiam pin 'w1' jako wy�cie

	PORTD &= ~B_SEGMENT;	// ustawiam stan niski na bit wyj�ciowy 'B_SEGMENT'
	PORTD &= ~C_SEGMENT;	// ustawiam stan niski na bit wyj�ciowy 'C_SEGMENT'

	return 0;
}

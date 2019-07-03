/*
 * main.c
 *
 *  Created on: 30 cze 2019
 *      Author: Marek Mikulski
 *
 *	Ta wersja programu wyœwietla 1485 na wyœwietlaczach 7-segmentowych
 *	 bardzo szybko prze³¹czaj¹c siê miêdzy nimi
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
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "MULTIPLEKS/multipleks.h"

int main(){


	multipleks_init();
//	SEGMENTY_PORT &= ~(SEG_A | SEG_DP | SEG_C);
//	ANODY_PORT &= ~(ANODA_1 | ANODA_2 | ANODA_3 | ANODA_4);

	sei();	// zezwolenie na przerwania

	cyfra[0] = 11;	// f
	cyfra[1] = 12;	// u
	cyfra[2] = 13;	// c
	cyfra[3] = 14;	// k
	_delay_ms(600);
	cyfra[0] = 4;	// y
	cyfra[1] = 0;	// o
	cyfra[2] = 12;	// u
	cyfra[3] = 10;	// null
	_delay_ms(600);

	uint16_t licznik = 1006;
	uint8_t z1, z2, z3, z4;

	while(licznik){				// and the bomb starts ticking
		z1 = licznik/1000;
		if(z1)
			cyfra[0] = z1;
		else
			cyfra[0] = 10;
		z2 = (licznik-(z1*1000))/100;
		if(z2)
			cyfra[1] = z2;
		else{
			if(licznik>999)
				cyfra[1] = 0;
			else
				cyfra[1] = 10;
		}
		z3 = (licznik-(z1*1000)-(z2*100))/10;
		if(z3)
			cyfra[2] = z3;
		else{
			if(licznik>99)
				cyfra[2] = 0;
			else
				cyfra[2] = 10;
		}
		z4 = (licznik-(z1*1000)-(z2*100)-(z3*10));
		cyfra[3] = z4;
		_delay_ms(50);

		licznik--;
	}
//	while(1){
//
//	}

	cyfra[0] = 10;	// f
	cyfra[1] = 10;	// u
	cyfra[2] = 10;	// c
	cyfra[3] = 10;	// k
	_delay_ms(400);

	cyfra[0] = 15;	// L
	cyfra[1] = 0;	// 0
	cyfra[2] = 15;	// L
	cyfra[3] = 10;	// null
	_delay_ms(600);

	cyfra[0] = 10;	// f
	cyfra[1] = 10;	// u
	cyfra[2] = 10;	// c
	cyfra[3] = 10;	// k
	_delay_ms(1000);

	return 0;
}

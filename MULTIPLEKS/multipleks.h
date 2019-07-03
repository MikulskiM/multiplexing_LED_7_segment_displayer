/*
 * multipleks.h
 *
 *  Created on: 3 lip 2019
 *      Author: Praca
 */

#ifndef MULTIPLEKS_MULTIPLEKS_H_
#define MULTIPLEKS_MULTIPLEKS_H_

#define SEGMENTY_PORT		PORTD
#define SEGMENTY_KIERUNEK	DDRD

#define ANODY_PORT		PORTB
#define ANODY_KIERUNEK	DDRB

#define ANODA_1	(1<<PB0)
#define ANODA_2 (1<<PB1)
#define ANODA_3 (1<<PB2)
#define ANODA_4 (1<<PB3)

#define MASKA_ANODY (ANODA_1 | ANODA_2 | ANODA_3 | ANODA_4)

#define SEG_A (1<<0)
#define SEG_B (1<<1)
#define SEG_C (1<<2)
#define SEG_D (1<<3)
#define SEG_E (1<<4)
#define SEG_F (1<<5)
#define SEG_G (1<<6)
#define SEG_DP (1<<7)

extern uint8_t cyfra[4];

void multipleks_init();

#endif /* MULTIPLEKS_MULTIPLEKS_H_ */

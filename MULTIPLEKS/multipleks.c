/*
 * multipleks.c
 *
 *  Created on: 3 lip 2019
 *      Author: Praca
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "multipleks.h"


const uint8_t cyfry[] PROGMEM = {
		~(SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F),	// 0
		~(SEG_B | SEG_C),									// 1
		~(SEG_A | SEG_B | SEG_D | SEG_E | SEG_G),			// 2
		~(SEG_A | SEG_B | SEG_C | SEG_D | SEG_G),			// 3
		~(SEG_F | SEG_B | SEG_C | SEG_G),					// 4
		~(SEG_A | SEG_G | SEG_C | SEG_D | SEG_F),			// 5
		~(SEG_A | SEG_G | SEG_C | SEG_D | SEG_E | SEG_F),	// 6
		~(SEG_A | SEG_B | SEG_C | SEG_F),					// 7
		~(SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G),	// 8
		~(SEG_A | SEG_B | SEG_C | SEG_D | SEG_G | SEG_F),	// 9
		0xFF,												// pusty znak
		~(SEG_A | SEG_E | SEG_F | SEG_G),					// F
		~(SEG_B | SEG_C | SEG_D | SEG_E | SEG_F),			// U
		~(SEG_A | SEG_D | SEG_E | SEG_F),					// C
		~(SEG_B | SEG_C | SEG_E | SEG_F | SEG_G),			// K
		~(SEG_D | SEG_E | SEG_F)							// L
};

void multipleks_init(){

	SEGMENTY_KIERUNEK = 0xFF; // ca�y port ustawiamy jako WYJ�CIE
	SEGMENTY_PORT = 0xFF;

	ANODY_KIERUNEK |= ANODA_1 | ANODA_2 | ANODA_3 | ANODA_4; // ustawiam piny anod jako WYJ�CIA
	ANODY_PORT |= ANODA_1 | ANODA_2 | ANODA_3 | ANODA_4;


	//	ustawienie timera
	TCCR2 |= (1<<WGM21);	// tryb CTC
	TCCR2 |= (1<<CS22) | (1<<CS21);	// preskaler 256
	OCR2 = 10;	// dodatkowe dzielenie przez 215, bo chcemy cz�stotliwo�c 200 Hz
	TIMSK |= (1<<OCIE2);	// zezwolenie na przerwanie od por�wnania

}

uint8_t cyfra[4]; // zmienna tablicowa kt�ra b�dzie trzyma�a cyfry kt�re chcemy zobaczyc na wy�wietlaczu

ISR(TIMER2_COMP_vect){	// obs�uga przerwania

	static uint8_t licznik;  // static = widoczna tylko w tej funkcji (b�dzie zmienia�a swoj� warto�c od 0 do 3
	ANODY_PORT = (ANODY_PORT | MASKA_ANODY); // wygaszenie wszystkich wy�wietlaczy (dzi�ki temu '|' wygasimy tylko 4 piny od anod, reszta portu bez zmian)

	SEGMENTY_PORT = pgm_read_byte(&cyfry[cyfra[licznik]]);

	ANODY_PORT = (ANODY_PORT & ~MASKA_ANODY) | (~(1<<licznik) & MASKA_ANODY);	// cykliczne prze��czanie wyswietlacza

	licznik++;
	if(licznik>3)
		licznik = 0;
}




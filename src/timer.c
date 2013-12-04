/*
 * timer.c
 *
 *  Created on: 25.11.2013
 *      Author: alexandermertens
 */


#include "timer.h"

#include <avr/interrupt.h>


//global Data
volatile bool timer_compare_reached;
volatile uint8_t timer_slot_counter;


/*
	Timer0 wird auf eine Periodenl�nge von T = 4 ms einstellt

	F_OC0 = 250

	OCR0    = ?

	F_OC0   =    (F_CPU) / (2 * Prescaler * (1 + OCR0))
	OCR0    =   ((F_CPU) / (2 * Prescaler * F_OC0)) - 1
	OCR0    =  (16000000 / (2 * 256 * 250)) - 1
	OCR0    =  124

	Vgl.:	Atmel-2490-8-bit-AVR-Microcontroller-ATmega64-L_datasheet.pdf
			Seite 125
*/
void timer_init()
{
	timer_compare_reached = false;
	timer_slot_counter = 0;


	/* Timer0 wird auf eine Periodenl�nge von T = 4 ms einstellt */

	//Timer0 Betriebsart festlegen - Timer/Counter Control Register:
	TCCR0 |= (1 << WGM01); 				// Mode 4 - CTC

	//Timer1 Prescaler festlegen
	TCCR0 |= (1 << CS02 | 1 << CS01);	//Prescaler = 256

	//Interruptverhalten definieren
	TIMSK |= (1 << OCIE0);				//OCIE1A: Timer/Counter0,
										//Output Compare Match Interrupt Enable

	//Timer0 OCR-Register vorladen
	OCR0 = 249;						//OCR0: Output Compare Register


}


ISR(TIMER0_COMP_vect)
{
	if(timer_slot_counter >= TIMER_SLOT_COUNTER_MAX) {
		timer_slot_counter = 0;
	} else {
		timer_slot_counter++;
	}
	timer_compare_reached = true;
}
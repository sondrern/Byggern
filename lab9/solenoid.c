#include <avr/io.h>
#include "solenoid.h"

#define solenoidPin PJ1

void solenoid_init(void){
	DDRJ |= (1<<solenoidPin);
}

void solenoid_on(void){
	PORTJ |= (1<<solenoidPin);
}

void solenoid_off(void)void solenoid_init(void){
	DDRJ |= (1<<solenoidPin);
}

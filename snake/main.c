#include "MKL05Z4.h"
#include "keyboard.h"
#include "NOKIA_LCD.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Klawiatura wg nastepujacych zasad: 
C4-PTA7, C3-PTA10, C2-PTA11, C1-PTA12,
R4-PTA5, R3-PTA6, R2-PTA9, R1-PTA8.
Piny PTA5-8 pracuja jako wejscia, z rezystorem podciagajacym.
Piny PTA9-12 pracuja jako wyjscia.
Wyswietlacz wg nastepujacych zasad:
RST-PTB1
CE-PTB2
DC-PTB8
DIN-PTB6
CLK-PTB7
VCC-3.3V
BL-3.3V
GND-GND*/



int main()
{
	setup();
	NOKIA_INIT();
	buttonsInitialize();
	
	set_clear();
	set_welcome_screen();
	display();
	delay_ms(2000);
	while(1) //cala gra
	{
		set_clear();
		set_init_screen();
		display();
		button_pushed=0;
		while(1) //menu startowe
		{
			timer+=1;
			if(timer>1000)
				timer=0;
			if(button_pushed)
			{
				button_pushed=0;
				break;
			}
		}
		set_clear();
		set_frame();
		display();
		delay_ms(500);
		init_snake();
		direction=right;
		score=0;
		food_eaten=1;
		button_pushed=0;
		while(1) //gra
		{
			timer+=1;
			if(timer>1000)
				timer=0;
			set_clear_without_frame();
			snake_pos();
			check_food();
			set_score();
			set_snake();
			check_snake();
			if(game_over)
			{
				game_over=0;
				display_inverse();
				delay_ms(2000);
				display_normal();
				set_game_over_screen();
				display();
				delay_ms(2000);
				if(score>high_score)
					high_score=score;
				clear_snake();
				break; //powrot do calej gry
			}
			food_pos_set();
			display();
			delay_ms(100);
			if(button_pushed)
			{
				if(button_pushed_nb==3){
					if(!(direction==down))
						direction=up;
				}
				if(button_pushed_nb==6){
					if(!(direction==right))
						direction=left;
				}
				if(button_pushed_nb==7){
					if(!(direction==up))
						direction=down;
				}
				if(button_pushed_nb==8){
					if(!(direction==left))
						direction=right;
				}
				button_pushed=0;
			}
		}
	}
}
	

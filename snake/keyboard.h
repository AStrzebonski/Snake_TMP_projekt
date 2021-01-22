#include "MKL05Z4.h"


#define C4_POS 7
#define C3_POS 10
#define C2_POS 11
#define C1_POS 12
#define R4_POS 5
#define R3_POS 6
#define R2_POS 9
#define R1_POS 8

void del_ms( int n) {
	volatile int i;
	volatile int j;
	for( i = 0 ; i < n; i++)
		for(j = 0; j < 3500; j++) {}
}

volatile uint8_t button_pushed_nb;
volatile uint8_t button_pushed;

void PORTA_IRQHandler(void){
	if(button_pushed==0)		//handshake
	{
		del_ms(5); //tlumienie drgan zestykow
		uint8_t counter=0;
		//set ones on rows
		PTA->PDOR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
		PTA->PDDR &= ~((1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rest rows as input
		PTA->PDOR &= ~(1<<R4_POS); //setting zero on row4
		for(volatile int i=0; i<5; i++){} //czekamy na ustalenie
		if(( PTA->PDIR & (1<<C4_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=1;
			counter++;
		}

		if(( PTA->PDIR & (1<<C3_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=2;
			counter++;
		}

		if(( PTA->PDIR & (1<<C2_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=3;
			counter++;
		}

		if(( PTA->PDIR & (1<<C1_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=4;
			counter++;
		}

		//setting ones
		PTA->PDOR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
		PTA->PDDR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rows as output
		PTA->PDDR &= ~((1<<R4_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rest rows as input
		PTA->PDOR &= ~(1<<R3_POS); //setting zero on row3
		for(volatile int i=0; i<5; i++){} //czekamy na ustalenie
		if(( PTA->PDIR & (1<<C4_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=5;
			counter++;
		}

		if(( PTA->PDIR & (1<<C3_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=6;
			counter++;
		}

		if(( PTA->PDIR & (1<<C2_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=7;
			counter++;
		}

		if(( PTA->PDIR & (1<<C1_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=8;
			counter++;
		}

		//setting ones
		PTA->PDOR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
		PTA->PDDR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rows as output
		PTA->PDDR &= ~((1<<R4_POS)|(1<<R3_POS)|(1<<R1_POS)); //set rest rows as input
		PTA->PDOR &= ~(1<<R2_POS); //setting zero on row2
		for(volatile int i=0; i<5; i++){} //czekamy na ustalenie
		if(( PTA->PDIR & (1<<C4_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=9;
			counter++;
		}

		if(( PTA->PDIR & (1<<C3_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=10;
			counter++;
		}

		if(( PTA->PDIR & (1<<C2_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=11;
			counter++;
		}

		if(( PTA->PDIR & (1<<C1_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=12;
			counter++;
		}

		//setting ones
		PTA->PDOR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
		PTA->PDDR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rows as output
		PTA->PDDR &= ~((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)); //set rest rows as input
		PTA->PDOR &= ~(1<<R1_POS); //setting zero on row1
		for(volatile int i=0; i<5; i++){} //czekamy na ustalenie
		if(( PTA->PDIR & (1<<C4_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=13;
			counter++;
		}

		if(( PTA->PDIR & (1<<C3_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=14;
			counter++;
		}

		if(( PTA->PDIR & (1<<C2_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=15;
			counter++;
		}

		if(( PTA->PDIR & (1<<C1_POS)) == 0)
		{
			button_pushed=1;
			button_pushed_nb=16;
			counter++;
		}
		if(counter>1)
			button_pushed=0;
	}
	//set 0 on rows
	PTA->PDOR &= ~((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
	PTA->PDDR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS)); //set rows as output
	//clear ISF flags
	PORTA->PCR[C4_POS] |= PORT_PCR_ISF_MASK;
	PORTA->PCR[C3_POS] |= PORT_PCR_ISF_MASK;
	PORTA->PCR[C2_POS] |= PORT_PCR_ISF_MASK;
	PORTA->PCR[C1_POS] |= PORT_PCR_ISF_MASK;
}



//funkcja inicjaizuje przyciski i wlacza przerwania
void buttonsInitialize(){
	SIM->SCGC5 |=  SIM_SCGC5_PORTA_MASK; 				/* Enable clock for port A */
	//set pins as GPIO
	PORTA->PCR[C4_POS] |= PORT_PCR_MUX(1);    
	PORTA->PCR[C3_POS] |= PORT_PCR_MUX(1);      
	PORTA->PCR[C2_POS] |= PORT_PCR_MUX(1); 
	PORTA->PCR[C1_POS] |= PORT_PCR_MUX(1);    
	PORTA->PCR[R4_POS] |= PORT_PCR_MUX(1);      
	PORTA->PCR[R3_POS] |= PORT_PCR_MUX(1);
	PORTA->PCR[R2_POS] |= PORT_PCR_MUX(1);    
	PORTA->PCR[R1_POS] |= PORT_PCR_MUX(1);      
	//set rows as output
	PTA->PDDR |= ((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
	//set 0 on rows
	PTA->PDOR &= ~((1<<R4_POS)|(1<<R3_POS)|(1<<R2_POS)|(1<<R1_POS));
	
	//set pull-up and activate falling-edge interrupts on columns
	PORTA->PCR[C4_POS] |=  PORT_PCR_PE_MASK |	PORT_PCR_PS_MASK;
	PORTA->PCR[C4_POS] |= 	PORT_PCR_IRQC(10);
	PORTA->PCR[C3_POS] |=  PORT_PCR_PE_MASK |	PORT_PCR_PS_MASK;
	PORTA->PCR[C3_POS] |= 	PORT_PCR_IRQC(10);
	PORTA->PCR[C2_POS] |=  PORT_PCR_PE_MASK |	PORT_PCR_PS_MASK;
	PORTA->PCR[C2_POS] |= 	PORT_PCR_IRQC(10);
	PORTA->PCR[C1_POS] |=  PORT_PCR_PE_MASK |	PORT_PCR_PS_MASK;
	PORTA->PCR[C1_POS] |= 	PORT_PCR_IRQC(10);
	/* ARM's Nested Vector Interrupt Controller configuration */
	NVIC_ClearPendingIRQ(PORTA_IRQn);				//Clear NVIC any pending interrupts on PORTA
	NVIC_EnableIRQ(PORTA_IRQn);							//Enable NVIC interrupts source for PORTA
	NVIC_SetPriority (PORTA_IRQn, 3);
}

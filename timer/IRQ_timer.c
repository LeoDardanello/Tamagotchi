/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../Lugia/Lugia.h"
#include "string.h"
#include "stdio.h"
#include "../Battery/Battery.h"
#include "../RIT/RIT.h"
#include "../Menu/Menu.h"
#include "../music/music.h"

#define Center_X  120
#define Center_Y 163


#define RIT_SEMIMINIMA 8
#define RIT_MINIMA 16
#define RIT_INTERA 32

#define UPTICKS 1

uint16_t SinTable[45] =                                       
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};

NOTE song[] = 
{ //1
	{c6,time_croma},
	{c6,time_croma},
  {d6b,time_semicroma},
	{c6,time_semicroma},
	{b5b,time_semicroma},
	{c6,time_croma},
	{g5,time_croma},
	{c6,time_croma},
	//2 
	{pause,time_croma},
	{c6,time_croma},
	{c6,time_croma},
  {d6b,time_semicroma},
	{c6,time_semicroma},
	{b5b,time_semicroma},
	{c6,time_croma},
	{g5,time_croma},
	{c6,time_croma},
	
};



NOTE song2[]={
	
	{e6,time_semibiscroma},
	{e6,time_semibiscroma},
	{e6,time_semibiscroma},
	{b6,time_semiminima}
	
};

NOTE song3[]={
	
		{f5,time_croma},
		{c5,time_croma},
		{c6,time_semicroma},
		{d6,time_semicroma},
		{c6,time_semicroma},
		{f6,time_croma}
};
	
NOTE song4[]={
	{c7,time_semicroma},
	{b6b,time_semicroma},
	{a6,time_semicroma},
	{g6,time_semicroma},
	{a6,time_semicroma},
	{g6,time_semicroma},
	{f6,time_croma},
  {f7,time_croma}
};

static int flag_display=0;
volatile int sec=0;
volatile int min=0;
volatile int hour=0;
volatile int cnt=0;
int extern sinistra;
int extern destra;
int extern alive;
int extern cuddled;
int extern isEating;
uint8_t	extern Volume;
void UpdateAge(void);

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER0_IRQHandler (void){//scatta ad ogni secondo
	
	disable_timer(0);
	reset_timer(0);

	if(IsAlive()==0){
	
					if(flag_display==0){
						DrawSprite(Lugia_Matrix_2);
						flag_display=1;}
					else{
						DrawSprite(Lugia_Matrix);
						flag_display=0;}
					
					UpdateAge();
						
						if(sec%5==0)
						{DecreaseSatietyBattery();
						DecreaseHappinessBattery();}
						
						
						if(cuddled==1){
							cnt++;
							if(cnt==2){
							cnt=0;
						  DespawnHeart();
							cuddled=0;
							}
							
						}
			

}	
	else {
		
		
		if(alive==0){
		LugiaDespawn();
		PokeballOnScreen();
		ResetButton();
		alive=1;
		init_timer(3,0x005B8D80);//50ms
		enable_timer(3);
		}
	
	}
		
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  enable_timer(0);
	return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/



void TIMER1_IRQHandler (void)
{	
	static int sineticks=0;
	/* DAC management */	
	static int currentValue; 
	currentValue = SinTable[sineticks];
	LPC_DAC->DACR = ((currentValue <<6)*Volume/100);
	sineticks++;
	if(sineticks==45) sineticks=0;

	
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
	
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER2_IRQHandler (void)
{
	disable_timer(1);
	
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Timer/Counter 3 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER3_IRQHandler(void){


if(cuddled!=0){
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song4[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song4) / sizeof(song4[0])))
	{
		disable_timer(3);
		currentNote=0;
	}
}
	
	if(sinistra!=0 || destra!=0 ){
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song2[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song2) / sizeof(song2[0])))
	{
		disable_timer(3);
		currentNote=0;
	}
}
	

if(alive!=0){
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song) / sizeof(song[0])))
	{
		disable_timer(3);
		currentNote=0;
	}
}
if(isEating!=0){
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song3[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song3) / sizeof(song3[0])))
	{
		disable_timer(3);
		currentNote=0;
		isEating=1;
	}
}

	LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}





void UpdateAge(){
	
	char sec_str[2]="";
	char min_str[2]="";
	char hour_str[2]="";
	char msg[13]="";
	
	if(sec<60){
	sec=sec+1;
	}
	if(sec==60){
		min=min+1;
		sec=0;
	}
	if(hour==60){
		hour=hour+1;
		min=0;
	}
	
	if(sec<10){
		sprintf(sec_str,"0%d",sec);
		}
	else {
		sprintf(sec_str,"%d",sec);
	}
	
	if(min<10){
		sprintf(min_str,"0%d",min);
		}
	else{
		sprintf(min_str,"%d",min);
	}
	
	if(hour<10){
		sprintf(hour_str,"0%d",hour);
		}
	else{
		sprintf(hour_str,"%d",hour);
	}
		sprintf(msg,"Age: %s:%s:%s",hour_str,min_str,sec_str);
		GUI_Text(Center_X-50,20,(uint8_t*)msg,Black,White);
}

/******************************************************************************
**                            End Of File
******************************************************************************/
/*
	static int clear = 0;
	char time_in_char[5] = "";
	
  if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
		if(display.y < 280){
			TP_DrawPoint(display.x,display.y);
			GUI_Text(200, 0, (uint8_t *) "     ", Blue, Blue);
			clear = 0;
		}
		else{			
			if(display.y <= 0x13E){			
				clear++;
				if(clear%20 == 0){
					sprintf(time_in_char,"%4d",clear/20);
					GUI_Text(200, 0, (uint8_t *) time_in_char, White, Blue);
					if(clear == 200){	 
						LCD_Clear(Blue);
						GUI_Text(0, 280, (uint8_t *) " touch here : 1 sec to clear ", Blue, White);			
						clear = 0;
					}
				}
			}
		}
		*/


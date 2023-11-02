/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../GLCD/GLCD.h"
#include "../Menu/Menu.h"
#include "../Lugia/Lugia.h"
#include "../Food/Food.h"
#include "../Battery/Battery.h"
#include "../timer/timer.h"
#include "../music/music.h"
#include "../adc/adc.h"
#include "../Volume/Volume.h"
//#include "../TouchPanel/TouchPanel.h"

volatile int destra=0;
volatile int sinistra=0;
volatile int alive=0;
volatile int cuddled;
volatile int isEating=0;
int extern sec;
int extern min;
int extern hour;
/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void RIT_IRQHandler (void)
{	int temp=0;		  
  disable_timer(0);		 
  ADC_start_conversion();            //prendo valore da potenziometro e scateno ADC_Handler
	
         if(IsAlive()==0){
					
					 
					 
            if(destra!=0 || sinistra!=0){
							if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){
								//GUI_Text(120-50,60,(uint8_t*)"OK",Black,White);
									
								
								if(sinistra!=0){
									destra=0;
									sinistra=0;
									cuddled=0;
									LPC_PINCON->PINSEL3 &= (0xFFFFFFFF); //disabilito selezione cibo fino a quando lugia mangia
									FriesOnScreen();
									LugiaShiftLeft();
									isEating=1;
									init_timer(3,0x005B8D80);//50ms
							    enable_timer(3);
									FriesOffScreen();
									LugiaShiftLeftReturn();
									IncreaseHappinessBattery();
									MenuReset();
									LPC_PINCON->PINSEL3 &= (0xF003FFFF);//riabilito selezione cibo
									LPC_GPIO1->FIODIR |= 0xC1FFFFFF;
								}
								
								if(destra!=0){
									destra=0;
									sinistra=0;
									cuddled=0;
									LPC_PINCON->PINSEL3 &= (0xFFFFFFFF);//disabilito selezione cibo fino a quando lugia mangia
									AppleOnScreen(); 
									LugiaShiftRight();
									isEating=1;
									init_timer(3,0x005B8D80);//50ms
							    enable_timer(3);
									AppleOffScreen();
									LugiaShiftRightReturn();
									IncreaseSatietyBattery();
									MenuReset();
									LPC_PINCON->PINSEL3 &= (0xF003FFFF);//riabilito selezione cibo
									LPC_GPIO1->FIODIR |= 0xC1FFFFFF;
							 }
						 }
					 }
						
						if((LPC_GPIO1->FIOPIN & (1<<28)) == 0)//joystick destra 
					{
							destra =1;
							sinistra =0;
						  init_timer(3,0x005B8D80);//50ms
							enable_timer(3);
							MenuSelectRight();
							
					}

						if((LPC_GPIO1->FIOPIN & (1<<27)) == 0)//joystick sinistro
					{
							sinistra =1;
							destra =0;
					   	init_timer(3,0x005B8D80);//50ms
							enable_timer(3);
							MenuSelectLeft();
						
					}
					
					if(LugiaCuddled()==1){
						cuddled=1;
						init_timer(3,0x005B8D80);//50ms
						enable_timer(3);
						DrawHeart();
						IncreaseHappinessBattery();
					}
		
}	
else{
  	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){//select per resettare
 				PokeballOffScreen();
				LugiaStartup();
				BatteryStartup();
				MenuReset();
			  //VolumeStartup();
				alive=0;
				sec=0;
				hour=0;
				min=0;
				GUI_Text(120-50,20,(uint8_t*)"Age: 00:00:00",Black,White);
		
	}
}

  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	enable_timer(0);
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

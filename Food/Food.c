
#include <stdio.h>
#include "LPC17xx.h"
#include "../GLCD/GLCD.h"
#include "Food.h"


#define Center_X  120
#define Center_Y 163


static uint8_t Patatine[15][15]={ {0,0,0,1,0,0,0,1,0,1,0,0,0,0,0},
																	{0,0,1,2,1,0,1,2,1,2,1,0,1,1,1},
																	{0,1,2,1,2,1,1,2,1,2,2,1,2,2,1},
																	{1,2,2,2,1,2,1,2,2,1,2,1,2,2,1},
																	{0,1,1,2,1,2,2,1,2,2,1,2,2,1,0},
																	{0,0,1,1,2,1,2,2,1,2,1,2,1,1,0},
																	{0,0,1,3,1,1,1,1,1,1,1,1,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,3,3,3,3,3,3,3,3,3,3,1,0},
																	{0,0,1,1,3,3,3,3,3,3,3,3,1,1,0},
																	{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0} };

																	
static uint8_t Mela[12][11]={{0,0,0,0,1,0,1,1,0,0,0},
															{0,0,0,1,2,1,3,3,1,0,0},
															{0,0,0,0,1,2,3,3,1,0,0},
															{0,0,1,1,1,2,1,1,1,0,0},
															{0,1,4,4,1,1,1,4,4,1,0},
															{1,4,4,4,4,4,4,4,0,0,1},
															{1,4,4,4,4,4,4,4,4,0,1},
															{1,4,4,4,4,4,4,4,4,4,1},
															{1,4,4,4,4,4,4,4,4,4,1},
															{0,1,4,4,4,4,4,4,4,1,0},
															{0,0,1,4,4,4,4,4,1,0,0},
															{0,0,0,1,1,1,1,1,0,0,0}};
																	
void DrawFries(uint8_t Patatine[15][15]){
	
	int i,j=0;
	int dim=2;
	int start_X=Center_X-(20*dim)-80;
	int start_Y=Center_Y-(16*dim)+50;
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
		if(Patatine[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Patatine[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Patatine[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Yellow);
		if(Patatine[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);
		
										 }
									 }
	return;
}							

void FriesOnScreen(void){
	DrawFries(Patatine);
	return;
}

void DrawApple(uint8_t Mela[12][11]){
	
	int i,j=0;
	int dim=2;
	int start_X=Center_X-(15*dim)+128;
	int start_Y=Center_Y-(16*dim)+60;
	
	for(i=0;i<12;i++){
		for(j=0;j<11;j++){
		if(Mela[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Mela[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Mela[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Yellow);
		if(Mela[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Green);
		if(Mela[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);  
										 }
									 }
	return;
}							
	
void AppleOnScreen(void){
	DrawApple(Mela);
	return;
}

void FriesOffScreen(void){
	
	int i,j=0;
	int dim=2;
	int start_X=Center_X-(20*dim)-80;
	int start_Y=Center_Y-(16*dim)+50;
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
		if(Patatine[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Patatine[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Patatine[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Patatine[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		
										 }
									 }
	return;
}				


void AppleOffScreen(){
	
	int i,j=0;
	int dim=2;
	int start_X=Center_X-(15*dim)+128;
	int start_Y=Center_Y-(16*dim)+60;
	
	for(i=0;i<12;i++){
		for(j=0;j<11;j++){
		if(Mela[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Mela[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Mela[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Mela[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Mela[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);  
										 }
									 }
	return;
}

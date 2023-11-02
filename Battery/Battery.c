#include "LPC17xx.h"
#include "../GLCD/GLCD.h" 
#include "Battery.h"
#include "stdio.h"

#define Center_X  120
#define Center_Y 163

int HappinessLevel;
int SatietyLevel;	


uint8_t Battery4[8][18]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
												{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												{1,0,2,2,0,3,3,0,4,4,0,5,5,0,1,1},
												{1,0,2,2,0,3,3,0,4,4,0,5,5,0,1,1},
												{1,0,2,2,0,3,3,0,4,4,0,5,5,0,1,1},
												{1,0,2,2,0,3,3,0,4,4,0,5,5,0,1,1},
												{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};

uint8_t Battery3[8][18]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,0,2,2,0,3,3,0,4,4,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,4,4,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,4,4,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,4,4,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};

uint8_t Battery2[8][18]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,0,2,2,0,3,3,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,3,3,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};

uint8_t Battery1[8][18]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};										 

uint8_t Battery0[8][18]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
												 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
												 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};													 

void DisegnaBatteriaSazieta(uint8_t Battery[8][18]){
	
	int i,j=0;
	int dim=3;
	int start_X=240-(20*dim);
	int start_Y=65;
	
	GUI_Text(240-(22*dim),45,(uint8_t*)"Satiety",Black,White);
	
for(i=0;i<8;i++){
		for(j=0;j<18;j++){
		if(Battery[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Battery[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Battery[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);
		if(Battery[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Orange);
		if(Battery[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Yellow);  
		if(Battery[i][j]==5)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Green);  
										 }
									 }

 return;
								 }

void DisegnaBatteriaFelicita(uint8_t Battery[8][18]){
	
	int i,j=0;
	int dim=3;
	int start_X=10;
	int start_Y=65;
	GUI_Text(3,45,(uint8_t*)"Happiness",Black,White);
	
for(i=0;i<8;i++){
		for(j=0;j<18;j++){
		if(Battery[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Battery[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Battery[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);
		if(Battery[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Orange);
		if(Battery[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Yellow);  
		if(Battery[i][j]==5)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Green);  
										 }
									 }
return;
}

void DecreaseHappinessBattery(){
	
	
	if(HappinessLevel==0)
			return;
		
		HappinessLevel--;
		
		if(HappinessLevel==3){DisegnaBatteriaFelicita(Battery3);}
		if(HappinessLevel==2){DisegnaBatteriaFelicita(Battery2);}
		if(HappinessLevel==1){DisegnaBatteriaFelicita(Battery1);}
		if(HappinessLevel==0){DisegnaBatteriaFelicita(Battery0);}
		
	}	
		
	void DecreaseSatietyBattery(){
		
		
		if(SatietyLevel==0)
			return;
		SatietyLevel--;
		
		if(SatietyLevel==3){DisegnaBatteriaSazieta(Battery3);}
		if(SatietyLevel==2){DisegnaBatteriaSazieta(Battery2);}
		if(SatietyLevel==1){DisegnaBatteriaSazieta(Battery1);}
		if(SatietyLevel==0){DisegnaBatteriaSazieta(Battery0);}
		
		return;
	}	
	
	void BatteryStartup(){
		DisegnaBatteriaFelicita(Battery4);
		DisegnaBatteriaSazieta(Battery4);
		HappinessLevel=4;
		SatietyLevel=4;
		
		return;
}

void IncreaseSatietyBattery(void){
	
	if(SatietyLevel==4)
		return;
	SatietyLevel++;
	
	if(SatietyLevel==4){DisegnaBatteriaSazieta(Battery4);}
	if(SatietyLevel==3){DisegnaBatteriaSazieta(Battery3);}
	if(SatietyLevel==2){DisegnaBatteriaSazieta(Battery2);}
	
	return;
	
}

void IncreaseHappinessBattery(void){
	
	if(HappinessLevel==4)
		return;
	HappinessLevel++;
	
	if(HappinessLevel==4){DisegnaBatteriaFelicita(Battery4);}
	if(HappinessLevel==3){DisegnaBatteriaFelicita(Battery3);}
	if(HappinessLevel==2){DisegnaBatteriaFelicita(Battery2);}
	
	return;
	
}

int IsAlive(void){
	if(HappinessLevel==0 || SatietyLevel==0){return 1; }
	else return 0;
}

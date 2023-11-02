#include "LPC17xx.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../timer/timer.h"
#include "Lugia.h"

#define Center_X  120
#define Center_Y 163


																
void DrawSprite(uint8_t CharacterMatrix[29][32]){
	
	int i,j=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(i=0;i<29;i++){
		for(j=0;j<32;j++){
		if(CharacterMatrix[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(CharacterMatrix[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(CharacterMatrix[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Grey);
		if(CharacterMatrix[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Cyan);
		if(CharacterMatrix[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Blue2);  
										 }
									 }
}							

void LugiaStartup(){
DrawSprite(Lugia_Matrix);
	return;
}


void LugiaShiftRight(void){
 int pixel_offshift=15;

	int i=0,j=0,k=0,l=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(k=0;k<pixel_offshift;k++){
		
		for(l=0;l<29;l++)//cancello colonna 
		LCD_DrawRectangle((start_X+k*dim),(start_Y+l*dim),dim,dim,White);
		
		for(i=0;i<29;i++){
			for(j=0;j<32;j++){
			if(Lugia_Matrix_Mirrored[i][j]==0)
				LCD_DrawRectangle((start_X+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,White);
			if(Lugia_Matrix_Mirrored[i][j]==1)
				LCD_DrawRectangle((start_X+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Black);
			if(Lugia_Matrix_Mirrored[i][j]==2)
				LCD_DrawRectangle((start_X+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Grey);
			if(Lugia_Matrix_Mirrored[i][j]==3)
				LCD_DrawRectangle((start_X+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Cyan);
			if(Lugia_Matrix_Mirrored[i][j]==4)
				LCD_DrawRectangle((start_X+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Blue2);  
		 }
		}
}
	return;}



void LugiaShiftRightReturn(void){
 int pixel_offshift=15;

	int i=0,j=0,k=0,l=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(k=0;k<pixel_offshift;k++){
		
		for(l=0;l<29;l++)//cancello colonna 
		LCD_DrawRectangle((start_X+pixel_offshift*dim+32*dim-(k+1)*dim),(start_Y+l*dim),dim,dim,White);
		
		
		for(i=0;i<29;i++){
			for(j=0;j<32;j++){
			if(Lugia_Matrix[i][j]==0)
				LCD_DrawRectangle((start_X+j*dim+pixel_offshift*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,White);
			if(Lugia_Matrix[i][j]==1)
				LCD_DrawRectangle((start_X+j*dim+pixel_offshift*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Black);
			if(Lugia_Matrix[i][j]==2)
				LCD_DrawRectangle((start_X+j*dim+pixel_offshift*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Grey);
			if(Lugia_Matrix[i][j]==3)
				LCD_DrawRectangle((start_X+j*dim+pixel_offshift*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Cyan);
			if(Lugia_Matrix[i][j]==4)
				LCD_DrawRectangle((start_X+j*dim+pixel_offshift*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Blue2);  
		 }
		}
	
}
	return;}


	void LugiaShiftLeft(void){
 int pixel_offshift=15;

	int i=0,j=0,k=0,l=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(k=0;k<pixel_offshift;k++){
		
		for(l=0;l<29;l++)//cancello colonna 
		LCD_DrawRectangle((start_X+32*dim-(k+1)*dim),(start_Y+l*dim),dim,dim,White);
		
		
		for(i=0;i<29;i++){
			for(j=0;j<32;j++){
			if(Lugia_Matrix[i][j]==0)
				LCD_DrawRectangle((start_X+j*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,White);
			if(Lugia_Matrix[i][j]==1)
				LCD_DrawRectangle((start_X+j*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Black);
			if(Lugia_Matrix[i][j]==2)
				LCD_DrawRectangle((start_X+j*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Grey);
			if(Lugia_Matrix[i][j]==3)
				LCD_DrawRectangle((start_X+j*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Cyan);
			if(Lugia_Matrix[i][j]==4)
				LCD_DrawRectangle((start_X+j*dim)-(k+1)*dim,(start_Y+i*dim),dim,dim,Blue2);  
		 }
		}
	
}
	return;}
	
	
	void LugiaShiftLeftReturn(void){
 int pixel_offshift=15;

	int i=0,j=0,k=0,l=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(k=0;k<pixel_offshift;k++){
		
		for(l=0;l<29;l++)//cancello colonna 
		LCD_DrawRectangle((start_X-pixel_offshift*dim+k*dim),(start_Y+l*dim),dim,dim,White);
		
		for(i=0;i<29;i++){
			for(j=0;j<32;j++){
			if(Lugia_Matrix_Mirrored[i][j]==0)
				LCD_DrawRectangle((start_X-pixel_offshift*dim+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,White);
			if(Lugia_Matrix_Mirrored[i][j]==1)
				LCD_DrawRectangle((start_X-pixel_offshift*dim+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Black);
			if(Lugia_Matrix_Mirrored[i][j]==2)
				LCD_DrawRectangle((start_X-pixel_offshift*dim+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Grey);
			if(Lugia_Matrix_Mirrored[i][j]==3)
				LCD_DrawRectangle((start_X-pixel_offshift*dim+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Cyan);
			if(Lugia_Matrix_Mirrored[i][j]==4)
				LCD_DrawRectangle((start_X-pixel_offshift*dim+j*dim)+(k+1)*dim,(start_Y+i*dim),dim,dim,Blue2);  
		 }
		}
}
	return;}


void LugiaDespawn(void){
	
	int i,j=0;
	int dim=3;
	int start_X=Center_X-(15*dim);
	int start_Y=Center_Y-(16*dim)+40;
	
	for(i=0;i<29;i++){
		for(j=0;j<32;j++){
		if(Lugia_Matrix[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Lugia_Matrix[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Lugia_Matrix[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Lugia_Matrix[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Lugia_Matrix[i][j]==4)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);  
										 }
									 }
}

void DrawPokeball (uint8_t Pokeball[12][12]){
	
	int i,j=0;
	int dim=5;
	int start_X=Center_X-(12*dim)+30;
	int start_Y=Center_Y-(12*dim)+50;
	
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
		if(Pokeball[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Pokeball[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Pokeball[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Grey);
		if(Pokeball[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);
										 }
									 }
}				

void PokeballOnScreen(void){
	DrawPokeball(Pokeball);
	return;}

	
	
	void PokeballOffScreen (void){
	
	int i,j=0;
	int dim=5;
	int start_X=Center_X-(12*dim)+30;
	int start_Y=Center_Y-(12*dim)+50;
	
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
		if(Pokeball[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Pokeball[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Pokeball[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Pokeball[i][j]==3)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
										 }
									 }
}	
	
		
	
int LugiaCuddled(void){
	int dim=3;
	if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
		if((display.x>Center_X-(15*dim) && display.x<Center_X-(15*dim)+32*dim) && (display.y>Center_Y-16*dim+40 && display.y<Center_Y-(16*dim)+40+29*dim)){
		//GUI_Text(120-50,80,(uint8_t*)"OK",Black,White);
			return 1;
		}
	}
	return 0;
}

void DrawHeart(void){
	int i,j=0;
	int dim=2;
	int start_X=Center_X-15;
	int start_Y=Center_Y-(16*dim)-20;
	
	for(i=0;i<13;i++){
		for(j=0;j<13;j++){
		if(Heart[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Heart[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Black);
		if(Heart[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,Red);
		 
										 }
									 }
}		

void DespawnHeart(void){
	int i,j=0;
	int dim=2;
	int start_X=Center_X-15;
	int start_Y=Center_Y-(16*dim)-20;
	
	for(i=0;i<13;i++){
		for(j=0;j<13;j++){
		if(Heart[i][j]==0)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Heart[i][j]==1)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		if(Heart[i][j]==2)
			LCD_DrawRectangle(start_X+j*dim,start_Y+i*dim,dim,dim,White);
		 
										 }
									 }
}		
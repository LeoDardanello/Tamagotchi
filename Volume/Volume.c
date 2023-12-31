#include "lpc17xx.h"
#include "Volume.h"
#include "../GLCD/GLCD.h"

#define Center_X  120
#define Center_Y 163

int VolumeLevel=3;
//int extern Volume;
uint8_t Volume_level_3[11][11]={{0,0,0,0,1,0,0,0,0,0,1},
																{0,0,0,1,1,0,0,0,0,0,1},
																{0,0,1,1,1,0,0,0,1,0,1},
																{0,0,1,1,1,0,0,0,1,0,1},
																{1,1,1,1,1,0,1,0,1,0,1},
																{1,1,1,1,1,0,1,0,1,0,1},
																{1,1,1,1,1,0,1,0,1,0,1},
																{0,0,1,1,1,0,0,0,1,0,1},
																{0,0,0,1,1,0,0,0,1,0,1},
																{0,0,0,1,1,0,0,0,0,0,1},
																{0,0,0,0,1,0,0,0,0,0,1}};

																
uint8_t Volume_level_2[11][11]={{0,0,0,0,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,1,0,0},
																{0,0,1,1,1,0,0,0,1,0,0},
																{1,1,1,1,1,0,1,0,1,0,0},
																{1,1,1,1,1,0,1,0,1,0,0},
																{1,1,1,1,1,0,1,0,1,0,0},
																{0,0,1,1,1,0,0,0,1,0,0},
																{0,0,0,1,1,0,0,0,1,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,0,0,1,0,0,0,0,0,0}};

																
uint8_t Volume_level_1[11][11]={{0,0,0,0,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{1,1,1,1,1,0,1,0,0,0,0},
																{1,1,1,1,1,0,1,0,0,0,0},
																{1,1,1,1,1,0,1,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,0,0,1,0,0,0,0,0,0}};
																	
	
	
uint8_t Volume_level_0[11][11]={{0,0,0,0,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{1,1,1,1,1,0,0,0,0,0,0},
																{1,1,1,1,1,0,0,0,0,0,0},
																{1,1,1,1,1,0,0,0,0,0,0},
																{0,0,1,1,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,0,1,1,0,0,0,0,0,0},
																{0,0,0,0,1,0,0,0,0,0,0}};
	
void PrintVolumeLevel(uint8_t Matrix[11][11]){
	
	int i=0,j=0;
	int dim=2;
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			if(Matrix[i][j]==0){
				LCD_DrawRectangle(10+j*dim,10+i*dim,dim,dim,White);
			}
			if(Matrix[i][j]==1){
		
				LCD_DrawRectangle(10+j*dim,10+i*dim,dim,dim,Black);
			}
			
		}
	}
	
	
	
}


void Volume3 (void){
	PrintVolumeLevel(Volume_level_3);
	return;
}

void Volume2 (void){
	PrintVolumeLevel(Volume_level_2);
	return;
}
void Volume1 (void){
	PrintVolumeLevel(Volume_level_1);
	return;
}
void Volume0 (void){
	PrintVolumeLevel(Volume_level_0);
	return;
}

/*void VolumeStartup(void){
	Volume=100;
	Volume3();
	
	return;
}*/
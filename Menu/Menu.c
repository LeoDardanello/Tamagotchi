#include <stdio.h>
#include "LPC17xx.h"
#include "Menu.h"
#include "../GLCD/GLCD.h"

//dimensione cella menu sx 118(0-117) x 42 (284-326)
void MenuStartup(void){
	
	LCD_DrawRectangle(0,280,240,4,Black);//linea orizz
	LCD_DrawRectangle(118,280,4,46,Black);//linea vert
	GUI_Text(59-17,295,(uint8_t*)"Meal",Black,White);
	GUI_Text(164-5,295,(uint8_t*)"Snack",Black,White);
	return;
}

void MenuSelectLeft(void){
	
	
	//coloro rosso cella sx
	LCD_DrawLine(0,284,117,284,Red);//riga orizz sopra
	LCD_DrawLine(0,285,117,285,Red);
	LCD_DrawLine(0,286,117,286,Red);
	LCD_DrawLine(0,287,117,287,Red);
	
	LCD_DrawLine(0,317,117,317,Red);//riga orizz sotto
	LCD_DrawLine(0,318,117,318,Red);
	LCD_DrawLine(0,319,117,319,Red);
	LCD_DrawLine(0,320,117,320,Red);
	
	LCD_DrawLine(115,284,115,320,Red);// riga vert dx
	LCD_DrawLine(116,284,116,320,Red);
	LCD_DrawLine(117,284,117,320,Red);
	LCD_DrawLine(118,284,118,320,Red);
	
	LCD_DrawLine(0,284,0,320,Red); //riga vert sx
	LCD_DrawLine(1,284,1,320,Red);
	LCD_DrawLine(2,284,2,320,Red);
	LCD_DrawLine(3,284,3,320,Red);
	
	GUI_Text(59-17,295,(uint8_t*)"Meal",Red,White);
	
	
	//deseleziono (coloro di bianco) cella dx
	
	LCD_DrawLine(122,284,240,284,White);//riga orizz sopra
	LCD_DrawLine(122,285,240,285,White);
	LCD_DrawLine(122,286,240,286,White);
	LCD_DrawLine(122,287,240,287,White);
	
	LCD_DrawLine(122,317,240,317,White);//riga orizz sotto
	LCD_DrawLine(122,318,240,318,White);
	LCD_DrawLine(122,319,240,319,White);
	LCD_DrawLine(122,320,240,320,White);
	
	LCD_DrawLine(237,284,237,320,White);// riga vert dx
	LCD_DrawLine(238,284,238,320,White);
	LCD_DrawLine(239,284,239,320,White);
	LCD_DrawLine(240,284,240,320,White);
	
	LCD_DrawLine(122,284,122,320,White); //riga vert sx
	LCD_DrawLine(123,284,123,320,White);
	LCD_DrawLine(124,284,124,320,White);
	LCD_DrawLine(125,284,125,320,White);
	
	GUI_Text(164-5,295,(uint8_t*)"Snack",Black,White);
	
	return;
}

void MenuSelectRight(void){
	
	LCD_DrawLine(122,284,240,284,Red);//riga orizz sopra
	LCD_DrawLine(122,285,240,285,Red);
	LCD_DrawLine(122,286,240,286,Red);
	LCD_DrawLine(122,287,240,287,Red);
	
	LCD_DrawLine(122,317,240,317,Red);//riga orizz sotto
	LCD_DrawLine(122,318,240,318,Red);
	LCD_DrawLine(122,319,240,319,Red);
	LCD_DrawLine(122,320,240,320,Red);
	
	LCD_DrawLine(237,284,237,320,Red);// riga vert dx
	LCD_DrawLine(238,284,238,320,Red);
	LCD_DrawLine(239,284,239,320,Red);
	LCD_DrawLine(240,284,240,320,Red);
	
	LCD_DrawLine(122,284,122,320,Red); //riga vert sx
	LCD_DrawLine(123,284,123,320,Red);
	LCD_DrawLine(124,284,124,320,Red);
	LCD_DrawLine(125,284,125,320,Red);
	
	GUI_Text(164-5,295,(uint8_t*)"Snack",Red,White);
	
	//deseleziono (coloro di bianco) cella sx
	
	LCD_DrawLine(0,284,117,284,White);//riga orizz sopra
	LCD_DrawLine(0,285,117,285,White);
	LCD_DrawLine(0,286,117,286,White);
	LCD_DrawLine(0,287,117,287,White);
	
	LCD_DrawLine(0,317,117,317,White);//riga orizz sotto
	LCD_DrawLine(0,318,117,318,White);
	LCD_DrawLine(0,319,117,319,White);
	LCD_DrawLine(0,320,117,320,White);
	
	LCD_DrawLine(115,284,115,320,White);// riga vert dx
	LCD_DrawLine(116,284,116,320,White);
	LCD_DrawLine(117,284,117,320,White);
	LCD_DrawLine(118,284,118,320,White);
	
	LCD_DrawLine(0,284,0,320,White); //riga vert sx
	LCD_DrawLine(1,284,1,320,White);
	LCD_DrawLine(2,284,2,320,White);
	LCD_DrawLine(3,284,3,320,White);
	
	GUI_Text(59-17,295,(uint8_t*)"Meal",Black,White);
	
	return;}

	void MenuReset(void){
		
	GUI_Text(120-20,295,(uint8_t*)"Reset",White,White);
	LCD_DrawRectangle(118,280,4,46,Black);//linea vert
		
	//cella dx	
	LCD_DrawLine(0,284,117,284,White);//riga orizz sopra
	LCD_DrawLine(0,285,117,285,White);
	LCD_DrawLine(0,286,117,286,White);
	LCD_DrawLine(0,287,117,287,White);
	
	LCD_DrawLine(0,317,117,317,White);//riga orizz sotto
	LCD_DrawLine(0,318,117,318,White);
	LCD_DrawLine(0,319,117,319,White);
	LCD_DrawLine(0,320,117,320,White);
	
	LCD_DrawLine(115,284,115,320,White);// riga vert dx
	LCD_DrawLine(116,284,116,320,White);
	LCD_DrawLine(117,284,117,320,White);
	LCD_DrawLine(118,284,118,320,White);
	
	LCD_DrawLine(0,284,0,320,White); //riga vert sx
	LCD_DrawLine(1,284,1,320,White);
	LCD_DrawLine(2,284,2,320,White);
	LCD_DrawLine(3,284,3,320,White);
		
	//cella sx
	LCD_DrawLine(122,284,240,284,White);//riga orizz sopra
	LCD_DrawLine(122,285,240,285,White);
	LCD_DrawLine(122,286,240,286,White);
	LCD_DrawLine(122,287,240,287,White);
	
	LCD_DrawLine(122,317,240,317,White);//riga orizz sotto
	LCD_DrawLine(122,318,240,318,White);
	LCD_DrawLine(122,319,240,319,White);
	LCD_DrawLine(122,320,240,320,White);
	
	LCD_DrawLine(237,284,237,320,White);// riga vert dx
	LCD_DrawLine(238,284,238,320,White);
	LCD_DrawLine(239,284,239,320,White);
	LCD_DrawLine(240,284,240,320,White);
	
	LCD_DrawLine(122,284,122,320,White); //riga vert sx
	LCD_DrawLine(123,284,123,320,White);
	LCD_DrawLine(124,284,124,320,White);
	LCD_DrawLine(125,284,125,320,White);
	
	GUI_Text(59-17,295,(uint8_t*)"Meal",Black,White);
	GUI_Text(164-5,295,(uint8_t*)"Snack",Black,White);
	
	return;
}
	
void ResetButton (void){
	
	LCD_DrawLine(0,284,117,284,White);//riga orizz sopra
	LCD_DrawLine(0,285,117,285,White);
	LCD_DrawLine(0,286,117,286,White);
	LCD_DrawLine(0,287,117,287,White);
	
	LCD_DrawLine(0,317,117,317,White);//riga orizz sotto
	LCD_DrawLine(0,318,117,318,White);
	LCD_DrawLine(0,319,117,319,White);
	LCD_DrawLine(0,320,117,320,White);
	
	LCD_DrawLine(115,284,115,320,White);// riga vert dx
	LCD_DrawLine(116,284,116,320,White);
	LCD_DrawLine(117,284,117,320,White);
	LCD_DrawLine(118,284,118,320,White);
	
	LCD_DrawLine(0,284,0,320,White); //riga vert sx
	LCD_DrawLine(1,284,1,320,White);
	LCD_DrawLine(2,284,2,320,White);
	LCD_DrawLine(3,284,3,320,White);
	
	LCD_DrawLine(122,284,240,284,White);//riga orizz sopra
	LCD_DrawLine(122,285,240,285,White);
	LCD_DrawLine(122,286,240,286,White);
	LCD_DrawLine(122,287,240,287,White);
	
	LCD_DrawLine(122,317,240,317,White);//riga orizz sotto
	LCD_DrawLine(122,318,240,318,White);
	LCD_DrawLine(122,319,240,319,White);
	LCD_DrawLine(122,320,240,320,White);
	
	LCD_DrawLine(237,284,237,320,White);// riga vert dx
	LCD_DrawLine(238,284,238,320,White);
	LCD_DrawLine(239,284,239,320,White);
	LCD_DrawLine(240,284,240,320,White);
	
	LCD_DrawLine(122,284,122,320,White); //riga vert sx
	LCD_DrawLine(123,284,123,320,White);
	LCD_DrawLine(124,284,124,320,White);
	LCD_DrawLine(125,284,125,320,White);
	
	
	LCD_DrawRectangle(118,280,4,46,White);//linea vert
	LCD_DrawRectangle(0,280,240,4,Black);//linea orizz

	GUI_Text(59-17,295,(uint8_t*)"Meal",White,White);
	GUI_Text(164-5,295,(uint8_t*)"Snack",White,White);
	GUI_Text(120-20,295,(uint8_t*)"Reset",Black,White);
	
	return;
}

void ResetButtonOffScreen (void){
	
	LCD_DrawRectangle(0,280,240,4,Black);//linea orizz
	GUI_Text(120-20,295,(uint8_t*)"Reset",White,White);
	
	return;
}

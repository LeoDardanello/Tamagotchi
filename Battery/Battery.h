#include "LPC17xx.h"
#include "../GLCD/GLCD.h" 

//void DisegnaBatteriaSazieta(uint8_t Battery[8][18]);
//void DisegnaBatteriaFelicita(uint8_t Battery[8][18]);
void BatteryStartup(void);
void DecreaseSatietyBattery(void);
void DecreaseHappinessBattery(void);
void IncreaseSatietyBattery(void);
void IncreaseHappinessBattery(void);
int IsAlive(void);	

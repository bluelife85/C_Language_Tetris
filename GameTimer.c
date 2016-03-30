#include <windows.h>
#include "GameTimer.h"

static uint32_t TICK;

static void tenMiliTickHandler(void){
	
	TICK++;
	Sleep(1);
}

static uint32_t getCurrentTick(void){
	
	return TICK;
}

static uint32_t getPassedTick(uint32_t t){
	
	uint32_t retval;
	
	if(TICK > t){
		
		retval = TICK - t;
	}
	else{
		retval = t - TICK + 1;
	}
	
	return retval;
}

const ClassTimer Timer = {
	tenMiliTickHandler,
	getCurrentTick,
	getPassedTick
};


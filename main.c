#include <stdio.h>
#include <stdlib.h>

#include "GameTetris.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	if(Tetris.initialize()){
		
		Tetris.run();
	}
	else{
		printf("initialize failed\n");
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "GameTetris.h"
#include "GameRule.h"
#include "GameBlock.h"
#include "GameTimer.h"

static GameBlock_st CurrentBlock;
static GameBlock_st NextBlock;

static void LoadGameBoard(void){
	
	char* f = "*****************";
	char* b = "*               *";
	int i;
	
	puts(f);
	for(i=0;i<20;i++){
		
		puts(b);
	}
	puts(f);
}

static int GameInitialize(void){
	
	time_t t;
	
	time(&t);
	srand(t);
	
	if(GameBlock.regist(&CurrentBlock,&NextBlock)){
		
		LoadGameBoard();
		return 1;
	}
	
	return 0;
}

static void RunGame(void){
	
	KeyEvent event = None;
	Coordinator position = {7,0};
	GameBlock.move(event,&position);
	
	while(event != GameOff){
		
		event = KeyEventHandler();
		
		switch(event){
			case Up:
				GameRule.rotate(&position);
				break;
			case Right:
				if(!GameRule.hasRight(&position)){
					GameBlock.move(event, &position);
				}
				break;
			case Down:
				if(!GameRule.hasBottom(&position)){
					GameBlock.move(event, &position);
				}
				else{
					GameRule.stack(&position);
					GameRule.clear();
					GameBlock.getNext();
					position.x = 7;
					position.y = 0;
					GameBlock.move(None,&position);
				}
				break;
			case Left:
				if(!GameRule.hasLeft(&position)){
					GameBlock.move(event,&position);
				}
				break;
		}
		
		Timer.runtime();
	}
}

const ClassGame Tetris = {
	GameInitialize,
	RunGame
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GameCoordinator.h"
#include "GameBlock.h"

static int getImagePos(Coordinator* dest, Coordinator* src){
	
	GameBlock_st* block = NULL;
	
	block = GameBlock.getCurrentBlock();
	
	if(block == NULL){
		
		return -1;
	}
	
	dest->x = src->x + block->Block.StartWidth;
	dest->y = src->y + block->Block.StartHeight;
	
	return 1;
}

static int getRightPos(Coordinator* src){
	
	GameBlock_st* block = NULL;
	
	block = GameBlock.getCurrentBlock();
	
	if(block == NULL){
		
		return -1;
	}
	
	return src->x + block->Block.EndWidth;
}

static int getLeftPos(Coordinator* src){
	
	GameBlock_st* block = NULL;
	
	block = GameBlock.getCurrentBlock();
	
	if(block == NULL){
		
		return -1;
	}
	
	return src->x + block->Block.StartWidth;
}

static int getBottonPos(Coordinator* src){
	
	GameBlock_st* block = NULL;
	
	block = GameBlock.getCurrentBlock();
	
	if(block == NULL){
		
		return -1;
	}
	
	return src->y + block->Block.EndHeight;
}

const ClassPosition Position = {
	
	getImagePos,
	getRightPos,
	getLeftPos,
	getBottonPos
};

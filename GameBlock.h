#ifndef TETRIS_GAME_BLOCK_H_
#define TETRIS_GAME_BLOCK_H_

#include "GameCoordinator.h"
#include "GameKeyEvent.h"

typedef struct blockinfo{
	char Block[4][4];
	int StartWidth;
	int EndWidth;
	int StartHeight;
	int EndHeight;
}Block_st;

typedef struct gb{
	Block_st Block;
	int Direction;
	int Type;
	int color;
}GameBlock_st;

typedef struct cBlock{
	int (*regist)(GameBlock_st* c, GameBlock_st* n);
	int (*getNext)(void);
	int (*rotate)(void);
	GameBlock_st* (*getCurrentBlock)(void);
	void (*move)(KeyEvent e, Coordinator* pos);
	void (*show)(int type, int direction);
	void (*set)(int type, int dir);
	
}ClassBlock;

extern const ClassBlock GameBlock;

#endif /* TETRIS_GAME_BLOCK_H_ */


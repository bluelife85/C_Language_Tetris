#ifndef TETRIS_GAME_RULE_H_
#define TETRIS_GAME_RULE_H_

#include "GameBlock.h"

typedef struct crule{
	int (*isRightEnd)(Coordinator* pos);
	int (*isLeftEnd)(Coordinator* pos);
	int (*isBottomEnd)(Coordinator* pos);
	int (*hasRight)(Coordinator* pos);
	int (*hasLeft)(Coordinator* pos);
	int (*hasBottom)(Coordinator* pos);
	void (*stack)(Coordinator* pos);
	void (*view)(void);
	int (*rotate)(Coordinator* pos);
	void (*clear)(void);
}ClassGameRule;

extern const ClassGameRule GameRule;

#endif


#ifndef TETRIS_GAME_H_
#define TETRIS_GAME_H_

typedef struct tetris{
	int (*initialize)(void);
	void (*run)(void);
}ClassGame;

extern const ClassGame Tetris;

#endif /* TETRIS_GAME_RULE_H_ */


#ifndef TETRIS_GAME_TIMER_H_
#define TETRIS_GAME_TIMER_H_

#include <stdint.h>

typedef struct gtimer{
	void (*runtime)(void);
	uint32_t (*getCurrent)(void);
	uint32_t (*getPassed)(uint32_t t);
}ClassTimer;

extern const ClassTimer Timer;

#endif /* TETRIS_GAME_TIMER_H_ */

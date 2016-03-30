#ifndef TETRIS_KEY_EVENT_H_
#define TETRIS_KEY_EVENT_H_

typedef enum {
	None = 0,
	Up,
	Right,
	Down,
	Left,
	GameOff
} KeyEvent;

KeyEvent KeyEventHandler(void);

#endif /* TETRIS_KEY_EVENT_H_ */


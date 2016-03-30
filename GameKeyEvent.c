#include "GameKeyEvent.h"

static int unicode;
static char unicodeFlag;

KeyEvent KeyEventHandler(void){
	
	KeyEvent key = None;
	int ch;
	
	if(kbhit()){
		ch = getch();
		if(ch & 0x80){
			unicodeFlag = 1;
			unicode = ch;
			unicode <<= 8;
		}
		else{
			if(unicodeFlag){
				unicode |= ch;
				if(unicode == 0xe048){ // pushed up
					key = Up;
				}
				else if(unicode == 0xe04d){ // pushed right
					key = Right;
				}
				else if(unicode == 0xe050){ // pushed down
					key = Down;
				}
				else if(unicode == 0xe04b){ // pusehd left
					key = Left;
				}
				unicodeFlag = 0;
			}
			else{
				// check esc key
				if(ch == 0x1b){
					key = GameOff;
				}
				unicode = 0;
			}
		}
	}
	
	return key;
}

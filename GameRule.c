#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "GameRule.h"

#ifndef X_LENGTH
#define X_LENGTH 15
#endif

#ifndef Y_LENGTH
#define Y_LENGTH 20
#endif

static char GameBoard[Y_LENGTH][X_LENGTH];

static int isRightEnd(Coordinator* pos){
	
	GameBlock_st* b;
	
	b = GameBlock.getCurrentBlock();
	
	if(b != NULL){
		
		if(b->Block.StartWidth == 0){
			if((pos->x + b->Block.EndWidth) == X_LENGTH){
				
				return 1;
			}
			return 0;
		}
		else{
			
			if((pos->x + b->Block.StartWidth + b->Block.EndWidth) > X_LENGTH){
				
				return 1;
			}
			return 0;
		}
	}
	
	return 1;
}

static int isLeftEnd(Coordinator* pos){
	
	GameBlock_st* b;
	
	b = GameBlock.getCurrentBlock();
	
	if(b != NULL){
		if(b->Block.StartWidth == 0){
			if((pos->x -1) == 0){
				
				return 1;
			}
			return 0;
		}
		else{
			
			if((pos->x - b->Block.StartWidth) < 0){
				
				return 1;
			}
			return 0;
		}
	}
	
	return 1;
}

static int isBottomEnd(Coordinator* pos){
	
	GameBlock_st* b;
	
	b = GameBlock.getCurrentBlock();
	
	if(b != NULL){
		if(b->Block.StartHeight == 0){
			if((pos->y + b->Block.EndHeight + 1) == Y_LENGTH){
				
				return 1;
			}
			
			return 0;
		}
		else if(b->Block.StartHeight == b->Block.EndHeight){
			if((pos->y + b->Block.EndHeight -1) == Y_LENGTH){
				
				return 1;
			}
			
			return 0;
		}
		else{
			
			if((pos->y + b->Block.StartHeight + b->Block.EndHeight - 1 ) == Y_LENGTH){
				
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	
	
	return 1;
}

static int hasRightBlock(Coordinator* pos){
	
	GameBlock_st* b;
	int x,y;
	
	b = GameBlock.getCurrentBlock();
	
	if(!isRightEnd(pos)){
		for(y = b->Block.StartHeight;y <= b->Block.EndHeight;y++){
			for(x = b->Block.StartWidth;x <= b->Block.EndWidth;x++){
				if(x != 3){
					if(b->Block.Block[y][x+1] == 0){
						if(GameBoard[y - b->Block.StartHeight + pos->y][x + pos->x - b->Block.StartWidth + 1] && 
							b->Block.Block[y][x]){
							
							return 1;
						}
					}
				}
				else{
					if(GameBoard[y - b->Block.StartHeight + pos->y][x + pos->x - b->Block.StartWidth + 1] && 
						b->Block.Block[y][3]){
						return 1;
					}
				}
			}
		}
		
		return 0;
	}
	
	return 1;
}

static int hasLeftBlock(Coordinator* pos){
	
	GameBlock_st* b;
	int x,y;
	
	b = GameBlock.getCurrentBlock();
	
	if(!isLeftEnd(pos)){
		
		for(y = b->Block.StartHeight;y <= b->Block.EndHeight;y++){
			for(x = b->Block.EndWidth;x >= b->Block.StartWidth;x--){
				if(x != 0){
					if(b->Block.Block[y][x-1] == 0){
						if(GameBoard[y - b->Block.StartHeight + pos->y][x + pos->x - b->Block.StartWidth - 1] && 
							b->Block.Block[y][x]){
							
							return 1;
						}
					}
				}
				else{
					if(GameBoard[y - b->Block.StartHeight + pos->y][x + pos->x - b->Block.StartWidth - 1] && 
						b->Block.Block[y][0]){
						return 1;
					}
				}
			}
		}
		
		return 0;
	}
	return 1;
}

static int hasBottomBlock(Coordinator* pos){
	
	GameBlock_st* b;
	int i;
	int y;
	
	b = GameBlock.getCurrentBlock();
		
	if(!isBottomEnd(pos)){
		
		for(i=b->Block.StartWidth;i<=b->Block.EndWidth;i++){
			for(y=b->Block.StartHeight;y<=b->Block.EndHeight;y++){
				if(y != 3){
					if(b->Block.Block[y+1][i] == 0){
						
						if(GameBoard[y - b->Block.StartHeight + pos->y + 1][i + pos->x - 1] && 
							b->Block.Block[y][i]){
							
							return 1;
						}
					}
				}
				else{
					if(GameBoard[y - b->Block.StartHeight + pos->y + 1][i + pos->x - 1] && 
						b->Block.Block[3][i]){
						return 1;
					}
				}
			}
		}
		
		return 0;
	}
	
	return 1;
}

static void stackBoard(Coordinator* pos){
	
	GameBlock_st* b;
	int i,j;
	
	b = GameBlock.getCurrentBlock();
	
	if(b->Block.StartHeight == 0){
		for(i = b->Block.StartHeight;i <= b->Block.EndHeight; i++){
			for(j = b->Block.StartWidth; j <= b->Block.EndWidth; j++){
				if(b->Block.Block[i][j]){
					GameBoard[pos->y + i][pos->x + j - 1] = b->color;
				}
			}
		}
	}
	else if(b->Block.StartHeight == b->Block.EndHeight){
		for(i = b->Block.StartHeight;i <= b->Block.EndHeight; i++){
			for(j = b->Block.StartWidth; j <= b->Block.EndWidth; j++){
				if(b->Block.Block[i][j]){
					GameBoard[pos->y + i - 2][pos->x + j - 1] = b->color;
				}
			}
		}
	}
	else{
		for(i = b->Block.StartHeight;i <= b->Block.EndHeight; i++){
			for(j = b->Block.StartWidth; j <= b->Block.EndWidth; j++){
				if(b->Block.Block[i][j]){
					GameBoard[pos->y + i - 1][pos->x + j - 1] = b->color;
				}
			}
		}
	}
	
}

static void viewBoard(void){
	
	int i,j;
	
	for(i=0;i<Y_LENGTH;i++){
		for(j=0;j<X_LENGTH;j++){
			gotoxy(40+j,1+i);
			if(GameBoard[i][j]){
				putchar('*');
			}
			else{
				putchar('-');
			}
		}
	}
}

static int rotateRule(Coordinator* pos){
	
	int prior_index;
	int prior_type;
	
	GameBlock_st* b;
	
	int i,j;
	int compensate;
	
	b = GameBlock.getCurrentBlock();
	
	compensate = b->Block.StartHeight;
	
	prior_index = b->Direction;
	prior_type = b->Type;
	
	if(compensate == 0){
		compensate++;
	}
	else if(b->Block.StartHeight == b->Block.EndHeight){
		compensate = -1;
	}
	else{
		compensate = 0;
	}
	
	for(i=b->Block.StartHeight;i<4;i++){
		for(j=b->Block.StartWidth;j<4;j++){
			gotoxy(pos->x+j,pos->y + i + compensate);
			if(b->Block.Block[i][j]){
				putchar(' ');
			}
		}
	}
	
	GameBlock.rotate();
	
	if(hasBottomBlock(pos)){
		GameBlock.set(prior_type,prior_index);
		GameBlock.move(None,pos);
		return 0;
	}
	
	if(hasRightBlock(pos)){
		GameBlock.set(prior_type,prior_index);
		GameBlock.move(None,pos);
		return 0;
	}
	
	if(hasLeftBlock(pos)){
		GameBlock.set(prior_type,prior_index);
		GameBlock.move(None,pos);
		return 0;
	}
	
	GameBlock.move(None,pos);
	return 1;
}

static void refresh(void){
	
	int i,j;
	
	for(i=0;i<Y_LENGTH;i++){
		for(j=0;j<X_LENGTH;j++){
			gotoxy(1+j,1+i);
			if(GameBoard[i][j]){
				textcolor(GameBoard[i][j]);
				putchar('*');
			}
			else{
				putchar(' ');
			}
		}
	}
}

static void lineClear(void){
	
	int x,y;
	int f = 1;
	int y_1;
	char* full = "***************";
	char* b = "*             *";
	
	for(y = Y_LENGTH - 1; y >= 0; y--){
		for(x=0;x < X_LENGTH; x++){
			
			if(GameBoard[y][x] == 0){
				f = 0;
				break;
			}
		}
		
		if(f){
			for(y_1 = y; y_1 >= 0; y_1--){
				memcpy(&GameBoard[y_1], &GameBoard[y_1 - 1],X_LENGTH);
			}
			
			textcolor(9);
			gotoxy(1,y+1);
			printf("%s",b);
			Sleep(500);
			gotoxy(1,y+1);
			printf("%s",full);
			Sleep(200);
			gotoxy(1,y+1);
			printf("%s",b);
			Sleep(100);
			gotoxy(1,y+1);
			printf("%s",full);
			Sleep(50);
			gotoxy(1,y+1);
			printf("%s",full);
			Sleep(10);
			refresh();
		}
		
		f = 1;
	}
}
const ClassGameRule GameRule = {
	isRightEnd,
	isLeftEnd,
	isBottomEnd,
	hasRightBlock,
	hasLeftBlock,
	hasBottomBlock,
	stackBoard,
	viewBoard,
	rotateRule,
	lineClear
};

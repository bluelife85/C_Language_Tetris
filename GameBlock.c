#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameBlock.h"
#include "conios.h"

const Block_st BLOCKS[7][4] = 
{
	{
		{ // I block start 0
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0}
			},
			1,
			1,
			0,
			3
		},
		{
			{
				{0,0,0,0},
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0}
			},
			0,
			3,
			2,
			2
		},
		{
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0}
			},
			1,
			1,
			0,
			3
		},
		{
			{
				{0,0,0,0},
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0}
			},
			0,
			3,
			2,
			2
		} // I Block End
	},
	{
		{ // L Block Start 1
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			0,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,1},
				{0,1,0,0},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,0,1,0},
				{0,0,1,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,0,0,1},
				{0,1,1,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		}// L block End
	},
	{
		{// L Mirror Block Start 2
			{
				{0,0,1,0},
				{0,0,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			0,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,0,0},
				{0,1,1,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,1,1,1},
				{0,0,0,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		}// L mirro End
	},
	{
		{// square start 3
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			2,
			1,
			2
		}// square end
	},
	{
		{// zig start 4
			{
				{0,0,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,0,1,1},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,0,1,1},
				{0,1,1,0},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		}// zig end
	},
	{
		{ // zig mirro start 5
			{
				{0,0,0,0},
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,0,1,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,0,1,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		}// zig mirro end
	},
	{
		{ // half cross start 6
			{
				{0,0,0,0},
				{0,0,1,0},
				{0,1,1,1},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,1,0,0}
			},
			1,
			2,
			1,
			3
		},
		{
			{
				{0,0,0,0},
				{0,1,1,1},
				{0,0,1,0},
				{0,0,0,0}
			},
			1,
			3,
			1,
			2
		},
		{
			{
				{0,0,0,0},
				{0,0,1,0},
				{0,1,1,0},
				{0,0,1,0}
			},
			1,
			2,
			1,
			3
		}
	},
};

static GameBlock_st* current;
static GameBlock_st* next;

static void showBlock(int type, int direction){
	
	int i,j;
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			gotoxy(20+j,5+i);
			if(BLOCKS[type][direction].Block[i][j]){
				putchar(' '); 
			}
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			gotoxy(20+j,5+i);
			if(BLOCKS[type][direction].Block[i][j]){
				putchar('*');
			}
		}
	}
}

static int regBlock(GameBlock_st* c, GameBlock_st* n){
	
	int type;
	int direction;
	int color;
	
	if(c != NULL && n != NULL){
		
		current = c;
		next = n;
		
		type = rand() % 7;
		direction = rand() % 4;
		color = rand() % 4 + 1;
		
		memcpy(c,&BLOCKS[type][direction],sizeof(Block_st));
		c->color = color;
		c->Type = type;
		c->Direction = direction;
		
		type = rand() % 7;
		direction = rand() % 4;
		color = rand() % 4 + 1;
		
		memcpy(n,&BLOCKS[type][direction],sizeof(Block_st));
		n->color = color;
		n->Type = type;
		n->Direction = direction;
		
		return 1;
	}
	
	return 0;
}

static int getNextBlock(void){
	
	int type;
	int direction;
	int color;
	
	if(current != NULL && next != NULL){
		
		memcpy(current,next,sizeof(GameBlock_st));
		
		type = rand() % 7;
		direction = rand() % 4;
		color = rand() % 4 + 1;
		
		memcpy(next,&BLOCKS[type][direction],sizeof(Block_st));
		next->color = color;
		next->Type = type;
		next->Direction = direction;
		
		return 1;
	}
	
	return 0;
}

static int getRotateBlock(void){
	
	if(current != NULL && next != NULL){
		
		current->Direction++;
		if(current->Direction == 4){
			current->Direction = 0;
		}
		
		memcpy(current,&BLOCKS[current->Type][current->Direction],sizeof(Block_st));
		
		return 1;
	}
	
	return 0;
}

static GameBlock_st* getCurrentBlock(void){
	
	if(current != NULL){
		
		return current;
	}
	
	return NULL;
}

static void moveBlock(KeyEvent e, Coordinator* pos){
	
	int i,j;
	int compensate;
	
	compensate = current->Block.StartHeight;
	
	if(compensate == 0){
		compensate++;
	}
	else if(current->Block.StartHeight == current->Block.EndHeight){
		compensate = -1;
	}
	else{
		compensate = 0;
	}
	
	for(i=current->Block.StartHeight;i<4;i++){
		for(j=current->Block.StartWidth;j<4;j++){
			gotoxy(pos->x+j,pos->y + i + compensate);
			if(current->Block.Block[i][j]){
				putchar(' ');
			}
		}
	}
	
	switch(e){
		case Down:
			pos->y++;
			break;
		case Left:
			pos->x--;
			break;
		case Right:
			pos->x++;
			break;
	}
	
	textcolor(current->color);
	
	for(i=current->Block.StartHeight;i<4;i++){
		for(j=current->Block.StartWidth;j<4;j++){
			gotoxy(pos->x+j,pos->y + i + compensate);
			if(current->Block.Block[i][j]){
				putchar('*');
			}
		}
	}
}

static void setIndexBlock(int type, int dir){
	
	memcpy(current,&BLOCKS[type][dir],sizeof(Block_st));
	current->Type = type;
	current->Direction = dir;
}

const ClassBlock GameBlock = {
	regBlock,
	getNextBlock,
	getRotateBlock,
	getCurrentBlock,
	moveBlock,
	showBlock,
	setIndexBlock
};

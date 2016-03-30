#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void textcolor(int color_number){
	
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void gotoxy(int x, int y){
	
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#ifndef TETRIS_COORDINATOR_H_
#define TETRIS_COORDINATOR_H_

typedef struct gcode{
	int x;
	int y;
}Coordinator;

typedef struct cpos{
	int (*complement)(Coordinator* dest, Coordinator* src);
	int (*getRight)(Coordinator* src);
	int (*getLeft)(Coordinator* src);
	int (*getBotton)(Coordinator* src);
}ClassPosition;

extern const ClassPosition Position;
#endif


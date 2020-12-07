#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
	Maze Maze1(5,5);
	for (int i = 0; i < 4; i++) {
		Maze1.makeConnection(0, i, 0, i + 1);
		if(i != 0)
			Maze1.makeConnection(1, i, 1, i + 1);
		if (i != 0 && i != 1)
			Maze1.makeConnection(2, i, 2, i + 1);
		if (i != 0 && i != 1 && i != 2)
			Maze1.makeConnection(3, i, 3, i + 1);
	}
	for (int i = 0; i < 4; i++) {
		Maze1.makeConnection(i, 0, i + 1, 0);
		Maze1.makeConnection(i, 1, i + 1, 1);
		if (i != 0)
			Maze1.makeConnection(i, 2, i + 1, 2);
		if (i != 0 && i != 1)
			Maze1.makeConnection(i, 3, i + 1, 3);
	}
	Maze1.makeConnection(3, 4, 4, 4);
	Maze1.printMaze();
}
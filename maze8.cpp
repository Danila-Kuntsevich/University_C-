#include <iostream>
#include "MazeCell.h"
using namespace std;

int main()
{
	Maze Maze1(5, 5);
	Maze1.makeConnection(0, 1, 0, 0);
	Maze1.makeConnection(0, 1, 1, 1);
	Maze1.makeConnection(1, 1, 1, 2);
	Maze1.makeConnection(1, 2, 2, 2);
	Maze1.makeConnection(2, 2, 2, 3);
	Maze1.makeConnection(2, 3, 3, 3);
	Maze1.makeConnection(3, 3, 3, 4);
	Maze1.makeConnection(4, 4, 3, 4);
	Maze1.makeConnection(1, 1, 2, 1);
	Maze1.printMaze();
}
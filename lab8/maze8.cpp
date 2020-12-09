#include <iostream>
#include "MazeCell.h"
using namespace std;

int main()
{
	Maze Maze1(5, 5);
	for (int i = 0; i < 5; i++) {
		Maze1.makeConnection(i, i, i, i + 1);
		Maze1.makeConnection(i, i + 1, i + 1, i + 1);
	}
	Maze1.printMaze();
}
#pragma once
#include "mCell.h"
class MCell;

class Maze
{
private:
	MCell* m_field = nullptr;
	int horizontal = 0;
	int vertical = 0;
public:
	Maze(int, int);
	~Maze();
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
};

#pragma once
class MCell
{
private:
	MCell();
	bool m_down = false;
	bool m_right = false;
	friend class Maze;
public:
	bool right();
	bool down();
};

class Maze
{
private:
	MCell* m_field = nullptr;
	int horizontal = 0;
	int vertical = 0;
	enum Connetcion {
		UP = 1,
		Down = 2,
		Right = 4,
		Left = 8,
	};
public:
	Maze(int, int);
	~Maze();
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
};

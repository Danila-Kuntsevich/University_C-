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

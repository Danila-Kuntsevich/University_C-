#ifndef MCELL_H
#define MCELL_H

class MCell
{
	friend class Maze;
private:
	MCell();
	bool m_down = false;
	bool m_right = false;
public:
	bool right();
	bool down();
};
#endif

#pragma once
#include "MTreeNode.h"

class MCell
{
private:
	MCell();
	bool m_down = false;
	bool m_right = false;
	friend class Maze;
public:
	MTreeNode node = *MTreeNode::beginTree(node.i(), node.j());
	bool right();
	bool down();
};

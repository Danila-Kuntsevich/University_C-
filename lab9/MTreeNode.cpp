#include "MTreeNode.h"
#include "Maze.h"

MTreeNode::MTreeNode(MTreeNode* parent) {
	m_parent = parent;
	for (int i = 0; i < 2 ; i++)
		m_children[i] = nullptr;
}

int MTreeNode::i() const {
	return m_i;
}
int MTreeNode::j() const {
	return m_j;
}

const MTreeNode* MTreeNode::parent() const {
	return m_parent;
}

const MTreeNode* MTreeNode::child(int i) const {
	return m_children[i];
}

int MTreeNode::distance() const {
	return m_distance;
}

int MTreeNode::childCount() const {
	int count = 0;
	for (int i = 0; i < 2;i++)
		if (m_children[i] != nullptr)
			count++;
	return count;
}

bool MTreeNode::addChild(int i, int j) {
	if ((m_i + 1 == i) & (m_j == j))
	{
		m_children[0] = new MTreeNode(this);
		m_children[0]->m_i = i;
		m_children[0]->m_j = j;
		m_children[0]->m_distance = this->m_distance + 1;
		return true;
	}
	if ((m_i == i) & (m_j + 1 == j))
	{
		m_children[1] = new MTreeNode(this);
		m_children[1]->m_i = i;
		m_children[1]->m_j = j;
		m_children[1]->m_distance = this->m_distance + 1;
		return true;
	}
	return false;
}

MTreeNode* MTreeNode::hasChild(int i1, int j1) {
	if (m_children[0] != nullptr && m_children[0]->i() == i1 && m_children[0]->j() == j1)
		return m_children[0];
	if (m_children[1] != nullptr && m_children[1]->i() == i1 && m_children[1]->j() == j1)
		return m_children[1];
	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i , int j) {
	MTreeNode* zero = new MTreeNode(nullptr);
	zero->m_i = i;
	zero->m_j = j;
	return zero;
}
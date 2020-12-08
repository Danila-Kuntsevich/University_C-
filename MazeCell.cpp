#include "MazeCell.h"
#include <iostream>

MCell::MCell() {

}

bool MCell::right() {
	return m_right;
}

bool MCell::down() {
	return m_down;
}

Maze::Maze(int N, int M) {
	horizontal = M;
	vertical = N;
	m_field = new MCell[horizontal * vertical];
}
Maze::~Maze() {
	delete[] m_field;
}

const MCell& Maze::cell(int i, int j) const {
	return m_field[i * vertical + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) {
	if ((i2 == i1 + 1 && j2 == j1) & m_field[i1 * vertical + j1].right()) {
		return true;
	}
	if ((i2 == i1 && j2 == j1 + 1) & m_field[i1 * vertical + j1].down()) {
		return true;
	}
	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2) {
	int m1 = i1;
	int m2 = j1;
	j1 = std::min(j1, j2);
	i1 = std::min(i1, i2);
	j2 = std::max(m2, j2);
	i2 = std::max(m1, i2);
	if ((i2 == i1 + 1) && (j2 == j1) && (i2 < vertical) && i1 >= 0) {
		m_field[i1 * vertical + j1].m_down = true;
		return true;
	}
	if ((i2 == i1) && (j2 - 1 == j1) && (j2 < horizontal) && j2 >= 0) {
		m_field[i1 * vertical + j1].m_right = true;
		return true;
	}
	return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2) {
	int m1 = i1;
	int m2 = j1;
	j1 = std::min(j1, j2);
	i1 = std::min(i1, i2);
	j2 = std::max(m2, j2);
	i2 = std::max(m1, i2);
	if ((i2 == i1 + 1) && (j2 == j1)) {
		m_field[i1 * vertical + j1].m_down = false;
		return true;
	}
	if ((i2 == i1) && (j2 == j1 + 1)) {
		m_field[i1 * vertical + j1].m_right = false;
		return true;
	}
	return false;
}

void Maze::printMaze() {
	for (int i = 0; i < (horizontal * vertical); i++) {
		if (i % horizontal == 0)
			std::cout << std::endl;
		int way = 0;
		if (m_field[i].down())
			way += Down;
		if (m_field[i].right())
			way += Right;
		if (i - 1 >= 0 && m_field[i - 1].right())
			way += Left;
		if (i - vertical >= 0 && m_field[i - vertical].down())
			way += UP;
		switch (way)
		{
		case 3:
			std::cout << char(179); //│
			break;
		case 5:
			std::cout << char(192); //└
			break;
		case 6:
			std::cout << char(218);// ┌
			break;
		case 7:
			std::cout << char(195); //├
			break;
		case 9:
			std::cout << char(217);// ┘
			break;
		case 10:
			std::cout << char(191);// ┐
			break;
		case 11:
			std::cout << char(180); // ┤
			break;
		case 12:
			std::cout << char(196);//  ─
			break;
		case 13:
			std::cout << char(193);// ┴
			break;
		case 14:
			std::cout << char(194);// ┬
			break;
		case 15:
			std::cout << char(197);// ┼
			break;
		default:
			std::cout << "0";
			break;
		}
	}
}
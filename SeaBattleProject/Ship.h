#pragma once
#include "Cell.h"

enum Direction
{
	Horizontal,
	Vertical
};

class Ship
{
	Point point;
	int size;
	Direction direction;
	int damage;
public:
	Ship(Point point, int size, Direction direction)
		: point{ point },
		size{ size },
		direction{ direction },
		damage{} {};
	Ship(int row, int col, int size, Direction direction)
		: Ship(Point(row, col), size, direction) {}
	
	Point GetPoint() { return point; }

	int& Row() { return point.row; }
	int& Col() { return point.col; }

	int Size() { return size; }
	int& Damage() { return damage; }

	Direction Direction() { return direction; }

	bool IsDead() { return damage == size; }

	bool IsPoint(Point point)
	{
		bool isPoint = false;
		int row = this->point.row;
		int col = this->point.col;

		if (point.row != row && point.col != col)
			return isPoint;

		for (int i = 0; i < size; i++)
		{
			if (point.row == row && point.col == col)
				isPoint = true;
			(direction == Direction::Horizontal) ? col++ : row++;
		}
	}

};


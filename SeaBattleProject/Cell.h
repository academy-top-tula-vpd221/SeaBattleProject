#pragma once

struct Point
{
	int row;
	int col;
	Point() : row{}, col{} {}
	Point(int row, int col) : row{ row }, col{ col } {}
};

enum CellType
{
	Empty,
	Water,
	Deck
};

class Cell
{
	Point point;
	CellType type;
	bool isShot;
public:
	Cell() : Cell(Point(0,0)) {}
	Cell(Point point)
		: point{ point },
		type{ CellType::Water },
		isShot{ false } {}
	Cell(int row, int col) 
		: Cell(Point(row, col)) {};
	
	CellType& Type() { return type; }
	bool& IsShot() { return isShot; }
};


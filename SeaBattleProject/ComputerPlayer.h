#pragma once
#include <iostream>
#include "Player.h"
class ComputerPlayer : public Player
{
public:
	ComputerPlayer() : Player("Computer") {}
	void SetFlotilla() override
	{
		flotilla.push_back(Ship(1, 1, 2, Direction::Vertical));
		flotilla.push_back(Ship(1, 4, 1, Direction::Vertical));
		flotilla.push_back(Ship(1, 7, 3, Direction::Horizontal));
		flotilla.push_back(Ship(3, 3, 3, Direction::Horizontal));
		flotilla.push_back(Ship(3, 8, 2, Direction::Vertical));
		flotilla.push_back(Ship(5, 5, 4, Direction::Vertical));
		flotilla.push_back(Ship(6, 6, 2, Direction::Horizontal));
		flotilla.push_back(Ship(7, 7, 1, Direction::Vertical));
		flotilla.push_back(Ship(8, 1, 1, Direction::Vertical));
		flotilla.push_back(Ship(9, 8, 1, Direction::Vertical));

		battleField.SetShips(flotilla);
	}

	Point SetShot() override
	{
		srand(time(nullptr));
		return Point((rand() % 10),(rand() % 10));
	}
};


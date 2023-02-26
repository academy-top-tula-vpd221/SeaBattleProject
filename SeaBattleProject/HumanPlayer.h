#pragma once
#include "Player.h"
#include "IPlayerPlatform.h"

class HumanPlayer : public Player
{
	ISetShot* shooter = nullptr;
	ISetFlotilla* commander = nullptr;
public:
	HumanPlayer(string name) : Player(name) {}

	ISetShot*& Shooter() { return shooter; }
	ISetFlotilla*& Commander() { return commander; }

	void SetFlotilla() override
	{
		//flotilla = commander->SetFlotilla();

		flotilla.push_back(Ship(1, 1, 2, Direction::Vertical));
		flotilla.push_back(Ship(1, 4, 1, Direction::Vertical));
		flotilla.push_back(Ship(1, 7, 3, Direction::Horizontal));
		flotilla.push_back(Ship(3, 3, 3, Direction::Horizontal));
		flotilla.push_back(Ship(3, 8, 2, Direction::Vertical));
		flotilla.push_back(Ship(5, 5, 4, Direction::Vertical));
		flotilla.push_back(Ship(6, 2, 2, Direction::Horizontal));
		flotilla.push_back(Ship(7, 7, 1, Direction::Vertical));
		flotilla.push_back(Ship(8, 1, 1, Direction::Vertical));
		flotilla.push_back(Ship(9, 8, 1, Direction::Vertical));


		battleField.SetShips(flotilla);
	}

	Point SetShot() override
	{
		return shooter->SetShot();
	}
};


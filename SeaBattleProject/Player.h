#pragma once
#include <string>
#include "Field.h"

using namespace std;

class Player
{
protected:
	string name;
	Field battleField;
	vector<Ship> flotilla;
public:
	Player(string name) : name{ name } {}
	
	string& Name() { return name; }
	Field& BattleField() { return battleField; }
	vector<Ship> GetFlotilla() { return flotilla; }

	ShotType GetShot(Point point)
	{
		ShotType shot;
		shot = battleField.CheckShot(point);
		battleField.SetCellShot(point);

		if (shot == ShotType::Beside)
			return shot;

		for (int i = 0; i < flotilla.size(); i++)
		{
			if (flotilla[i].IsPoint(point))
			{
				flotilla[i].Damage()++;
				if (flotilla[i].IsDead())
					return ShotType::Destroy;
				else
					return ShotType::Wound;
			}
		}
	}

	int FlotillaSize()
	{
		int count{};
		for (Ship ship : flotilla)
			if (!ship.IsDead())
				count++;
		return count;
	}

	virtual Point SetShot() = 0;

	virtual void SetFlotilla() = 0;
};


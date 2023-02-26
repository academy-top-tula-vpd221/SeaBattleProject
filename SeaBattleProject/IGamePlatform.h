#pragma once
#include "Player.h"

class IGamePlatform
{
public:
	virtual void Setup(Player* player) = 0;
	virtual void View(vector<Player*>& players) = 0;
};


#pragma once
#include "IGamePlatform.h"
#include "IPlayerPlatform.h"

class IPlatform //: public IGamePlatform, public IPlayerPlatform
{
	IGamePlatform* gamePlatform;
	IPlayerPlatform* playerPlatform;
public:
	IPlatform(IGamePlatform* gamePlatform, IPlayerPlatform* playerPlatform)
		: gamePlatform{ gamePlatform }, playerPlatform{ playerPlatform } {}

	IGamePlatform* GamePlatform() { return gamePlatform; }
	IPlayerPlatform* PlayerPlatform() { return playerPlatform; }
};


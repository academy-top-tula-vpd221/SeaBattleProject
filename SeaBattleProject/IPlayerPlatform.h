#pragma once
#include <vector>
#include "Ship.h"

class ISetFlotilla
{
public:
	virtual std::vector<Ship> SetFlotilla() = 0;
};

class ISetShot
{
public:
	virtual Point SetShot() = 0;
};

class IPlayerPlatform //: public ISetFlotilla, public ISetShot
{
	ISetFlotilla* commander;
	ISetShot* shooter;
public:
	IPlayerPlatform(ISetFlotilla* commander, ISetShot* shooter)
		: commander{ commander }, shooter{ shooter } {}
	ISetFlotilla*& Commander() { return commander; }
	ISetShot*& Shooter() { return shooter; }
};


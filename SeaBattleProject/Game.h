#pragma once
#include <vector>

#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include "ConsolePlatform.h"

using namespace std;

class Game
{
	vector<Player*> players;
	bool currentPlayer{ false };

	IPlatform* platform;

public:
	Game() : Game(nullptr) {}
	Game(IPlatform* platform) : platform{ platform } 
	{
		HumanPlayer* humanPlayer = new HumanPlayer("Player");
		humanPlayer->Shooter() = platform->PlayerPlatform()->Shooter();
		humanPlayer->Commander() = platform->PlayerPlatform()->Commander();
		players.push_back(humanPlayer);
		players.push_back(new ComputerPlayer());
	}

	void Setup()
	{
		platform->GamePlatform()->Setup(players[0]);
	}

	void View()
	{
		platform->GamePlatform()->View(players);
	}

	void SdetFlotilla()
	{
		for (int i = 0; i < players.size(); i++)
			players[i]->SetFlotilla();
	}

	void Process()
	{
		currentPlayer = false;
		ShotType shot;

		while (true)
		{
			View();
			Point pointShot = players[currentPlayer]->SetShot();
			shot = players[!currentPlayer]->GetShot(pointShot);

			// Destroy
			if (shot == ShotType::Destroy)
				if (players[!currentPlayer]->FlotillaSize() == 0)
					break;

			// Beside
			if (shot == ShotType::Beside)
				currentPlayer = !currentPlayer;
		}
	}
};


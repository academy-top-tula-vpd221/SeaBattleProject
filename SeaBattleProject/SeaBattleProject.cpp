#include <iostream>

#include "Game.h"

using namespace std;

int main()
{
    //Game* game = new Game(new ConsoleGamePlatform(Point(5, 5)));
	vector<Player*> players;

	HumanPlayer* humanPlayer = new HumanPlayer("Player");
	humanPlayer->SetFlotilla();
	players.push_back(humanPlayer);
	players.push_back(new ComputerPlayer());

	//ConsoleGamePlatform* gamePlatforme = new ConsoleGamePlatform(Point(3, 5));
	//gamePlatforme->View(players);

	PlayerSetFlotillaConsole* playerSetFlotilla = new PlayerSetFlotillaConsole(Point(3, 5));
	playerSetFlotilla->SetFlotilla();
}

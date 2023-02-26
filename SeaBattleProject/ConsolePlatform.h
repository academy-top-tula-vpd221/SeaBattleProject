#pragma once
#include <iostream>
#include <iomanip>

#include "Console.h"
#include "IPlatform.h"

class ConsoleGamePlatform : public IGamePlatform
{
	Console* console;

	const int sizeField{ 10 };
	Point beginField;
	Point endField;
public:
	ConsoleGamePlatform(Point beginField) : beginField{ beginField }
	{
		endField.row = beginField.row + sizeField;
		endField.col = beginField.col + sizeField;

		console = new Console();
	}


	void Setup(Player* player) override
	{
		cout << "Welcome to Sea Battle\nYour name: ";
		char name[50];
		cin.getline(name, 50);
		player->Name() = string(name);
	}
	void View(vector<Player*>& players) override
	{
		int diffCol{ 40 };
		console->Clear();

		Player* humanPlayer = players[0];
		Player* computerPlayer = players[1];

		console->Foreground(Colors::White, true);
		for (int i = 0; i < sizeField; i++)
		{
			console->CursorGoTo(beginField.row - 1, beginField.col + i * 2);
			cout << setw(2) << (char)(i + 'a');
			console->CursorGoTo(beginField.row + i, beginField.col - 2);
			cout << setw(2) << i + 1;

			console->CursorGoTo(beginField.row - 1, diffCol + beginField.col + i * 2);
			cout << setw(2) << (char)(i + 'a');
			console->CursorGoTo(beginField.row + i, diffCol + beginField.col - 2);
			cout << setw(2) << i + 1;
		}

		for (int row = 0; row < sizeField; row++)
			for (int col = 0; col < sizeField; col++)
			{
				if (humanPlayer->BattleField().GetCell(row, col).IsShot())
					console->Foreground(Colors::Red);
				else
					console->Foreground(Colors::Cyan);
				console->CursorGoTo(beginField.row + row, beginField.col + col * 2);
				cout << string(2, WATER);

				if (computerPlayer->BattleField().GetCell(row, col).IsShot())
				{
					console->Foreground(Colors::Red);
					console->CursorGoTo(beginField.row + row, diffCol + beginField.col + col * 2);
					if (computerPlayer->BattleField().GetCell(row, col).Type() == CellType::Water)
						cout << string(2, WATER);
					else
						cout << string(2, DESK);
				}
				else
				{
					console->Foreground(Colors::Cyan);
					console->CursorGoTo(beginField.row + row, diffCol + beginField.col + col * 2);
					cout << string(2, WATER);
				}
			}

		for (Ship ship : humanPlayer->GetFlotilla())
		{
			int row = ship.Row();
			int col = ship.Col();

			for (int s = 0; s < ship.Size(); s++)
			{
				console->CursorGoTo(beginField.row + row, beginField.col + col * 2);
				if(humanPlayer->BattleField().GetCell(row, col).IsShot())
					console->Foreground(Colors::Red);
				else
					console->Foreground(Colors::Yellow);
				cout << string(2, DESK);
				(ship.Direction() == Direction::Horizontal) ? col++ : row++;
			}
		}
	}
};

class PlayerSetFlotillaConsole : public ISetFlotilla
{
	Console* console;

	const int sizeField{ 10 };
	Point beginField;
	Point endField;

	vector<Ship> flotilla;
public:
	PlayerSetFlotillaConsole(Point beginField) : beginField{ beginField }
	{
		endField.row = beginField.row + sizeField;
		endField.col = beginField.col + sizeField;

		console = new Console();
	}


	void View(int shipSize, int shipCount)
	{
		console->Clear();
		console->Foreground(Colors::White, true);
		for (int i = 0; i < sizeField; i++)
		{
			console->CursorGoTo(beginField.row - 1, beginField.col + i * 2);
			cout << setw(2) << (char)(i + 'a');
			console->CursorGoTo(beginField.row + i, beginField.col - 2);
			cout << setw(2) << i + 1;
		}

		console->Foreground(Colors::Cyan);
		for(int row = 0; row < sizeField; row++)
			for (int col = 0; col < sizeField; col++)
			{
				console->CursorGoTo(beginField.row + row, beginField.col + col * 2);
				cout << string(2, WATER);
			}
	}

	Ship SetShip(int shipSize)
	{
		return Ship(0, 0, 0, Direction::Horizontal);
	}

	std::vector<Ship> SetFlotilla() override
	{
		for (int shipSize = 4; shipSize > 0; shipSize--)
		{
			for (int shipCount = shipSize; shipCount < 5; shipCount++)
			{
				View(shipSize, shipCount);
				Ship ship = SetShip(shipSize);
				flotilla.push_back(ship);
			}
		}

		return flotilla;
	}
};


class ConsolePlayerPlatforme : public IPlayerPlatform
{

};


class ConsolePlatform : public IPlatform
{
public:

};


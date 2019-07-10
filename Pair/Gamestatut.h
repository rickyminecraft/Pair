#pragma once

#include <bitset>

#include "Game_stats.h"

class Gamestatut
{
public:
	Gamestatut();
	~Gamestatut();

	void Set(const Game_Status Name);

	const bool Statut(const Game_Status Name) const;

private:

	std::bitset<10> Stats = 0x0;
};


#pragma once

#include <bitset>

#include "Game_stats.h"

class Gamestatut
{
public:
	Gamestatut();
	~Gamestatut();

	static void Set(const Game_Status Name);
	static void Unset(const Game_Status Name);

	const bool Statut(const Game_Status Name) const;

private:

	static std::bitset<10> Stats;
};


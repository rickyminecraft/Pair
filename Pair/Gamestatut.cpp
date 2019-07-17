#include "Gamestatut.h"

std::bitset<10> Gamestatut::Stats = 0x0;

Gamestatut::Gamestatut()
{
}


Gamestatut::~Gamestatut()
{
}

void Gamestatut::Set(const Game_Status Name)
{
	Stats[Name] = true;
}

void Gamestatut::Unset(const Game_Status Name)
{
	Stats[Name] = false;
}

const bool Gamestatut::Statut(const Game_Status Name) const
{
	return Stats[Name];
}

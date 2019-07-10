#include "Gamestatut.h"



Gamestatut::Gamestatut()
{
}


Gamestatut::~Gamestatut()
{
}

void Gamestatut::Set(const Game_Status Name)
{
	Stats[Name] = ~Stats[Name];
}

const bool Gamestatut::Statut(const Game_Status Name) const
{
	return Stats[Name];
}

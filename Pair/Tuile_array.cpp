#include "Tuile_array.h"



Tuile_array::Tuile_array()
{
}


Tuile_array::~Tuile_array()
{
}

const short Tuile_array::Get(const short Numero)
{
	return Tiles[Numero].first;
}

const bool Tuile_array::Removed(const short Numero)
{
	if (Numero > Min || Numero < Max)
	{
		return Tiles[Numero].second;
	}
	return false;
}

void Tuile_array::Remove(const short Numero)
{
	if (Numero > Min || Numero < Max)
	{
		Tiles[Numero].second = true;
	}
}

const bool Tuile_array::Is_all_removed() const
{
	bool Done = true;
	for (short Boucle = Min; Boucle < Max; ++Boucle)
	{
		if (!Tiles[Boucle].second)
		{
			Done = false;
		}
	}
	return Done;
}

void Tuile_array::Reset()
{
	if (Tiles.size() < 48)
	{
		Tiles.resize(48);
	}
	for (short Boucle = Min; Boucle < Max / 2; ++Boucle)
	{
		Tiles[Boucle].first = Boucle;
		Tiles[Boucle].second = false;
		Tiles[Boucle + Max / 2].first = Boucle;
		Tiles[Boucle + Max / 2].second = false;
	}
	Shuffle();
}

void Tuile_array::Shuffle()
{
	std::random_device Rdevice;
	std::default_random_engine Engine(Rdevice());
	std::shuffle(Tiles.begin(), Tiles.end(), Engine);
}

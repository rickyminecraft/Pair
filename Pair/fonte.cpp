#include "fonte.h"



fonte::fonte()
{
	for (auto Nom : Fonte_name)
	{
		Fontes.push_back(Fichier.Get_File<sf::Font>(Nom + ".ttf"));
	}
}


fonte::~fonte()
{
}

sf::Font * fonte::Get(const sf::String Sound_name)
{
	short Numero = 0;
	for (auto Name : Fonds_name)
	{
		if (Sound_name == Name)
		{
			return &Fontes[Numero];
		}
		++Numero;
	}
	return nullptr;
}

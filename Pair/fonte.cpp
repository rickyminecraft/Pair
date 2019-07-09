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

sf::Font * fonte::Get(sf::String Sound_name)
{
	return &Fontes[0];
}

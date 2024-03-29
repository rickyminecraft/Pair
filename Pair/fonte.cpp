#include "fonte.h"



fonte::fonte()
{
	Fontes.push_back(Fichier.Get_File<sf::Font>(Fonte_name + ".ttf"));
}


fonte::~fonte()
{
}

sf::Font * fonte::Get(const sf::String Fonte_name)
{
	short Numero = 0;
	for (auto Name : Fonds_name)
	{
		if (Fonte_name == Name)
		{
			return &Fontes[Numero];
		}
		++Numero;
	}
	return nullptr;
}

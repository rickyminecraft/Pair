#include "texture.h"



texture::texture()
{
	for (auto Nom : Tuiles_name)
	{
		Tuiles.push_back(Fichier.Get_File<sf::Texture>(Nom + ".png"));
	}

	for (auto Nom : Fonds_name)
	{
		Fonds.push_back(Fichier.Get_File<sf::Texture>(Nom + ".jpg"));
	}

	for (auto Nom : Divers_name)
	{
		Divers.push_back(Fichier.Get_File<sf::Texture>(Nom + ".png"));
	}
}


texture::~texture()
{
}

sf::Texture * texture::Get(sf::String Sound_name)
{
	short Numero = 0;
	for (auto Name : Fonds_name)
	{
		if (Sound_name == Name)
		{
			return &Fonds[Numero];
		}
		++Numero;
	}
	Numero = 0;
	for (auto Name : Tuiles_name)
	{
		if (Sound_name == Name)
		{
			return &Fonds[Numero];
		}
		++Numero;
	}
	Numero = 0;
	for (auto Name : Divers_name)
	{
		if (Sound_name == Name)
		{
			return &Fonds[Numero];
		}
		++Numero;
	}
	return nullptr;
}

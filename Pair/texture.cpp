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
	Hover.create(100, 100);
	sf::Image * Hover_image = new sf::Image();
	Hover_image->create(100, 100, sf::Color::Red);
	Hover.loadFromImage(*Hover_image);
	delete Hover_image;
}


texture::~texture()
{
}

sf::Texture * texture::Get(const sf::String Texture_name)
{
	short Numero = 0;
	for (auto Name : Fonds_name)
	{
		if (Texture_name == Name)
		{
			return &Fonds[Numero];
		}
		++Numero;
	}
	Numero = 0;
	for (auto Name : Tuiles_name)
	{
		if (Texture_name == Name)
		{
			return &Tuiles[Numero];
		}
		++Numero;
	}
	Numero = 0;
	for (auto Name : Divers_name)
	{
		if (Texture_name == Name)
		{
			return &Divers[Numero];
		}
		++Numero;
	}
	if (Texture_name == Hover_name)
	{
		return &Hover;
	}
	return nullptr;
}

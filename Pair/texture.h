#pragma once

#include <SFML/Graphics.hpp>

#include "fichier.h"
#include "assets.h"

class texture
{
public:
	texture();
	~texture();

	sf::Texture * Get(const sf::String Sound_name);

private:
	fichier Fichier;

	std::vector<sf::Texture> Tuiles;
	std::vector<sf::Texture> Fonds;
	std::vector<sf::Texture> Divers;
};


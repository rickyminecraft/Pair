#pragma once

#include <SFML/Graphics.hpp>

#include "fichier.h"
#include "assets.h"

class fonte
{
public:
	fonte();
	~fonte();

	sf::Font * Get(const sf::String Fonte_name);

private:
	fichier Fichier;

	std::vector<sf::Font> Fontes;
};


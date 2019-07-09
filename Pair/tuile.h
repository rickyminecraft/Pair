#pragma once

#include <SFML/Graphics.hpp>

class tuile
{
public:
	tuile();
	explicit tuile(sf::Vector2f Position, sf::Vector2f Taille);
	~tuile();

private:

	sf::RectangleShape Tuile;

};


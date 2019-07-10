#pragma once

#include <SFML/Graphics.hpp>

class tuile
{
public:
	tuile();
	~tuile();

	void Setposition(const sf::Vector2f Position);
	void Setsize(const sf::Vector2f Size);
	void Setname(sf::String Name);

	const std::pair<sf::RectangleShape, sf::String> * GetTuile() const;

private:

	std::pair<sf::RectangleShape, sf::String> Tuile;

};


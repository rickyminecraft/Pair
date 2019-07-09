#pragma once

#include <SFML/Graphics.hpp>

class tuile
{
public:
	tuile();
	~tuile();

	void Setposition(const sf::Vector2f Position);
	void SetSize(const sf::Vector2f Size);
	void SetTexture(const sf::Texture * Texture);

	const sf::RectangleShape GetTuile() const;

private:

	sf::RectangleShape Tuile;

};


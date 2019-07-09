#pragma once

#include <random>

#include <SFML/Graphics.hpp>

class pixel
{
public:
	pixel();
	explicit pixel(const sf::Vector2f Position, const sf::Color Couleur);
	~pixel();

	const bool Alive() const;
	void Update();
	const sf::Vertex GetPixel() const;

private:
	void Setspeed();
	void Setdirection();
	void Setlive();

	short Vie;
	float Vitesse;
	
	sf::Vertex vPixel;
	sf::Vector2f Direction;
};


#include "tuile.h"



tuile::tuile()
{
}


tuile::~tuile()
{
}

void tuile::Setposition(const sf::Vector2f Position)
{
	Tuile.first.setPosition(Position);
}

void tuile::Setsize(const sf::Vector2f Size)
{
	Tuile.first.setSize(Size);
}

void tuile::Setname(const sf::String Name)
{
	Tuile.second = Name;
}

const std::pair<sf::RectangleShape, sf::String> * tuile::GetTuile() const
{
	return &Tuile;
}

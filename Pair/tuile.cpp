#include "tuile.h"



tuile::tuile()
{
}


tuile::~tuile()
{
}

void tuile::Setposition(const sf::Vector2f Position)
{
	Tuile.setPosition(Position);
}

void tuile::SetSize(const sf::Vector2f Size)
{
	Tuile.setSize(Size);
}

void tuile::SetTexture(const sf::Texture * Texture)
{
	Tuile.setTexture(Texture);
}

const sf::RectangleShape tuile::GetTuile() const
{
	return Tuile;
}

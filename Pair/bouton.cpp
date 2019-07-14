#include "bouton.h"

short bouton::IDcourant = 0;

bouton::bouton()
{
}


bouton::~bouton()
{
}

void bouton::Select()
{
	bSelection = true;
}

void bouton::Deselect()
{
	bSelection = false;
}

const bool bouton::Is_inside(const sf::Vector2f Position) const
{
	//si on est dedans a l'horizontal
	if (Position.x >= GetTuile()->first.getPosition().x && Position.x <= GetTuile()->first.getPosition().x + GetTuile()->first.getSize().x)
	{
		//est on dedans a la vertical ?
		if (Position.y >= GetTuile()->first.getPosition().y && Position.y <= GetTuile()->first.getPosition().y + GetTuile()->first.getSize().y)
		{
			return true;
		}
	}
	return false;
}

const bool bouton::Is_select() const
{
	return bSelection;
}

const short bouton::GetID() const
{
	return ID;
}

void bouton::SetID()
{
	ID = IDcourant;
	++IDcourant;
}

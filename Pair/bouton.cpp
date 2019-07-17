#include "bouton.h"



bouton::bouton()
{
}


bouton::~bouton()
{
}

void bouton::Hover(void Function())
{
	Hoverfunction = Function;
}

void bouton::Click(void Function())
{
	Clickfunction = Function;
}

void bouton::Update(sf::Event Event)
{
	bool Click = false, Move = false;
	switch (Event.type)
	{

	case sf::Event::MouseButtonPressed:
		Mouseposition = sf::Vector2f((float)Event.mouseButton.x, (float)Event.mouseButton.y);
		Click = true;
		break;
	case sf::Event::MouseMoved:
		Mouseposition = sf::Vector2f((float)Event.mouseMove.x, (float)Event.mouseMove.y);
		Move = true;
		break;
	}

	if (Click)
	{
		if (Ishover())
		{
			if (Clickfunction != nullptr)
			Clickfunction();
		}
	}

	if (Move)
	{
		if (Ishover())
		{
			if (Hoverfunction != nullptr)
			Hoverfunction();
		}
	}
}

const bool bouton::Ishover() const
{
	//si on est dedans a l'horizontal
	if (Mouseposition.x >= GetTuile()->first.getPosition().x && Mouseposition.x <= GetTuile()->first.getPosition().x + GetTuile()->first.getSize().x)
	{
		//est on dedans a la vertical ?
		if (Mouseposition.y >= GetTuile()->first.getPosition().y && Mouseposition.y <= GetTuile()->first.getPosition().y + GetTuile()->first.getSize().y)
		{
			return true;
		}
	}
	return false;
}

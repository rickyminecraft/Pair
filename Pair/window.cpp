#include "window.h"



window::window()
{
}


window::~window()
{
	for (auto Win : Windows)
	{
		delete(Win.first);
	}
}

void window::CreateWindow(const int size_x, const int size_y, const sf::String Nom, const short Style, const bool rebuild)
{
	if (rebuild)
	{
		for (auto Name : Windows)
		{
			if (Name.second == Nom)
			{
				Name.first->create(sf::VideoMode(size_x, size_y), Nom, Style);
				return;
			}
		}
	}
	sf::RenderWindow* Window = new sf::RenderWindow(sf::VideoMode(size_x, size_y), Nom, Style);
	Windows.push_back(std::make_pair(Window, Nom));
}

const bool window::isOpen(const sf::String Nom) const
{
	for (auto Name : Windows)
	{
		if (Name.second == Nom)
		{
			return Name.first->isOpen();
		}
	}
	return false;
}

void window::Close(const sf::String Nom) const
{
	for (auto Name : Windows)
	{
		if (Name.second == Nom)
		{
			return Name.first->close();
		}
	}
}

const sf::RenderWindow * window::GetWindow(const sf::String Nom) const
{
	for (auto Name : Windows)
	{
		if (Name.second == Nom)
		{
			return Name.first;
		}
	}
	return nullptr;
}

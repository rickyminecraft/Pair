#pragma once

#include <SFML/Graphics.hpp>

class window
{
public:
	window();
	~window();

	void CreateWindow(const int size_x, const int size_y, const sf::String Nom, const short Style = sf::Style::Close, bool rebuild = false);
	const bool isOpen(const sf::String Nom);
	void Close(const sf::String Nom);
	sf::RenderWindow * GetWindow(const sf::String Nom);

private:

	std::vector<std::pair<sf::RenderWindow*, sf::String>> Windows;
};


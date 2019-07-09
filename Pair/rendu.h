#pragma once

#include <chrono>

#include <SFML/Graphics.hpp>

#include "window.h"
#include "audio.h"
#include "texture.h"
#include "fonte.h"

class rendu: private window
{
public:
	rendu();
	~rendu();

	void Playsound(const sf::String Name);
	void Playmusic(const sf::String Name);

	void Showtry(short Nombre);
	void ShowScore(short Score);

	void Drawfond();
	void Drawtuiles();
	void Drawmaintuiles();

	void Affiche();

private:
	bool Score = false, Try = false;


	sf::RenderWindow * Window;

	std::vector<sf::RectangleShape> Tuiles;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;
};


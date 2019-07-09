#pragma once

#include <chrono>

#include <SFML/Graphics.hpp>

#include "audio.h"
#include "texture.h"
#include "texte.h"
#include "pixel.h"

class rendu
{
public:
	rendu();
	~rendu();

	void Playsound(const sf::String Name);
	void Playmusic(const sf::String Name);

	void Showtry(const short Nombre);
	void ShowScore(const short Score);

	//une tuile peut être n'import quoi, bouton, fond, tuile du jeu, ...
	void Drawtuile(sf::RectangleShape Tuile, short Layer);
	//rend tout sur la fenetre fournit
	void Affiche(sf::RenderWindow * Window);

private:
	bool Score = false, Try = false;

	std::vector<sf::RectangleShape> Tuiles;

	//vector of particules
	//std::vector< Pixel> Pixels;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;
};


#pragma once

#include <chrono>

#include <SFML/Graphics.hpp>

#include "audio.h"
#include "texture.h"
#include "texte.h"
#include "pixel.h"
#include "bouton.h"

class rendu: private texture, private texte, private audio
{
public:
	rendu();
	~rendu();

	void Playsound(const sf::String Name);
	void Playmusic(const sf::String Name, const bool Mute = false);

	void Drawselection() const;
	void Hideselection() const;
	void reset();

	//une tuile peut être n'import quoi, bouton, fond, tuile du jeu, ...
	void Addtuile(bouton * Tuile, const short Layer = 0);
	//rend tout sur la fenetre fournit
	void Affiche(sf::RenderWindow * Window);

private:
	void Showtry(const short Nombre);
	void ShowScore(const short Score);

	bool Score = false, Try = false;

	std::vector<bouton*> Tuiles;
	std::vector<short> Layers;

	//vector of particules
	//std::vector< Pixel> Pixels;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;
};


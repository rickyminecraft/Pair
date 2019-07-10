#pragma once

//#include <algorithm>

#include <SFML/Audio.hpp>

#include "fichier.h"
#include "assets.h"

class audio
{
public:
	audio();
	~audio();

	//on recupere un pointeur sur un son
	sf::Sound * Get(const sf::String Sound_name);

private:
	fichier Fichier;

	std::vector<sf::SoundBuffer> Buffers;
	std::vector<sf::Sound> Sounds;
};


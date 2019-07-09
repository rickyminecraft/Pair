#pragma once

#include <chrono>

#include "fichier.h"
#include "rendu.h"
#include "bouton.h"
#include "window.h"

class pair
{
public:
	pair();
	~pair();

	//boucle principal
	bool Run();

private:
	void Ready_game();

	//files instance
	std::unique_ptr <fichier> Fichiers;
	//files instance
	std::unique_ptr <window> Windows;
	//files instance
	std::unique_ptr <bouton> Boutons;
	//renderer instance
	std::unique_ptr <rendu> Renderers;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;
	const sf::String Window_name = "Paires";
};


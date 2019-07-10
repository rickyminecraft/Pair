#pragma once

#include <chrono>

#include <SFML/System/Vector2.hpp>

#include "assets.h"
#include "Gamestatut.h"
#include "fichier.h"
#include "rendu.h"
#include "bouton.h"
#include "window.h"

class pair: private Gamestatut
{
public:
	pair();
	~pair();

	//boucle principal
	bool Run();

private:
	void Send_background();
	void Send_tiles();
	void Send_main_tiles();

	void Main_window_logic();
	void Play_window_logic();

	void Ready_game();

	//fichier instance
	std::unique_ptr <fichier> Fichiers;
	//window instance
	std::unique_ptr <window> Windows;
	//rendu instance
	std::unique_ptr <rendu> Renderers;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;

	std::vector<bouton> Bouton;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;
	const sf::String Window_name = "Paires";

	sf::Vector2f Mouseposition;
	sf::Keyboard::Key Touche;
};


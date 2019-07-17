#pragma once

#include <chrono>

#include <SFML/System/Vector2.hpp>

#include "assets.h"
#include "Gamestatut.h"
#include "Tuile_array.h"
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

	void Ready_game();
	void Ready_tuiles_array();

	static void Exitclick();
	static void Playclick();
	static void ExitHover();
	static void Playhover();

	//fichier instance
	std::unique_ptr <fichier> Fichiers;
	//window instance
	std::unique_ptr <window> Windows;
	//rendu instance
	static std::unique_ptr <rendu> Renderers;

	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;

	static std::vector<bouton> Bouton;
	Tuile_array Tuiles_array;

	//resolution
	const int Width = 1024, Height = 768;
	const sf::String Window_name = "Paires";

	sf::Vector2f Mouseposition;
	sf::Keyboard::Key Touche;
};
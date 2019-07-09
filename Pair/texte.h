#pragma once

#include "fonte.h"
#include "assets.h"

class texte : private fonte
{
public:
	texte();
	~texte();

	sf::Text * Get_try() const;
	sf::Text * Get_score() const;

private:

	//sf::String Try_texte = "Nombre d'essai: ";
	//sf::String Score_texte = "SCORE : ";
	mutable sf::Text Try, Score;
};


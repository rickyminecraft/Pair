#include "texte.h"



texte::texte()
{
	Try.setFont(*Get(Fonte_name));
	Try.setOutlineColor(sf::Color::Black);
	Try.setFillColor(sf::Color::Red);
	Try.setStyle(sf::Text::Regular);
	Try.setOutlineThickness(1.0f);
	Try.setCharacterSize(20);
	Try.setPosition(sf::Vector2f(30.0f, 30.0f));

	Score.setFont(*Get(Fonte_name));
	Score.setOutlineColor(sf::Color::Black);
	Score.setFillColor(sf::Color::Transparent);
	Score.setStyle(sf::Text::Regular);
	Score.setOutlineThickness(2.0f);
	Score.setCharacterSize(150);
	Score.setPosition(sf::Vector2f(80.0f, 300.0f));
}


texte::~texte()
{
}

sf::Text * texte::Get_try() const
{
	return &Try;
}

sf::Text * texte::Get_score() const
{
	return &Score;
}

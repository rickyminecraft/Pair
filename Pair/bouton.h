#pragma once

#include "tuile.h"

class bouton : public tuile
{
public:
	bouton();
	~bouton();

	void Hover(void Function());
	void Click(void Function());

	void Update(sf::Event Event);

private:
	const bool Ishover() const;

	sf::Vector2f Mouseposition;

	void (*Hoverfunction)();
	void (*Clickfunction)();
};


#pragma once

#include "tuile.h"

class bouton : public tuile
{
public:
	bouton();
	~bouton();

	void Select();
	void Deselect();

	const bool Is_inside(const sf::Vector2f Position) const;
	const bool Is_select() const;

	const short GetID() const;
	void SetID();

private:
	
	bool bSelection = false;

	static short IDcourant;
	short ID = -1;
};


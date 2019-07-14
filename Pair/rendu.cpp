#include "rendu.h"



rendu::rendu()
{
	Time = Horloge.now();
}


rendu::~rendu()
{
}

void rendu::Drawtuile(bouton * Tuile, short Layer)
{
	for (auto test : Tuiles)
	{
		if (test.GetID() == Tuile->GetID())
		{
			return;
		}
	}
	Tuiles.push_back(*Tuile);
	Layers.push_back(Layer);
}

void rendu::Affiche(sf::RenderWindow * Window)
{
	auto Actual_time = Horloge.now();
	if (Actual_time - Time >= std::chrono::microseconds(20000))//11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
	{
		if (Window->isOpen())
		{
			Window->clear();

			short Actual_layer = 0, Vectorposition = 0;
			while (Tuiles.size() > 0)
			{
				if (Vectorposition >= Tuiles.size())
				{
					Vectorposition = 0;
					++Actual_layer;
				}
				if (Layers[Vectorposition] == Actual_layer)
				{
					std::pair<sf::RectangleShape, sf::String> Sprite;
					Sprite = *Tuiles[Vectorposition].GetTuile();
					Sprite.first.setTexture(texture::Get(Sprite.second));
					Window->draw(Sprite.first);
					Tuiles.erase(Tuiles.cbegin() + Vectorposition);
					Layers.erase(Layers.cbegin() + Vectorposition);
				}

				++Vectorposition;
			}

			Window->display();
		}
		
		Time = Horloge.now();
	}
}

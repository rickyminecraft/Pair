#include "rendu.h"



rendu::rendu()
{

	Time = Horloge.now();
}


rendu::~rendu()
{
}

void rendu::Drawtuile(std::pair<sf::RectangleShape, sf::String> Tuile, short Layer)
{
	Tuiles.push_back(Tuile);
	Layers.push_back(Layer);
}

void rendu::Affiche(sf::RenderWindow * Window)
{
	auto Actual_time = Horloge.now();
	if (Actual_time - Time >= std::chrono::microseconds(20000))//11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
	{
		Window->clear();

		short Actual_layer = 0, Vectorposition = 0;
		while (Tuiles.size() > 0)
		{
			if (Vectorposition == Tuiles.size())
			{
				Vectorposition = 0;
				++Actual_layer;
			}
			if (Layers[Vectorposition] == Actual_layer)
			{
				//a ajouter quand j'aurais fait la lisaison avec les textures et autres
				//Tuiles[Vectorposition].first.setTexture(Tuiles[Vectorposition]);
				Window->draw(Tuiles[Vectorposition].first);
				Tuiles.erase(Tuiles.cbegin() + Vectorposition);
				Layers.erase(Layers.cbegin() + Vectorposition);
			}

			++Vectorposition;
		}

		Window->display();
		Time = Horloge.now();
	}
}

#include "rendu.h"



rendu::rendu()
{
	Time = Horloge.now();
}


rendu::~rendu()
{
}

void rendu::Addtuile(bouton * Tuile, short Layer)
{
	Tuiles.push_back(Tuile);
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

			if (Tuiles.size() > 0)
			{
				for (short Layer = 0; Layer < 4; Layer++)
				{
					for (short Vectorposition = 0; Vectorposition < Tuiles.size(); ++Vectorposition)
					{
						if (Layers[Vectorposition] == Layer)
						{
							std::pair<sf::RectangleShape, sf::String> Sprite;
							Sprite = *Tuiles[Vectorposition]->GetTuile();
							Sprite.first.setTexture(texture::Get(Sprite.second));
							Window->draw(Sprite.first);
							//Tuiles.erase(Tuiles.cbegin() + Vectorposition);
							//Layers.erase(Layers.cbegin() + Vectorposition);
						}
					}
					
				}
			}

			Window->display();
		}
		
		Time = Horloge.now();
	}
}

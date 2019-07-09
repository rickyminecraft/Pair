#include "pair.h"



pair::pair()
{
	Fichiers = std::make_unique<fichier>();
	Windows = std::make_unique<window>();
	Boutons = std::make_unique<bouton>();
	Renderers = std::make_unique<rendu>();

	Ready_game();
}


pair::~pair()
{
}

bool pair::Run()
{
	sf::Event event;

	while (Windows->isOpen(Window_name))
	{
		auto Actual_time = Horloge.now();
		if (Actual_time - Time >= std::chrono::microseconds(80000))//11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
		{



		}
		//Renderers->Affiche(Windows->GetWindow(Window_name));
	}
	
	return true;
}

void pair::Ready_game()
{
	Windows->CreateWindow(Width, Height, Window_name);



}

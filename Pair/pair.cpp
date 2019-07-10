#include "pair.h"



pair::pair()
{
	Fichiers = std::make_unique<fichier>();
	Windows = std::make_unique<window>();
	Renderers = std::make_unique<rendu>();

	Ready_game();
}


pair::~pair()
{
}

bool pair::Run()
{
	sf::Event Events;

	while (Windows->isOpen(Window_name))
	{
		auto Actual_time = Horloge.now();
		if (Actual_time - Time >= std::chrono::microseconds(100000))//11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
		{
			Windows->GetWindow(Window_name)->pollEvent(Events);
			switch (Events.type)
			{
			case sf::Event::Closed:
				Set(Game_Status::Quit);
				break;
			case sf::Event::MouseButtonPressed:
				Mouseposition = sf::Vector2f((float)Events.mouseButton.x, (float)Events.mouseButton.y);
				Set(Game_Status::Mouse_click);
				break;
			//case sf::Event::MouseButtonReleased:
			//	Mouseposition = sf::Vector2f((float)Events.mouseButton.x, (float)Events.mouseButton.y);
			//	Set(Game_Status::Mouse_unclick);
			//	break;
			case sf::Event::MouseMoved:
				Mouseposition = sf::Vector2f((float)Events.mouseMove.x, (float)Events.mouseMove.y);
				Set(Game_Status::Mouse_moved);
				break;
			case sf::Event::KeyPressed:
				Touche = Events.key.code;
				Set(Game_Status::Button_click);
				break;

			}

			if (Statut(Game_Status::Button_click))
			{
				if (Touche == sf::Keyboard::M)
				{
					Set(Game_Status::Mute);
				}
				if (Touche == sf::Keyboard::Escape)
				{
					if (!Statut(Game_Status::Main_window))
					{
						Set(Game_Status::Main_window);
					}
				}
				Set(Game_Status::Button_click);
			}

			if (Statut(Game_Status::Mouse_moved))
			{
				if (Statut(Game_Status::Main_window))
				{
					Main_window_logic();
				}
				else
				{
					Play_window_logic();
				}
				Set(Game_Status::Mouse_moved);
			}

			if (Statut(Game_Status::Mouse_click))
			{
				if (Statut(Game_Status::Main_window))
				{
					Main_window_logic();
				}
				else
				{
					Play_window_logic();
				}
				Set(Game_Status::Mouse_click);
			}

			if (Statut(Game_Status::Quit))
			{
				Windows->Close(Window_name);
			}

			Time = Horloge.now();
		}

		if (Statut(Game_Status::Main_window))
		{

		}
		else
		{

		}
		Renderers->Affiche(Windows->GetWindow(Window_name));
	}
	
	return true;
}

void pair::Send_background()
{
	Bouton[0].Setname(Fonds_name[0]);
	Renderers->Drawtuile(*Bouton[0].GetTuile(), 0);
}

void pair::Send_tiles()
{

}

void pair::Send_main_tiles()
{
	Renderers->Drawtuile(*Bouton[2].GetTuile(), 2);
	Renderers->Drawtuile(*Bouton[3].GetTuile(), 2);
}

void pair::Main_window_logic()
{

}

void pair::Play_window_logic()
{

}

void pair::Ready_game()
{
	Windows->CreateWindow(Width, Height, Window_name);

	bouton Nouveau;
	//on met le fond
	Nouveau.Setposition(sf::Vector2f(0.0f, 0.0f));
	Nouveau.Setsize(sf::Vector2f(Width, Height));
	Bouton.push_back(Nouveau);
	//puis toutes les textures de base
	Nouveau.Setname(Divers_name[0]);//selection
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Bouton.push_back(Nouveau);

	Nouveau.Setname(Divers_name[1]);//back
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Bouton.push_back(Nouveau);

	Nouveau.Setname(Divers_name[2]);//exit
	Nouveau.Setposition(sf::Vector2f(524.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Bouton.push_back(Nouveau);

	Nouveau.Setname(Divers_name[3]);//play
	Nouveau.Setposition(sf::Vector2f(400.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Bouton.push_back(Nouveau);
	//enfin on prepare les position et taille de toutes les tuiles du jeu
	for (short y = 0; y < 6; ++y)
	{
		for (short x = 0; x < 8; ++x)
		{
			Nouveau.Setposition(sf::Vector2f((float)(x * 128), (float)(y * 128)));
			Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
			Bouton.push_back(Nouveau);
		}
	}

	Set(Game_Status::Main_window);
}

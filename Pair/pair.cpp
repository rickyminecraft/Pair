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
					Set(Game_Status::Play);
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

		if (Statut(Game_Status::Main_window))
		{
			Send_main_tiles();
		}
		else
		{
			Send_background();
			Send_tiles();
		}

		Renderers->Affiche(Windows->GetWindow(Window_name));
	}
	
	return true;
}

void pair::Send_background()
{
	Bouton[0].Setname(Fonds_name[0]);
	Renderers->Drawtuile(&Bouton[0], 0);
}

void pair::Send_tiles()
{
	for (short y = 0; y < 6; ++y)
	{
		for (short x = 0; x < 8; ++x)
		{
			Renderers->Drawtuile(&Bouton[(x + (8 * y)) + 6]);
		}
	}
}

void pair::Send_main_tiles()
{
	Renderers->Drawtuile(&Bouton[3], 2);
	Renderers->Drawtuile(&Bouton[4], 2);
}

void pair::Main_window_logic()
{
	if (Statut(Game_Status::Mouse_click))
	{
		if (Bouton[3].Is_inside(Mouseposition))
		{
			Set(Game_Status::Quit);
		}
		if (Bouton[4].Is_inside(Mouseposition))
		{
			Set(Game_Status::Main_window);
			Set(Game_Status::Play);
		}
		Set(Game_Status::Mouse_click);
	}

	if (Statut(Game_Status::Mouse_moved))
	{
		if (Bouton[3].Is_inside(Mouseposition))
		{
			Bouton[5].Setposition(sf::Vector2f(524.0f, 334.0f));
			Renderers->Drawtuile(&Bouton[5], 1);
		}
		if (Bouton[4].Is_inside(Mouseposition))
		{
			Bouton[5].Setposition(sf::Vector2f(400.0f, 334.0f));
			Renderers->Drawtuile(&Bouton[5], 1);
		}
	}
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
	Nouveau.Setsize(sf::Vector2f((float)Width, (float)Height));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //0
	//puis toutes les textures de base
	Nouveau.Setname(Divers_name[0]);//selection
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //1

	Nouveau.Setname(Divers_name[1]);//back
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //2

	Nouveau.Setname(Divers_name[2]);//exit
	Nouveau.Setposition(sf::Vector2f(524.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //3

	Nouveau.Setname(Divers_name[3]);//play
	Nouveau.Setposition(sf::Vector2f(400.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //4

	Nouveau.Setname(Hover_name);//hover
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Nouveau.SetID();
	Bouton.push_back(Nouveau); //5

	//enfin on prepare les position et taille de toutes les tuiles du jeu
	for (short y = 0; y < 6; ++y)
	{
		for (short x = 0; x < 8; ++x)
		{
			Nouveau.Setposition(sf::Vector2f((float)(x * 128), (float)(y * 128)));
			Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
			Nouveau.SetID();
			Bouton.push_back(Nouveau);
		}
	}

	Ready_tuiles_array();
	Set(Game_Status::Main_window);
}

void pair::Ready_tuiles_array()
{
	Tuiles_array.Reset();
	for (short Boucle = 0; Boucle < 48; ++Boucle)
	{
		Bouton[Boucle + 6].Setname(Tuiles_name[Tuiles_array.Get(Boucle)]);
	}
}

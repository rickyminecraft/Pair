#include "pair.h"

std::vector<bouton> pair::Bouton;
std::unique_ptr <rendu> pair::Renderers;

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
		case sf::Event::KeyPressed:
			Touche = Events.key.code;
			Set(Game_Status::Button_click);
			break;
		}

		if (Statut(Game_Status::Button_click))
		{
			if (Touche == sf::Keyboard::M)
			{
				//Set(Game_Status::Mute);
			}
			if (Touche == sf::Keyboard::Escape)
			{
				if (!Statut(Game_Status::Main_window))
				{
					Set(Game_Status::Main_window);
					Unset(Game_Status::Play);
				}
			}
			Set(Game_Status::Button_click);
		}

		if (Statut(Game_Status::Main_window))
		{
			//trouver un systeme comme pour une application
			//quand on ouvre une fenetre, envoyer toutes les textures
			//puis attendre les evenements pour agir

			//Send_main_tiles();
			Bouton[3].Update(Events);
			Bouton[4].Update(Events);
		}
		else
		{

		}

		if (Statut(Game_Status::Quit))
		{
			Windows->Close(Window_name);
		}

		Renderers->Affiche(Windows->GetWindow(Window_name));
	}
	
	return true;
}

void pair::Send_background()
{
	Renderers->Addtuile(&Bouton[0], 0);
}

void pair::Send_tiles()
{
	for (short y = 0; y < 6; ++y)
	{
		for (short x = 0; x < 8; ++x)
		{
			Bouton[2].Setposition(sf::Vector2f((float)(x * 128), (float)(y * 128))); // trouver une solution pour ça
			Renderers->Addtuile(&Bouton[2]);
		}
	}
}

void pair::Send_main_tiles()
{
	Renderers->Addtuile(&Bouton[3], 2);
	Renderers->Addtuile(&Bouton[4], 2);
	
}

void pair::Ready_game()
{
	Windows->CreateWindow(Width, Height, Window_name);
	bouton Nouveau;
	//on met le fond
	Nouveau.Setname(Fonds_name[0]);
	Nouveau.Setposition(sf::Vector2f(10.0f, 2.0f));
	Nouveau.Setsize(sf::Vector2f((float)Width, (float)Height));
	Bouton.push_back(Nouveau); //0
	//puis toutes les textures de base
	//selection
	Nouveau.Setname(Divers_name[0]);
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Bouton.push_back(Nouveau); //1
	//back
	Nouveau.Setname(Divers_name[1]);
	Nouveau.Setsize(sf::Vector2f(128.0f, 128.0f));
	Bouton.push_back(Nouveau); //2
	//exit
	Nouveau.Setname(Divers_name[2]);
	Nouveau.Setposition(sf::Vector2f(524.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Nouveau.Hover(&pair::ExitHover);
	Nouveau.Click(&pair::Exitclick);
	Bouton.push_back(Nouveau); //3
	//play
	Nouveau.Setname(Divers_name[3]);
	Nouveau.Setposition(sf::Vector2f(400.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Nouveau.Hover(&pair::Playhover);
	Nouveau.Click(&pair::Playclick);
	Bouton.push_back(Nouveau); //4
	//hover
	Nouveau.Setname(Hover_name);
	Nouveau.Setposition(sf::Vector2f(400.0f, 334.0f));
	Nouveau.Setsize(sf::Vector2f(100.0f, 100.0f));
	Bouton.push_back(Nouveau); //5

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

void pair::Exitclick()
{
	Set(Game_Status::Quit);
}

void pair::Playclick()
{
	Unset(Game_Status::Main_window);
	Set(Game_Status::Play);
}

void pair::ExitHover()
{
	Bouton[5].Setposition(sf::Vector2f(524.0f, 334.0f));
	Renderers->Addtuile(&Bouton[5], 1);
}

void pair::Playhover()
{
	Bouton[5].Setposition(sf::Vector2f(400.0f, 334.0f));
	Renderers->Addtuile(&Bouton[5], 1);
}

#include "pair.h"



pair::pair()
{
	Fichier = std::make_unique<fichier>();
	Son = std::make_unique<audio>();
	//Texture = std::make_unique<textures>(Files.get());
	//Fonte = std::make_unique<fonte>(Files.get());
	//Renderer = std::make_unique<renderer>(Windows.get(), Texture.get(), Fonte.get());
}


pair::~pair()
{
}

bool pair::Run()
{
	sf::Event event;

	fichier *test = new fichier();
	//audio *son = new audio();

	//sf::Font font = test->Get_File<sf::Font>("arial.ttf");
	//sf::Text texte;
	//texte.setString("test");
	//texte.setFont(font);
	//texte.setFillColor(sf::Color::Red);

	//texture *Texture = new texture();
	//sf::Texture *t = Texture->Get("exit");
	//sf::Image image1 = test->Get_File<sf::Image>("play.png");

	//sf::VideoMode Resolution;
	//sf::RenderWindow * Window;

	//Resolution = sf::VideoMode(1024, 768);
	//Window = new sf::RenderWindow(Resolution, "test", sf::Style::Close);
	//while (1)
	//{
	//	Window->clear();
	//	Window->draw(texte);
	//	Window->display();
	//}

	//delete Window;
	//delete son;
	//delete test;
	//delete Texture;
	return true;
}

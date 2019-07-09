#include "rendu.h"



rendu::rendu()
{
	//CreateWindow(Width, Height, Window_name);
	//Window = GetWindow(Window_name);
	Time = Horloge.now();
}


rendu::~rendu()
{
}

void rendu::Affiche(sf::RenderWindow * Window)
{
	auto Actual_time = Horloge.now();
	if (Actual_time - Time >= std::chrono::microseconds(20000))//11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
	{
		Window->clear();







		Window->display();
		Time = Horloge.now();
	}
}

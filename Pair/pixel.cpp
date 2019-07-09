#include "pixel.h"



pixel::pixel()
{
}

pixel::pixel(sf::Vector2f Position, sf::Color Couleur)
{
	vPixel.color = Couleur;
	vPixel.position = Position;

	Setlive();
	Setspeed();
	Setdirection();
}


pixel::~pixel()
{
}

const bool pixel::Alive() const
{
	return Vie;
}

void pixel::Update()
{
	--Vie;

	vPixel.position.x += Direction.x;
	vPixel.position.y += Direction.y;
}

const sf::Vertex pixel::GetPixel() const
{
	return sf::Vertex();
}

void pixel::Setspeed()
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_real_distribution<float> uniform_dist(1.0f, 1.5f);
	Vitesse = uniform_dist(engine);
}

void pixel::Setdirection()
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_real_distribution<float> uniform_dist(80.0f, 110.0f);
	float rotation = uniform_dist(engine);
	float angle = rotation * 3.141592653589793238463f / 180.f;
	Direction.x = cos(angle) * Vitesse;
	Direction.y = sin(angle) * Vitesse;
}

void pixel::Setlive()
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_int_distribution<int> uniform_dist(5, 30);
	Vie = uniform_dist(engine);
}

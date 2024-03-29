#include "audio.h"



audio::audio()
{
	/*std::transform(Audio_name->begin(), Audio_name->end(), Audio_name->begin(), [&](const auto& Nom)
	{
		Buffers.push_back(Fichier.Get_File<sf::SoundBuffer>(Nom + ".ogg"));
	});*/
	for (auto Nom : Audio_name)
	{
		Buffers.push_back(Fichier.Get_File<sf::SoundBuffer>(Nom + ".ogg"));
	}

	for (auto Boucle : { 0,1,2,3 })
	{
		sf::Sound Sound;
		Sound.setBuffer(Buffers[Boucle]);
		Sounds.push_back(Sound);
	}
}

audio::~audio()
{
}

sf::Sound * audio::Get(const sf::String Sound_name)
{
	short Numero = 0;
	for (auto Nom : Audio_name)
	{
		if (Nom == Sound_name)
		{
			return &Sounds[Numero];
		}
		++Numero;
	}
	return nullptr;
}
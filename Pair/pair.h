#pragma once

#include "fichier.h"
#include "audio.h"
#include "texture.h"

class pair
{
public:
	pair();
	~pair();

	//boucle principal
	bool Run();

private:

	//sound instance
	std::unique_ptr <audio>  Son;
	//texture instance
	//std::unique_ptr <textures>  Texture;
	//fonte instance
	//std::unique_ptr <fonte>  Fonte;
	//files instance
	std::unique_ptr <fichier>  Fichier;
	//renderer instance
	//std::unique_ptr <renderer> Renderer;
};


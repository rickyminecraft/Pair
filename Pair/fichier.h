#pragma once

#include <SFML/Graphics.hpp>
#include <physfs.h>

class fichier
{
public:
	fichier();
	~fichier();

	//permet de savoir s'il y a une erreur
	const bool Has_error() const;
	//tant qu'il y a un message d'erreur, retourne le message
	const sf::String Get_error();

	//un template pour remplacer 4 fonctions quasi identiques
	template<class T>
	T Get_File(const sf::String File_name)
	{
		sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
		T file_type;

		if (File_exist(File_name))
		{
			PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
			PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);

			char * Buffer = new char[File_size];
			PHYSFS_readBytes(File_Handle, Buffer, File_size);

			//si c'est une texture, on passe dans la boucle car il faut l'intermédiaire
			/*if (Extension == "jpg" || Extension == "png")
			{
				sf::Image Image;
				Image.loadFromMemory(Buffer, File_size);
				file_type.loadFromMemory(Image.getPixelsPtr(), );
			}*/
			if (Extension == "ttf")
			{
				//on dereference Buffer et après on le neutralise en lui mettant nullptr comme adresse.
				Buffer_fonte = &Buffer[0];
				Buffer = nullptr;
				file_type.loadFromMemory(Buffer_fonte, File_size);
			}
			else
			{
				file_type.loadFromMemory(Buffer, File_size);
			}

			PHYSFS_close(File_Handle);

			//si c'est une fonte, on ne détruit pas le buffer
			//vu qu'il est dereferencer
			if (Extension != "ttf")
			{

				delete Buffer;
			}
		}
		return file_type;
	}

private:
	//monte un fichier zip
	void Mount(const sf::String);
	//met un message d'erreur
	void Report_error(const sf::String Error_string);
	//le fichier existe ?
	bool File_exist(const sf::String File_name);
	//nom du fichier contenant les assets
	const sf::String Pak_name = "matchmaking.pak";

	static bool bError;
	static std::vector<sf::String> stError;
	char * Buffer_fonte;
};
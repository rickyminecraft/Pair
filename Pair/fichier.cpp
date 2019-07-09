#include "fichier.h"



fichier::fichier()
{
	bool bInit = PHYSFS_init(nullptr);
	if (!bInit)
	{
		Report_error("Impossible d'initialiser PHYSFS");
	}
	else
	{
		//on monte le fichier zip
		Mount(Pak_name);
	}
}


fichier::~fichier()
{
	delete Buffer_fonte;
	PHYSFS_deinit();
}

const bool fichier::Has_error() const
{
	return bError;
}

const sf::String fichier::Get_error()
{
	if (stError.size() != 0)
	{
		sf::String Text = stError[stError.size() - 1];
		stError.pop_back();
		return Text;
	}
	bError = false;
	return "";
}

void fichier::Mount(const sf::String File_name)
{
	bool bMount = PHYSFS_mount(File_name.toAnsiString().c_str(), "", 1);
	if (!bMount)
	{
		Report_error(PHYSFS_getLastError());
	}
}

void fichier::Report_error(const sf::String Error_string)
{
	bError = true;
	stError.push_back(Error_string);
}

bool fichier::File_exist(const sf::String File_name)
{
	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		return true;
	}
	else
	{
		sf::String Error_text = "Fichier non trouvé: " + File_name;
		Report_error(Error_text);
		return false;
	}
}

bool fichier::bError = false;
std::vector<sf::String> fichier::stError;
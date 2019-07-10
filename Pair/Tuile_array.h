#pragma once

#include <random>

class Tuile_array
{
public:
	Tuile_array();
	~Tuile_array();

	//get the content of tile 'numero'
	const short Get(const short Numero);
	//is tile 'numero' done ?
	const bool Removed(const short Numero);
	//set tiles 'numero' done
	void Remove(const short Numero);
	//is all tiles done ?
	const bool Is_all_removed() const;
	//ready everything
	void Reset();

private:
	//shuffle array content
	void Shuffle();
	const short Min = 0, Max = 48;

	std::vector<std::pair<short, bool>> Tiles;
};


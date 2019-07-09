#include <cstdlib>
#include <memory>

#include "pair.h"

int main()
{
	std::unique_ptr<pair> Game(new pair());

	if (!Game->Run())
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
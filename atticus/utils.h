#pragma once
#include <fstream>

namespace utils
{

	void wipeFile(std::fstream& f)
	{
		f.open(filename, std::ios::trunc);
		f.close();
	}
}


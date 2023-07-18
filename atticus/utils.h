#pragma once
#include <fstream>

namespace utils
{
	std::string filename{ "C:\\Users\\gusbr\\source\\repos\\atticus\\books.txt" };

	void wipeFile(std::fstream& f)
	{
		f.open(filename, std::ios::trunc);
		f.close();
	}
}


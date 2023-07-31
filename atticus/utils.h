#pragma once

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

#include "Book.h"

namespace utils
{
	extern std::string filename;

	std::string toLower(std::string str);

	std::string toUpper(std::string str);

	void wipeFile(std::fstream& file);

	void updateFile(std::vector<Book>& shelf, std::fstream& file);

	void printShelf(std::vector<Book>& shelf);
}


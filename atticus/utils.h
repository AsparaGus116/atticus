#pragma once
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Book.h"



namespace utils
{
	extern std::string filename;

	std::string toLower(std::string str);

	std::string toUpper(std::string str);

	void wipeFile(std::fstream& f);

	void updateFile(std::fstream& f, std::vector<Book>& shelf);

	void printShelf(std::vector<Book>& shelf);
}


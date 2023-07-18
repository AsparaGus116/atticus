#pragma once
#include <fstream>
#include <algorithm>

namespace utils
{
	std::string filename{ "C:\\Users\\gusbr\\source\\repos\\atticus\\books.txt" };

	std::string& toLower(std::string str)
	{
		std::string res = "";
		for (auto c : str)
		{
			if (c >= 'A' && c <= 'Z')
			{
				res += c + 32;
			}
			else
			{
				res += c;
			}
		}
		return res;
	}

	std::string& toUpper(std::string str)
	{
		std::string res = "";
		for (auto c : str)
		{
			if (c >= 'a' && c <= 'z')
			{
				res += c - 32;
			}
			else
			{
				res += c;
			}
		}
		return res;
	}

	void wipeFile(std::fstream& f)
	{
		f.open(filename, std::ios::trunc);
		f.close();
	}

	void updateFile(std::fstream& f, std::vector<Book>& shelf)
	{
		wipeFile(f);
		std::sort(shelf.begin(), shelf.end());

		for (auto book : shelf)
		{
			book.writeToFile(f);
		}
	}

	void printShelf(const std::vector<Book>& shelf)
	{
		int counter = 1;
		for (auto book : shelf)
		{
			std::cout << counter << ") " << book;
			++counter;
		}
	}
}


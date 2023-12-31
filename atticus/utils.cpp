#include "utils.h"


std::map<char, std::string> utils::optionNames = 
{
	{'a', "add book"},
	{'d', "delete book"},
	{'m', "modify book"},
	{'u', "update pages read"},
	{'v', "view books"},
	{'e', "exit"},
	{'y', "yes"},
	{'n', "no"}
};

void utils::printOption(char option)
{
	std::cout << optionNames[option] << '\n';
}

std::string utils::filename = "C:\\Users\\gusbr\\Desktop\\CodingShit\\C++\\atticus\\books.txt";

std::string utils::toLower(std::string str)
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

std::string utils::toUpper(std::string str)
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

void utils::wipeFile(std::fstream& file)
{
	if (file.is_open())
	{
		file.close();
	}
	file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);
}

void utils::updateFile(std::vector<Book>& shelf, std::fstream& file)
{
	wipeFile(file);
	std::sort(shelf.begin(), shelf.end());

	for (auto book : shelf)
	{
		file << book;
	}
}

void utils::printShelf(std::vector<Book>& shelf)
{
	system("cls");
	int counter = 1;
	for (auto book : shelf)
	{
		std::cout << counter << ") ";
		std::cout << (counter < 10 ? " " : "");
		std::cout << book;

		++counter;
	}
}

void utils::printShelf(std::vector<Book>& shelf, char option)
{
	printShelf(shelf);
	printOption(option);
}
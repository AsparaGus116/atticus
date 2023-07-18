#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Book.h"
#include "utils.h"

int main()
{
	std::fstream file{utils::filename, std::ios::in | std::ios::out};
	std::vector<Book> shelf;
	while (file.good())
	{
		Book b;
		file >> b;
		shelf.push_back(b);
	}
	utils::wipeFile(file);
	std::sort(shelf.begin(), shelf.end()); // sorts books alphabetically
	for (auto book : shelf)
	{
		std::cout << book;
	}
	

	for (auto book : shelf)
	{
		book.writeToFile(file);
	}

}
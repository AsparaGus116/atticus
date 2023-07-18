#include <fstream>
#include <vector>
#include <cstdlib>

#include "Book.h"
#include "utils.h"

int main()
{
	std::fstream file{"REDACTED", std::ios::in | std::ios::out};
	std::vector<Book> shelf;
	while (file.good())
	{
		Book b;
		file >> b;
		shelf.push_back(b);
	}
	for (auto book : shelf)
	{
		std::cout << book;
	}

}
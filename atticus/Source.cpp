#include <fstream>
#include <vector>

#include "Book.h"

int main()
{
	std::fstream file{"C:\\Users\\gusbr\\source\\repos\\atticus\\books.txt", std::ios::in | std::ios::out};
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
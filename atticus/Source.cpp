#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Book.h"
#include "utils.h"

#define PROMPT ">> "

void handleAdd(std::vector<Book>& shelf);
void handleDelete(std::vector<Book>& shelf);
void handleModify(std::vector<Book>& shelf);
void handleUpdate(std::vector<Book>& shelf);

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
	utils::updateFile(file, shelf);

	utils::printShelf(shelf);
	
	while (1)
	{
		char option = '\0';
		std::string optionList{ "admuve" };
		do
		{
			std::cout << "Would you like to (a)dd, (d)elete, (m)odify a book, (u)pdate pages read, (v)iew, or (e)xit?\n";
			std::cin >> option;
			std::cin.ignore(4096, '\n');
		} while (optionList.find(option) == -1 && std::cout << "Invalid option, please try again.\n");

		switch (option)
		{
		case 'a':
			handleAdd(shelf);
			utils::updateFile(file, shelf);
			break;
		case 'd':
			handleDelete(shelf);
			utils::updateFile(file, shelf);
			break;
		case 'm':
			handleModify(shelf);
			utils::updateFile(file, shelf);
			break;
		case 'u':
			handleUpdate(shelf);
			utils::updateFile(file, shelf);
			break;
		case 'v':
			utils::printShelf(shelf);
			break;
		case 'e':
			return 0;
			break;
		default:
			break;
		}
	}

	
}

void handleAdd(std::vector<Book>& shelf)
{
	std::string title;
	int pagesRead;
	int totalPages;
	while (1)
	{
		std::cout << "What is the book's title?\n" << PROMPT;
		std::getline(std::cin, title, '\n');
		if (title.size() == 0)
		{
			std::cout << "\nErr: Empty title\n";
		}
		else if (std::find(shelf.begin(), shelf.end(), utils::toLower(title)) != shelf.end())
		{
			std::cout << "\nErr: Book already in library\n";
		}
		else
		{
			break;
		}
		
	}
	
	do
	{
		std::cout << "How many pages have you read?\n" << PROMPT;
		std::cin >> pagesRead;
	} while (pagesRead < 0 && std::cout << "\nErr: Please enter valid length\n");

	do
	{
		std::cout << "How many total pages are there?\n" << PROMPT;
		std::cin >> totalPages;
	} while (totalPages <= 0 && std::cout << "\nErr: Please enter valid length\n");
	shelf.push_back({ title, pagesRead, totalPages });
	return;
}

void handleDelete(std::vector<Book>& shelf)
{

}

void handleModify(std::vector<Book>& shelf)
{

}

void handleUpdate(std::vector<Book>& shelf)
{

}
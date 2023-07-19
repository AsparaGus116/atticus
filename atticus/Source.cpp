#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Book.h"
#include "utils.h"

#define PROMPT ">> "

void handleAdd(std::vector<Book>& shelf, std::fstream& file);
void handleDelete(std::vector<Book>& shelf, std::fstream& file);
void handleModify(std::vector<Book>& shelf, std::fstream& file);
void handleUpdate(std::vector<Book>& shelf, std::fstream& file);

int main()
{
	std::fstream file{utils::filename, std::ios::in | std::ios::out};
	std::vector<Book> shelf;
	while (!file.eof())
	{
		Book b;
		file >> b;
		if (!file.eof())
		{
			shelf.push_back(b);
		}
		
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
			handleAdd(shelf, file);
			break;
		case 'd':
			handleDelete(shelf, file);
			break;
		case 'm':
			handleModify(shelf, file);
			break;
		case 'u':
			handleUpdate(shelf, file);
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

void handleAdd(std::vector<Book>& shelf, std::fstream& file)
{
	std::string title;
	int pagesRead = 0;
	int totalPages = 0;
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
	Book b{ title, pagesRead, totalPages };
	shelf.push_back(b);
	utils::updateFile(file, shelf);
	std::cout << b.getTitle() << " successfully added.\n";
	return;
}

void handleDelete(std::vector<Book>& shelf, std::fstream& file)
{
	utils::printShelf(shelf);
	
	int sel = 0;
	do
	{
		std::cout << "Which book would you like to delete? (1-" << shelf.size() << ")\n" << PROMPT;
		std::cin >> sel;
	} while (sel <= 0 && sel > shelf.size() && std::cout << "Please enter a valid number\n");
	Book b = shelf[sel - 1];
	shelf.erase(shelf.begin() + (sel - 1));
	utils::updateFile(file, shelf);
	std::cout << b.getTitle() << " successfully deleted.\n";
}

void handleModify(std::vector<Book>& shelf, std::fstream& file)
{
	utils::printShelf(shelf);

	int sel = 0;
	do
	{
		std::cout << "Which book would you like to modify? (1-" << shelf.size() << ")\n" << PROMPT;
		std::cin >> sel;
	} while (sel <= 0 && sel > shelf.size() && std::cout << "Please enter a valid number\n");

	Book b = shelf[sel - 1];
	shelf.erase(shelf.begin() + (sel - 1));

	char c;

	do
	{
		std::cout << "Would you like to change the title? (y/n)\n" << PROMPT;
		std::cin >> c;
		std::cin.ignore(4096, '\n');
	} while (std::tolower(c) != 'y' && std::tolower(c) != 'n');

	std::string newTitle = "";
	if (std::tolower(c) == 'y')
	{
		std::cout << "Enter new title:\n" << PROMPT;
		std::cin >> newTitle;
	}
	else
	{
		newTitle = b.getTitle();
	}

	c = '\0';

	do
	{
		std::cout << "Would you like to change the total pages? (y/n)\n" << PROMPT;
		std::cin >> c;
		std::cin.ignore(4096, '\n');
	} while (std::tolower(c) != 'y' && std::tolower(c) != 'n');

	int newTotalPages = 0;

	if (std::tolower(c) == 'y')
	{
		do
		{
			std::cout << "Enter new page count:\n" << PROMPT;
		} while (newTotalPages <= 0);
	}
	else
	{
		newTotalPages = b.getTotalPages();
	}
	shelf.push_back({ newTitle, b.getPagesRead(), newTotalPages });
	utils::updateFile(file, shelf);
	std::cout << newTitle << " successfully modified.\n";
}

void handleUpdate(std::vector<Book>& shelf, std::fstream& file)
{

}
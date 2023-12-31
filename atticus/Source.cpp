#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <map>

#include "Book.h"
#include "utils.h"

#define PROMPT ">> "

void handleAdd(std::vector<Book>& shelf, std::fstream& file);
void handleDelete(std::vector<Book>& shelf, std::fstream& file);
void handleModify(std::vector<Book>& shelf, std::fstream& file);
void handleUpdate(std::vector<Book>& shelf, std::fstream& file);

char getInput(std::string options)
{
	while (1)
	{
		if (_kbhit())
		{
			char c = _getch();
			for (auto x : options)
			{
				if (c == x)
				{
					return x;
				}
			}
		}
		
	}
}

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

	utils::printShelf(shelf);
	
	while (1)
	{
		char option = '\0';
		std::string optionList{ "admuve" };
		do
		{
			std::cout << "Would you like to (a)dd, (d)elete, (m)odify a book, (u)pdate pages read, (v)iew, or (e)xit?\n" << PROMPT;
			option = getInput(optionList);
		} while (optionList.find(option) == -1 && std::cout << "Invalid option, please try again.\n");

		std::cout << utils::optionNames[option] << '\n';
		switch (option)
		{
		case 'a':
			handleAdd(shelf, file);
			file.close();
			break;
		case 'd':
			handleDelete(shelf, file);
			file.close();
			break;
		case 'm':
			handleModify(shelf, file);
			file.close();
			break;
		case 'u':
			handleUpdate(shelf, file);
			file.close();
			break;
		case 'v':
			utils::printShelf(shelf, option);
			break;
		case 'e':
			return 0;
			utils::updateFile(shelf, file);
			file.close();
			break;
		default:
			break;
		}
	}

	
}

void handleAdd(std::vector<Book>& shelf, std::fstream& file)
{
	file.open(utils::filename, std::ios::in | std::ios::out);
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
	utils::updateFile(shelf, file);
	std::cout << b.getTitle() << " successfully added.\n";
	return;
}

void handleDelete(std::vector<Book>& shelf, std::fstream& file)
{
	file.open(utils::filename, std::ios::in | std::ios::out);
	utils::printShelf(shelf, 'd');
	
	int sel = 0;
	do
	{
		std::cout << "Which book would you like to delete? (1-" << shelf.size() << ")\n" << PROMPT;
		std::cin >> sel;
	} while (sel <= 0 && sel > shelf.size() && std::cout << "Please enter a valid number\n");
	Book b = shelf[sel - 1];
	shelf.erase(shelf.begin() + (sel - 1));
	utils::updateFile(shelf, file);
	std::cout << b.getTitle() << " successfully deleted.\n";
}

void handleModify(std::vector<Book>& shelf, std::fstream& file)
{
	file.open(utils::filename, std::ios::in | std::ios::out);
	utils::printShelf(shelf, 'm');

	int sel = 0;
	do
	{
		std::cout << "Which book would you like to modify? (1-" << shelf.size() << ")\n" << PROMPT;
		std::cin >> sel;
	} while (sel <= 0 && sel > shelf.size() && std::cout << "Please enter a valid number\n");

	Book b = shelf[sel - 1];
	

	char c;

	do
	{
		std::cout << "Would you like to change the title? (y/n)\n" << PROMPT;
		c = getInput("yn");
	} while (std::tolower(c) != 'y' && std::tolower(c) != 'n');
	utils::printOption(c);

	std::string newTitle = "";
	if (std::tolower(c) == 'y')
	{
		std::cout << "Enter new title:\n" << PROMPT;
		std::getline(std::cin, newTitle, '\n');
	}
	else
	{
		newTitle = b.getTitle();
	}

	c = '\0';

	do
	{
		std::cout << "Would you like to change the total pages? (y/n)\n" << PROMPT;
		c = getInput("yn");
	} while (std::tolower(c) != 'y' && std::tolower(c) != 'n');
	utils::printOption(c);

	int newTotalPages = 0;

	if (std::tolower(c) == 'y')
	{
		do
		{
			std::cout << "Enter new page count:\n" << PROMPT;
			std::cin >> newTotalPages;
		} while (newTotalPages <= 0 && newTotalPages > b.getPagesRead());
	}
	else
	{
		newTotalPages = b.getTotalPages();
	}
	shelf.erase(shelf.begin() + (sel - 1));
	shelf.push_back({ newTitle, b.getPagesRead(), newTotalPages });
	utils::updateFile(shelf, file);
	std::cout << newTitle << " successfully modified.\n";
}

void handleUpdate(std::vector<Book>& shelf, std::fstream& file)
{
	file.open(utils::filename, std::ios::in | std::ios::out);
	utils::printShelf(shelf, 'u');

	int sel = 0;
	do
	{
		std::cout << "Which book would you like to modify? (1-" << shelf.size() << ")\n" << PROMPT;
		std::cin >> sel;
	} while (sel <= 0 && sel > shelf.size() && std::cout << "Please enter a valid number\n");

	Book b = shelf[sel - 1];

	int newPagesRead = 0;

	do
	{
		std::cout << "Enter new page count:\n" << PROMPT;
		std::cin >> newPagesRead;
	} while (newPagesRead <= 0 && newPagesRead > b.getTotalPages());
	shelf.erase(shelf.begin() + (sel - 1));
	shelf.push_back({ b.getTitle(), newPagesRead, b.getTotalPages()});
	utils::updateFile(shelf, file);
	std::cout << b.getTitle() << " successfully updated.\n";
}
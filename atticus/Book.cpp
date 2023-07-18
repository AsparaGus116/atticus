#include "Book.h"

#define PLACEHOLDER 64
#define BAR_SIZE 50

std::ostream& operator<< (std::ostream& out, const Book& b)
{
	std::string title = b.getTitle();
	out << title;
	for (int i = 0; i < 84 - b.getTitle().size(); i++)
	{
		std::cout << '.';
	}
	double percentComplete = (double)b.getPagesRead() / b.getTotalPages();
	out << '[';
	int percentCompleteInt = (int)(percentComplete * 100);
	for (int i = 0; i < percentCompleteInt / (100 / BAR_SIZE); i++)
	{
		out << (char)219;
	}
	for (int i = 0; i < BAR_SIZE - percentCompleteInt / (100 / BAR_SIZE); i++)
	{
		out << '-';
	}
	out << "]    " << b.getPagesRead() << " / " << b.getTotalPages() << " (" << percentCompleteInt << "%)";
	out << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Book& b)
{
	// Input takes form: <title>@<pagesRead>@<totalPages>
	in >> std::noskipws; // modifies input behavior to not skip whitespace
	char c;
	in >> c;
	std::string title = "";
	while (c != PLACEHOLDER) // @ acts as a placeholder to separate values
	{
		title += c;
		in >> c;
	}
	b.updateTitle(title);
	int pagesRead;
	in >> pagesRead;
	b.updatePagesRead(pagesRead);

	char empty; // weeds out placeholder again
	in >> empty;

	int totalPages;
	in >> totalPages;
	b.updateTotalPages(totalPages);

	in >> empty; // remove \n

	return in;
}

bool operator<(const Book& b1, const Book& b2)
{
	return b1.getTitle() < b2.getTitle();
}

bool operator==(const Book& b1, const Book& b2)
{
	return b1.getTitle() == b2.getTitle();
}

Book::Book(std::string m_title, int m_pagesRead, int m_totalPages):
	title{m_title},
	pagesRead{m_pagesRead},
	totalPages{m_totalPages}
{
}

void Book::writeToFile(std::fstream& f)
{
	f <<  title << '@' << pagesRead << '@' << totalPages << '\n';
}

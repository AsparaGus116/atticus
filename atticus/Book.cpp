#include "Book.h"
#include "utils.h"


#define PLACEHOLDER 64
#define BAR_SIZE 50

Book::Book(std::string m_title, int m_pagesRead, int m_totalPages) :
	title{ m_title },
	pagesRead{ m_pagesRead },
	totalPages{ m_totalPages }
{
}

std::ostream& operator<< (std::ostream& out, const Book& b)
{
	std::string title = b.getTitle();
	out << title;
	for (int i = 0; i < 64 - b.getTitle().size(); i++)
	{
		std::cout << '.';
	}
	double percentComplete = (double)b.getPagesRead() / b.getTotalPages();
	out << '[';
	int percentCompleteInt = (int)(percentComplete * 100);
	if (!percentCompleteInt) ++percentCompleteInt;
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

std::ostream& operator<< (std::fstream& out, const Book& b)
{
	out << b.getTitle() << '@' << b.getPagesRead() << '@' << b.getTotalPages() << '\n';
	return out;
}

std::istream& operator>> (std::istream& in, Book& b)
{
	// Input takes form: <title>@<pagesRead>@<totalPages>
	in >> std::noskipws; // modifies input behavior to not skip whitespace
	char c;
	in >> c;
	std::string title = "";
	while (c != PLACEHOLDER && !in.eof()) // @ acts as a placeholder to separate values
	{
		title += c;
		in >> c;
	}
	if (in.eof())
	{
		return in;
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

	std::string str;
	std::getline(in, str, '\n');
	return in;
}

bool operator< (const Book& b1, const Book& b2)
{
	return b1.getTitle() < b2.getTitle();
}

bool Book::operator== (std::string s) const
{
	return utils::toLower(title) == utils::toLower(s);
}

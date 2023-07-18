#include "Book.h"

#define PLACEHOLDER 64

std::ostream& operator<< (std::ostream& out, const Book& b)
{
	const int TABS_AFTER_TITLE = 8;
	out << "test";
	for (int i = 0; i <  TABS_AFTER_TITLE - b.getTitle().size() / 8; i++)
	{
		out << '\t';
	}
	double percentComplete = (double)b.getPagesRead() / b.getTotalPages();
	out << '[';
	int percentCompleteInt = (int)(percentComplete * 100);
	for (int i = 0; i < percentCompleteInt / 4; i++)
	{
		out << (char)219;
	}
	for (int i = 0; i < 25 - percentCompleteInt / 4; i++)
	{
		out << '-';
	}
	out << "]\t" << b.getPagesRead() << " / " << b.getTotalPages() << " (" << percentCompleteInt << "%)";
	out << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Book& b)
{
	// Input takes form: <title>|<pagesRead>|<totalPages>, where | is placeholder
	char c;
	in >> c;
	std::string title = "";
	while (c != PLACEHOLDER) // 219 acts as a placeholder to separate values
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

	return in;
}

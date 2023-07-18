#include "Book.h"

#define PLACEHOLDER 219

std::ostream& operator<< (std::ostream& out, const Book& b)
{
	const int TABS_AFTER_TITLE = 8;
	out << b.getTitle();
	for (int i = 0; i < b.getTitle().size() / 8 - TABS_AFTER_TITLE; i++)
	{
		out << '\t';
	}
	double percentComplete = (double)b.getPagesRead() / b.getTotalPages();
	out << '[';
	int percentCompleteInt = (int)(percentComplete * 100);
	for (int i = 0; i < percentCompleteInt / 4; i++)
	{
		out << 219;
	}
	for (int i = 0; i < 25 - percentCompleteInt; i++)
	{
		out << '-';
	}
	out << "]\t" << b.getPagesRead() << " / " << b.getTotalPages() << '(' << percentCompleteInt << "%)";
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

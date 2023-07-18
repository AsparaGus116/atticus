#pragma once
#include <string>
#include <iostream>

class Book
{
private:
	std::string title;
	int pagesRead;
	int totalPages;
	
public:
	//setters
	void updateTitle(std::string newTitle) { title = newTitle; }
	void updatePagesRead(int newPagesRead) { pagesRead = newPagesRead; }
	void updateTotalPages(int newTotalPages) { totalPages = newTotalPages; }

	//getters
	std::string getTitle() const { return title; }
	int getPagesRead() const { return pagesRead; }
	int getTotalPages() const { return totalPages; }
	

	//overloaded IO
	friend std::ostream& operator<< (std::ostream& out, const Book& b);
	friend std::istream& operator>> (std::istream& in, Book& b);
};




#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Book
{
private:
	std::string title;
	int pagesRead;
	int totalPages;
	
public:
	//constructors
	Book() = default;
	Book(std::string m_title, int m_pagesRead, int m_totalPages);

	//setters
	void updateTitle(std::string newTitle) { title = newTitle; }
	void updatePagesRead(int newPagesRead) { pagesRead = newPagesRead; }
	void updateTotalPages(int newTotalPages) { totalPages = newTotalPages; }

	//getters
	std::string getTitle() const { return title; }
	int getPagesRead() const { return pagesRead; }
	int getTotalPages() const { return totalPages; }
	
	void writeToFile(std::fstream& f);

	//overloaded IO
	friend std::ostream& operator<< (std::ostream& out, const Book& b);
	friend std::istream& operator>> (std::istream& in, Book& b);

	friend bool operator<(const Book& b1, const Book& b2);
	bool operator==(std::string s) const;
};




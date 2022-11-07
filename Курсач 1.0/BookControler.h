#pragma once
#include "Book.h"

class BookControler
{
private:
	Book book;
public:
	BookControler(Book book)
	{
		this->book = book;
	}
	void get_num_of_copies(int num)
	{
		if (num < 0)
			throw;
		book.set_num_of_copies(num);
	}
	int set_num_of_copies()
	{
		return book.get_num_of_copies();
	}
	float get_Book_price()
	{
		return book.get_price();
	}
	void set_Book_price(float price)
	{
		if (price < 0.01)
			throw;
		book.set_price(price);
	}
	FullName get_Book_Author_name()
	{
		return book.get_Author_name();
	}
	void set_Book_Author_name(FullName author_name)
	{
		book.set_Author_name(author_name);
	}
	char* get_Book_description()
	{
		return book.get_description();
	}
	void set_Book_description(char* description)
	{
		book.set_description(description);
	}
	char* get_book_name()
	{
		return book.get_book_name();
	}
	void set_book_name(char* book_name)
	{
		book.set_book_name(book_name);
	}
};


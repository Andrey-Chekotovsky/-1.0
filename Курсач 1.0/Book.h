#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"

class Book   
{
private:
	FullName Author_name;
	char book_name[40];
	char description[500];
	int num_of_copies;
	float price;
public:
	Book();
	Book(Book& other);
	void set_num_of_copies(int num)
	{
		this->num_of_copies = num;
	}
	int get_num_of_copies()
	{
		return this->num_of_copies;
	}
	float get_price()
	{
		return this->price;
	}
	void set_price(float price)
	{
		this->price = price;
	}
	FullName get_Author_name()
	{
		return this->Author_name;
	}
	void set_Author_name(FullName author_name)
	{
		this->Author_name = author_name;
	}
	char* get_description()
	{
		return this->description;
	}
	void set_description(char* description)
	{
		strcpy_s(this->description, description);
	}
	char* get_book_name()
	{
		return this->book_name;
	}
	void set_book_name(char* book_name)
	{
		strcpy_s(this->book_name, book_name);
	}
	void operator =(Book& other);
};


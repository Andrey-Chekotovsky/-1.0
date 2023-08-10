#pragma once
#include <exception>
#include <string>
#include<fstream>
#include "FullName.h"
#include "Exeptions.h"

class Book  
{
private:
	FullName Author_name;
	int ID;
	char book_name[40];
	char description[500];
	int num_of_copies;
	float price;
public:
	Book();
	Book(Book const& other);
	void set_num_of_copies(int num);
	int get_num_of_copies();
	float get_price();
	void set_price(float price);
	FullName get_Author_name();
	void set_Author_name(FullName author_name);
	char* get_description();
	void set_description(char* description);
	char* get_book_name();
	void set_book_name(char* book_name);
	int get_ID();
	void operator =(Book const& other);
	bool operator ==(Book const& other);
	void generate_ID();
	void view();
};


#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"
#include "Date.h"
#include "Book.h"
#include<vector>

class Purchase
{
private:
	int customer_ID;
	float price;
	int num;
	int order[10];
	int books_in_order[10];
	Date date;
public:
	Purchase();
	Purchase(Purchase const& other);
	int get_costomerID();
	void set_costomerID(int costomer);
	int get_num();
	int get_number_of_books();
	float get_price();
	int get_book_ID(int num_of_book);
	void add(Book& book, int num_books);
	void return_all_books(std::vector<Book>& mas);
	int return_books(Book book);
	void operator =(Purchase const& other);
};


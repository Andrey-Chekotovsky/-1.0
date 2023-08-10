#include "Purchase.h"


Purchase::Purchase()
{
	this->num = 0;
	this->price = 0;
}
Purchase::Purchase(Purchase const& other)
{
	this->date = other.date;
	this->customer_ID = other.customer_ID;
	this->price = other.price;
	this->num = other.num;
	for (int i = 0; i < num; i++)
	{
		this->order[i] = other.order[i];
	}
}
void Purchase::add(Book& book, int num_books)
{
	book.set_num_of_copies(book.get_num_of_copies() - num_books);
	this->order[this->num] = book.get_ID();
	this->books_in_order[this->num] = num_books;
	this->price += book.get_price() * num_books;
	this->num++;
}
int Purchase::return_books(Book book)
{
	int del_num = 0;
	for (; del_num < this->num; del_num++)
	{
		if (order[del_num] == book.get_ID())
			break;
	}
	this->price -= this->books_in_order[del_num] * book.get_price();
	int num_of_copies = this->books_in_order[del_num];
	this->num--;
	for (int i = del_num; i < this->num; i++)
	{
		this->order[i] = this->order[i + 1];
		this->books_in_order[i] = this->books_in_order[i + 1];
	}
	return num_of_copies;
}
void Purchase::operator =(Purchase const& other)
{
	this->date = other.date;
	this->customer_ID = other.customer_ID;
	this->price = other.price;
	this->num = other.num;
	for (int i = 0; i < num; i++)
	{
		this->order[i] = other.order[i];
		this->books_in_order[i] = other.books_in_order[i];
	}
}


int Purchase::get_costomerID()
{
	return this->customer_ID;
}
void Purchase::set_costomerID(int costomer)
{
	this->customer_ID = costomer;
}
int Purchase::get_num()
{
	return this->num;
}
float Purchase::get_price()
{
	return this->price;
}
int Purchase::get_book_ID(int num_of_book)
{
	return this->order[num_of_book];
}
int Purchase::get_number_of_books()
{
	int rez = 0;
	for (int i = 0; i < this->num; i++)
	{
		rez += this->books_in_order[i];
	}
	return rez;
}
void Purchase::return_all_books(std::vector<Book>& mas)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			if (this->order[i] == mas[j].get_ID())
			{
				mas[j].set_num_of_copies(mas[j].get_num_of_copies() + this->books_in_order[i]);
			}
		}
	}
}
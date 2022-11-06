#include "Book.h"

Book::Book()
{
	this->price = 0;
	strcpy_s(this->description, "NONE");
	strcpy_s(this->book_name, "NONE");
}
Book::Book(Book& other)
{
	this->Author_name = other.Author_name;
	this->price = other.price;
	strcpy_s(this->description, other.description);
	strcpy_s(this->book_name, other.book_name);
}
void Book::operator =(Book& other)
{
	this->Author_name = other.Author_name;
	this->price = other.price;
	strcpy_s(this->description, other.description);
	strcpy_s(this->book_name, other.book_name);
}
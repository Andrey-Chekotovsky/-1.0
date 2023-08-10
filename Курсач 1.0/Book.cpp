#include "Book.h"
#include"functions.h"
Book::Book()
{
	this->price = 0;
	strcpy_s(this->description, "NONE");
	strcpy_s(this->book_name, "NONE");
}
Book::Book(Book const& other)
{
	this->ID = other.ID;
	this->num_of_copies = other.num_of_copies;
	this->Author_name = other.Author_name;
	this->price = other.price;
	strcpy_s(this->description, other.description);
	strcpy_s(this->book_name, other.book_name);
}
void Book::operator =(Book const& other)
{
	this->ID = other.ID;
	this->num_of_copies = other.num_of_copies;
	this->Author_name = other.Author_name;
	this->price = other.price;
	strcpy_s(this->description, other.description);
	strcpy_s(this->book_name, other.book_name);
}
void Book::set_num_of_copies(int num)
{
	this->num_of_copies = num;
}
int Book::get_num_of_copies()
{
	return this->num_of_copies;
}
float Book::get_price()
{
	return this->price;
}
void Book::set_price(float price)
{
	this->price = price;
}
FullName Book::get_Author_name()
{
	return this->Author_name;
}
void Book::set_Author_name(FullName author_name)
{
	this->Author_name = author_name;
}
char* Book::get_description()
{
	return this->description;
}
void Book::set_description(char* description)
{
	strcpy_s(this->description, description);
}
char* Book::get_book_name()
{
	return this->book_name;
}
void Book::set_book_name(char* book_name)
{
	strcpy_s(this->book_name, book_name);
}
int Book::get_ID()
{
	return this->ID;
}
void Book::generate_ID()
{
	int ID;
	std::ifstream fin;
	fin.open(BOOK_ID_FILE);
	if (fin.read((char*)&ID, sizeof(int)))
	{
		fin.close();
		Update_ID_File(ID + 1, BOOK_ID_FILE);
		this->ID = ID + 1;
	}
	else
	{
		fin.close();
		Update_ID_File(1, BOOK_ID_FILE);
		this->ID = 0;
	}
}
bool Book::operator ==(Book const& other)
{
	if (this->ID == other.ID)
		return true;
	else
		return false;
}
void Book::view()
{
	std::cout << "Название: " << this->book_name << std::endl;
	std::cout << "Автор: " << this->Author_name.get_string() << std::endl;
	std::cout << "На складе: " << this->num_of_copies << std::endl;
	std::cout << "Цена: " << this->price << std::endl;
	std::cout << "Описание: " << std::endl;
}
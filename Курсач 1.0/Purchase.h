#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"
#include "Date.h"
#include "Book.h"

class Purchase
{
private:
	Date date;
	FullName costomer;
	int num;
	Book order[10];
public:
	Purchase();
	Purchase(Purchase& other);
	Date get_date()
	{
		return this->date;
	}
	void set_date(Date date)
	{
		this->date = date;
	}
	FullName get_Author_name()
	{
		return this->costomer;
	}
	void set_Author_name(FullName costomer)
	{
		this->costomer = costomer;
	}
	void add(Book book);
	void del(int num);
	void operator =(Purchase& other);
};


#include "Purchase.h"


Purchase::Purchase()
{
	this->num = 0;
}
Purchase::Purchase(Purchase& other)
{
	this->date = other.date;
	this->customer = other.customer;
	this->num = other.num;
	for (int i = 0; i < num; i++)
	{
		this->order[i] = other.order[i];
	}
}
void Purchase::add(Book book)
{
	this->order[num] = book;
	this->num++;
}
void Purchase::del(int num)
{
	this->num--;
	for (int i = num; i < this->num; i++)
	{
		this->order[i] = this->order[i + 1];
	}
}
void Purchase::operator =(Purchase& other)
{
	this->date = other.date;
	this->customer = other.customer;
	this->num = other.num;
	for (int i = 0; i < num; i++)
	{
		this->order[i] = other.order[i];
	}
}
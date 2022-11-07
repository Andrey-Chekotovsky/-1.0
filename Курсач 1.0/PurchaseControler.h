#pragma once
#include "Purchase.h"

class PurchaseControler
{
private:
	Purchase purchase;
public:
	Date get_date()
	{
		return purchase.get_date();
	}
	void set_date(Date date)
	{
		purchase.set_date(date);
	}
	FullName get_Author_name()
	{
		return purchase.get_Author_name();
	}
	void set_Author_name(FullName costomer)
	{
		purchase.set_Author_name(costomer);
	}
	void add(Book book);
	void del(int num);
};


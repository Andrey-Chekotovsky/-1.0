#include "PurchaseControler.h"


void PurchaseControler::add(Book book)
{
	if (purchase.get_num() == 10)
		throw;
	purchase.add(book);
}
void PurchaseControler::del(int num)
{
	if (num < 0 || num > 9)
		throw;
	purchase.del(num);
}
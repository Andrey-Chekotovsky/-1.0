#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"
#include "Date.h"
#include "Book.h"

class Purchase
{
	Date date;
	FullName costomer;
	int num;
	Book order;
};


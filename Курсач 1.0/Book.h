#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"

class Book   //main class
{
	FullName Author_name;
	char book_name[40];
	char description[500];
	float price;
};


#include "FullName.h"


FullName::FullName()
{
	strcpy_s(this->name, "None");
	strcpy_s(this->surname, "None");
}
FullName::FullName(char name[30], char surname[30])
{
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
}
void FullName::SetFIO()
{
	std::cin.clear();
	std::cout << "¬ведите фамилию и им€:";
	std::cin >> this->surname >> this->name;
	std::cin.clear();
}

void FullName::set_surname(char* surname)
{
	strcpy_s(this->surname, surname);
}
char* FullName::get_surname()
{
	return this->surname;
}
void FullName::set_name(char* name)
{
	strcpy_s(this->name, name);
}
char* FullName::get_name()
{
	return this->name;
}
std::string FullName::get_string()
{
	std::string fio = " ";
	fio += this->surname; fio += " ";
	fio += this->name;
	fio += " ";
	return fio;
}
bool FullName::operator <(FullName const& other)
{
	int symb = 0;
	if (strlen(this->surname) < strlen(other.surname))
	{
		while (symb < strlen(this->surname))
		{
			if (int(this->surname[symb]) < int(other.surname[symb]))
				return true;
			if (int(this->surname[symb]) > int(other.surname[symb]))
				return false;
			symb++;
		}
	}
	else
	{
		while (symb < strlen(other.surname))
		{
			if (int(this->surname[symb]) < int(other.surname[symb]))
				return true;
			if (int(this->surname[symb]) > int(other.surname[symb]))
				return false;
			symb++;
		}
	}
	return false;
}
bool FullName::operator >(FullName const& other)
{
	int symb = 0;
	if (strlen(this->surname) < strlen(other.surname))
	{
		while (symb < strlen(this->surname))
		{
			if (int(this->surname[symb]) > int(other.surname[symb]))
				return true;
			if (int(this->surname[symb]) < int(other.surname[symb]))
				return false;
			symb++;
		}
	}
	else
	{
		while (symb < strlen(other.surname))
		{
			if (int(this->surname[symb]) > int(other.surname[symb]))
				return true;
			if (int(this->surname[symb]) < int(other.surname[symb]))
				return false;
			symb++;
		}
	}
	return false;
}
void FullName::operator =(const FullName& other)
{
	strcpy_s(this->name, other.name);
	strcpy_s(this->surname, other.surname);
}
bool FullName::operator ==(FullName const& other)
{
	int symb = 0;
	if (strlen(this->surname) != strlen(other.surname))
	{
		return false;
	}
	if (strlen(this->name) != strlen(other.name))
	{
		return false;
	}
	for (symb; symb < strlen(other.surname); symb++)
	{
		if (int(this->surname[symb]) != int(other.surname[symb]))
			return false;
	}
	for (symb = 0; symb < strlen(other.surname); symb++)
	{
		if (int(this->name[symb]) != int(other.name[symb]))
			return false;
	}
	return true;
}
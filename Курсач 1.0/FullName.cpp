#include "FullName.h"


FullName::FullName()
{
	strcpy_s(this->Name, "None");
	strcpy_s(this->Surname, "None");
	strcpy_s(this->Patronymic, "None");
}
FullName::FullName(char name[30], char surname[30], char patronymic[30])
{
	strcpy_s(this->Name, name);
	strcpy_s(this->Surname, surname);
	strcpy_s(this->Patronymic, patronymic);
}
void FullName::SetFIO()
{
	std::cout << "������� ������� ��� � ��������:";
	std::cin >> this->Surname >> this->Name >> this->Patronymic;
	std::cin.clear();
}
std::string FullName::GetFIO()
{
	std::string fio = " ";
	fio += this->Surname; fio += " ";
	fio += this->Name;
	fio += " ";
	fio += this->Patronymic;
	return fio;
}
bool FullName::operator <(FullName& other)
{
	int symb = 0;
	if (strlen(this->Surname) < strlen(other.Surname))
	{
		while (symb < strlen(this->Surname))
		{
			if (int(this->Surname[symb]) < int(other.Surname[symb]))
				return true;
			if (int(this->Surname[symb]) > int(other.Surname[symb]))
				return false;
			symb++;
		}
	}
	else
	{
		while (symb < strlen(other.Surname))
		{
			if (int(this->Surname[symb]) < int(other.Surname[symb]))
				return true;
			if (int(this->Surname[symb]) > int(other.Surname[symb]))
				return false;
			symb++;
		}
	}
	return false;
}
bool FullName::operator >(FullName& other)
{
	int symb = 0;
	if (strlen(this->Surname) < strlen(other.Surname))
	{
		while (symb < strlen(this->Surname))
		{
			if (int(this->Surname[symb]) > int(other.Surname[symb]))
				return true;
			if (int(this->Surname[symb]) < int(other.Surname[symb]))
				return false;
			symb++;
		}
	}
	else
	{
		while (symb < strlen(other.Surname))
		{
			if (int(this->Surname[symb]) > int(other.Surname[symb]))
				return true;
			if (int(this->Surname[symb]) < int(other.Surname[symb]))
				return false;
			symb++;
		}
	}
	return false;
}
void FullName::operator =(const FullName& other)
{
	strcpy_s(this->Name, other.Name);
	strcpy_s(this->Surname, other.Surname);
	strcpy_s(this->Patronymic, other.Patronymic);
}
bool FullName::operator ==(FullName& other)
{
	int symb = 0;
	if (strlen(this->Surname) != strlen(other.Surname))
	{
		return false;
	}
	if (strlen(this->Name) != strlen(other.Name))
	{
		return false;
	}
	if (strlen(this->Patronymic) != strlen(other.Patronymic))
	{
		return false;
	}
	for (symb; symb < strlen(other.Surname); symb++)
	{
		if (int(this->Surname[symb]) != int(other.Surname[symb]))
			return false;
	}
	for (symb = 0; symb < strlen(other.Surname); symb++)
	{
		if (int(this->Name[symb]) != int(other.Name[symb]))
			return false;
	}
	for (symb = 0; symb < strlen(other.Surname); symb++)
	{
		if (int(this->Patronymic[symb]) != int(other.Patronymic[symb]))
			return false;
	}
	return true;
}
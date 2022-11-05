#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	char Name[30], Surname[30], Patronymic[30];
public:
	FullName();
	FullName(char name[30], char surname[30], char patronymic[30]);
	std::string GetFIO();
	void SetFIO();
	bool operator <(FullName& other);
	bool operator >(FullName& other);
	void operator =(const FullName& other);
	bool operator ==(FullName& other);
};


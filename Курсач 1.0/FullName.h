#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	char name[30], surname[30];
public:
	FullName();
	FullName(char name[30], char surname[30]);
	void set_surname(char* surname);
	char* get_surname();
	void set_name(char* name);
	char* get_name();
	std::string get_string();
	void SetFIO();
	bool operator <(FullName const& other);
	bool operator >(FullName const& other);
	void operator =(const FullName& other);
	bool operator ==(FullName const& other);
};


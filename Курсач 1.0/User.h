#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"
#include "Role.h"

class User
{
protected:
	FullName full_name;
	int ID;
	char login[30];
	char pasword[30];
	Role role;
public:
	User();
	User(User const & other);
	void operator =(User const & other);
	bool operator ==(User const& other);
	void set_full_name(FullName full_name);
	FullName get_full_name();
	void set_login(char* login);
	char* get_login();
	void set_pasword(char* pasword);
	char* get_pasword();
	Role get_role();
	void set_role(Role role);
	void generate_ID();
	int get_ID();
	void view();
	friend std::ofstream& operator << (std::ofstream& fout, User& user);
	friend std::ifstream& operator >> (std::ifstream& fin, User& user);
};

std::ofstream& operator << (std::ofstream& fout, User& user);
std::ifstream& operator >> (std::ifstream& fin, User& user);

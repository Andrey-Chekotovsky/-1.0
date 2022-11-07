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
	char login[30];
	char pasword[30];
	Role role;
public:
	
	void set_full_name(FullName full_name)
	{
		this->full_name = full_name;
	}
	FullName get_full_name()
	{
		return this->full_name;
	}
	void set_login(char* login)
	{
		strcpy_s(this->login, login);
	}
	char* get_login()
	{
		return this->login;
	}
	void set_pasword(char* pasword)
	{
		strcpy_s(this->pasword, pasword);
	} 
	char* get_pasword()
	{
		return this->pasword;
	}
	Role get_role()
	{
		return this->role;
	}
	void set_role(Role role)
	{
		this->role = role;
	}
};


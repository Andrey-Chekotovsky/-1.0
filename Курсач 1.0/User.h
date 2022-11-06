#pragma once
#include <exception>
#include <string>
#include "FullName.h"
#include "Exeptions.h"

class User
{
protected:
	FullName full_name;
	char login[30];
	char pasword[30];
	char UserID[40];
	void generate_UserID();
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
	void set_UserID(char* UserID)
	{
		strcpy_s(this->UserID, UserID);
	}
	char* get_UserID()
	{
		return this->UserID;
	}
};


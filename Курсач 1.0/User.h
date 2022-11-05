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
	virtual void meny();
	virtual void set_User();
	virtual void get_User();
	std::string get_login();
	std::string get_pasword();

};


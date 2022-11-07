#pragma once
#include "User.h"
#include "functions.h"
class UserControler
{
public:
	User user;
public:
	UserControler(User user)
	{
		this->user = user;
	}
	void set_User_full_name(FullName full_name)
	{
		user.set_full_name(full_name);
	}
	FullName get_User_full_name()
	{
		return user.get_full_name();
	}
	void set_User_login(char* login)
	{
		encrypt(login);
		user.set_login(login);
	}
	char* get_User_login()
	{
		char login[30];
		strcpy_s(login, user.get_login());
		encrypt(login);
		return user.get_login();
	}
	void set_User_pasword(char* pasword)
	{
		encrypt(pasword);
		user.set_pasword(pasword);
	}
	char* get_User_pasword()
	{
		char pasword[30];
		strcpy_s(pasword, user.get_pasword());
		encrypt(pasword);
		return pasword;
	}

	Role get_User_role()
	{
		return user.get_role();
	}
	void set_User_role(Role role)
	{
		user.set_role(role);
	}
};


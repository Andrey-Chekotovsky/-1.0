#include "User.h"
#include"functions.h"
User::User()
{
	strcpy_s(this->login, "None");
	strcpy_s(this->pasword, "None");
	role = Role::Customer;
	this->ID = -1;
}
User::User(User const & other)
{
	strcpy_s(this->login, other.login);
	strcpy_s(this->pasword, other.pasword);
	this->role = other.role;
	this->full_name = other.full_name;
	this->ID = other.ID;
}
void User::operator =(User const & other)
{
	strcpy_s(this->login, other.login);
	strcpy_s(this->pasword, other.pasword);
	this->role = other.role;
	this->full_name = other.full_name;
	this->ID = other.ID;
}
bool User::operator ==(User const& other)
{
	if (this->full_name == other.full_name)
		return true;
	return false;
}

void User::set_full_name(FullName full_name)
{
	this->full_name = full_name;
}
FullName User::get_full_name()
{
	return this->full_name;
}
void User::set_login(char* login)
{
	strcpy_s(this->login, login);
}
char* User::get_login()
{
	return this->login;
}
void User::set_pasword(char* pasword)
{
	strcpy_s(this->pasword, pasword);
}
char* User::get_pasword()
{
	return this->pasword;
}
Role User::get_role()
{
	return this->role;
}
void User::set_role(Role role)
{
	this->role = role;
}

void User::generate_ID()
{
	int ID;
	std::ifstream fin;
	fin.open(USER_ID_FILE);
	if (fin.read((char*)&ID, sizeof(int)))
	{
		fin.close();
		Update_ID_File(ID + 1, USER_ID_FILE);
		this->ID = ID + 1;
	}
	else
	{
		fin.close();
		Update_ID_File(1, USER_ID_FILE);
		this->ID = 0;
	}
}
int User::get_ID()
{
	return this->ID;
}

void User::view()
{
	std::cout << "Фамилия ИМя: " << this->full_name.get_string() << std::endl;
	std::cout << "Логин: " << this->login << std::endl;
	std::cout << "Роль: " << ident_role(this->role) << std::endl;
}

std::ofstream& operator << (std::ofstream& fout, User& user)
{
	fout.write((char*)&user, sizeof(User));
	return fout;
}
std::ifstream& operator >> (std::ifstream& fin, User& user)
{
	fin.read((char*)&user, sizeof(User));
	return fin;
}

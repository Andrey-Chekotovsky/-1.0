#pragma once
#include<string>
enum class Role
{
	Customer,
	Employee,
	Admin
};
std::string ident_role(Role role);


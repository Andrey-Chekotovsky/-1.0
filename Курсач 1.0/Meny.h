#pragma once
#include<map>
#include<vector>
#include "Role.h"

class Meny
{  
private:
	static std::map<Role, std::vector<bool>> mp;
public:
};

std::map<Role, std::vector<bool>> Meny::mp = { {Role::Customer, {false, false, false}},
	{Role::Employee, {false, false, false } },
	{Role::Admin, {false, false, false} } };

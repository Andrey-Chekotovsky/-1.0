#include "Role.h"

std::string ident_role(Role role)
{
	switch (role)
	{
	case Role::Customer: return "����������";
	case Role::Admin: return "�������������";
	case Role::Employee: return "��������";
	}
}
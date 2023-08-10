#include "Role.h"

std::string ident_role(Role role)
{
	switch (role)
	{
	case Role::Customer: return "Покупатель";
	case Role::Admin: return "Администратор";
	case Role::Employee: return "Работник";
	}
}
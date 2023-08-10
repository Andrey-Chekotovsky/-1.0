#pragma once
#include<map>
#include<vector>
#include<string>
#include<windows.h>
#include<winuser.h>
#include<conio.h>
#include "Role.h"
#include "User.h"
#include "Book.h"
#include"Task.h"
#include"Transaction.h"
#include"MenuButNot.h"


class Menu : public MenuButNot
{  
private:
	void smile() override
	{
		std::cout << " :)" << std::endl;
	}
public:
	static std::map<Role, std::vector<bool>> table_for_user_meny;
	static const std::vector<std::string> main_meny;
	static const std::vector<std::string> user_meny;
	static const std::vector<std::string> buy_meny;
	static const std::vector<std::string> reduct_user_meny;
	static const std::vector<std::string> reduct_task_meny;
	static const std::vector<std::string> reduct_book_meny;
	static const std::vector<std::string> modify_user_list_meny;
	static const std::vector<std::string> modify_task_list_meny;
	static const std::vector<std::string> modify_book_list_meny;
	static const std::vector<std::string> choose_role_menu;
	static const std::vector<std::string> conform_menu;
	static const std::vector<std::string> autorisation_menu;
	static void show_meny(std::vector<std::string> meny, int num, Role role);
	static int ident_comand_for_role(std::vector<std::string> meny, std::map<Role, std::vector<bool>> table, int num, Role role);


	static void show_main_menu();
	static void show_meny(std::vector<std::string> meny, int num);
	static int size_for_role(Role role);
	static void show_user_meny(User user);
	static void show_buy_meny(int userID, std::vector<Book>& books);
	static Role show_choose_role_menu();
	static void show_modify_user_list_meny();
	static void show_modify_book_list_meny();
	static void show_modify_task_list_meny();
	static void show_reduct_book_meny(Book& book);
	static void show_reduct_user_meny(User& user);
	static void show_reduct_task_meny(Task& task);
	static bool show_conform_menu(std::string question);
};




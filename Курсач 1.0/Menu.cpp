#include "Menu.h"
#include "functions.h"


std::map<Role, std::vector<bool>> Menu::table_for_user_meny = {
	{Role::Customer, {true, true, true, true, true, false, false, false, false, false } },
	{Role::Employee, {true, false, false, false, true, true, true, false, false, false } },
	{Role::Admin, {true, false, false, false, true, false, false, true, true, true } } };
const std::vector<std::string> Menu::main_meny = { "Выход", "Авторизация", "Регистрация" };
const std::vector<std::string> Menu::user_meny = { "Выход", "Смотреть список книг", "Купить", "Просмотреть историю покупок", "Редактировать профиль",
	"Смотреть задачи", "Изменить статус задачи на <выполнена>", "Редактировать список пользователей", "Редактировать список книг", "Редактирование задач" };

const std::vector<std::string> Menu::reduct_user_meny = { "Выход", "Редактировать полное имя", "Редактировать логин", "Редактировать пароль", "Откатиить изменение", "Вурнуть изменение" };
const std::vector<std::string> Menu::reduct_task_meny = { "Выход", "Редактировать задачу", "Изменить работника", "Откатиить изменение", "Вурнуть изменение" };
const std::vector<std::string> Menu::reduct_book_meny = { "Выход", "Редактировать название книги", "Редактировать имя и фамилию автора", "Редактировать цену", "Редактировать количество копий",
	"Редактировать описание", "Откатиить изменение", "Вурнуть изменение" };

const std::vector<std::string> Menu::buy_meny = { "Выход", "Добавить книгу", "Удалить книгу", "Оплатить" };

const std::vector<std::string> Menu::modify_user_list_meny = {"Выход", "Добавить пользователя", "Редактировать пользователя", "Удалить пользователя", "Список пользователей", 
	"Информация о пользователе" };
const std::vector<std::string> Menu::modify_task_list_meny = { "Выход", "Добавить звдвчу", "Редактировать задачу", "Удалить задачу", "Список задач",
	"Информация о задачах работника" };
const std::vector<std::string> Menu::modify_book_list_meny = { "Выход", "Добавить книгу", "Редактировать книгу", "Удалить книгу", "Список книг",
	"Информация о книге" };

const std::vector<std::string> Menu::choose_role_menu = { "Покупатель", "Работник", "Администратор" };
const std::vector<std::string> Menu::conform_menu = {"Да", "Нет"};

int Menu::size_for_role(Role role)
{
	int rez = 0;
	for (int i = 0; i < Menu::table_for_user_meny[role].size(); i++)
	{
		if (Menu::table_for_user_meny[role][i])
			rez++;
	}
	return rez;
}

void Menu::show_meny(std::vector<std::string> meny, int num)
{
	for (int i = 0; i < meny.size(); i++)
	{
		if (i == num)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 << 4 | 0);
			std::cout << meny[i] << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else
		{
			std::cout << meny[i] << std::endl;
		}
	}
}
void Menu::show_meny(std::vector<std::string> meny, int num, Role role)
{
	for (int i = 0, j = -1; i < meny.size(); i++)
	{
		if (!Menu::table_for_user_meny[role][i])
			continue;
		if (i == num)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 << 4 | 0);
			std::cout << meny[i] << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else
		{
			std::cout << meny[i] << std::endl;
		}
	}
}
int Menu::ident_comand_for_role(std::vector<std::string> meny, std::map<Role, std::vector<bool>> table, int num, Role role)
{
	for (int i = 0, j = -1; i < meny.size(); i++)
	{
		if (table[role][i])
			j++;
		else
			continue;
		if (j == num)
		{
			return i;
		}
	}
}


void Menu::show_main_menu()
{
	int switcher = 0;
	Keys keys;
	User user;
	Menu menu;
	UsualExeption excp;
	char login[30];
	char pas[30];
	while (true)
	{
		keys.all_false();
		system("cls");
		std::cout << "МЕНЮ";
		menu.smile();
		Menu::show_meny(Menu::main_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::main_meny, Menu::main_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			if (!keys.get_ent())
				continue;
			switch (switcher)
			{
			case 0:
				if (show_conform_menu("Вы действительно хотите выйти?"))
					return;
				else
					break;
			case 1:
				while (true){
					try
					{
						std::cout << "Введите логин" << std::endl;
						std::cin.clear();
						std::cin.getline(login, 30);
						user = find_User(login);
						break;
					}
					catch (FindException)
					{
						if (Menu::show_conform_menu("Пользователь не найден желаете заново ввести логин?"))
							continue;
						else
							throw excp;
					}
				}
				while (true) {
					std::cout << "Введите пароль" << std::endl;
					std::wcin.ignore(0);
					enter_pas(login);
					decrypt(user);
					strcpy_s(pas, user.get_pasword());
					encrypt(user);
					if (compare_сhar(login, pas) == 0)
						break;
					if (Menu::show_conform_menu("Пороль неверный, хотите ввести заново?"))
						continue;
					else
						throw excp;

				}
				Menu::show_user_meny(user);
				break;
			case 2:
				user = create_user(Role::Customer);
				save_user(user);
				break;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (UsualExeption)
		{
			std::cout << UsualExeption::what() << std::endl;
		}
		catch (...)
		{

		}
	}
}
void Menu::show_user_meny(User user)
{
	int num = 0;
	int switcher = 0;
	std::vector<Task> tasks;
	std::vector<Book> books;
	Keys keys;
	while (true) 
	{
		keys.all_false();
		system("cls");
		std::wcout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ" << std::endl;
		Menu::show_meny(Menu::user_meny, switcher, user.get_role());
		try
		{
			process_keys(keys, switcher, Menu::user_meny, user.get_role());
			if (keys.get_bot() || keys.get_top())
				continue;
			if (!keys.get_ent())
				continue;
			switch (switcher)
			{
			case 0:
				return;
			case 1:
				books = create_mas<Book>();
				show_all_books(books);
				books.clear();
				break;
			case 2:
				books = create_mas<Book>();
				Menu::show_buy_meny(user.get_ID(), books);
				save_change(books);
				books.clear();
				break;
			case 3:
				show_user_purchases(user.get_ID());
				break;
			case 4:
				Menu::show_reduct_user_meny(user);
				update_user(user);
				break;
			case 5:
				tasks = create_mas<Task>();
				show_all_user_tasks(tasks, user.get_ID());
				break;
			case 6:
				tasks = create_mas<Task>();
				choose_task(tasks, user.get_ID())->make_complete();
				save_change(tasks);
				tasks.clear();
				break;
			case 7:
				Menu::show_modify_user_list_meny();
				break;
			case 8:
				Menu::show_modify_book_list_meny();
				break;
			case 9:
				Menu::show_modify_task_list_meny();
				break;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{

		}
		wait();
	}
}
void Menu::show_buy_meny(int userID, std::vector<Book>& mas)
{
	int switcher = 0;
	int num;
	Purchase purch;
	Book* book;
	std::vector<Book> books;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::wcout << "МЕНЮ ЗАКАЗОВ" << std::endl;
		Menu::show_meny(Menu::buy_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::buy_meny, Menu::buy_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			switch (switcher)
			{
			case 0:
				purch.return_all_books(mas);
				return;
			case 1:
				book = choose_book(mas);
				std::cout << "Введите количество" << std::endl;
				num = input_int();
				if (num > book->get_num_of_copies())
				{
					std::cout << "Добавление невозможно: недостаточно копий на складе" << std::endl;
					break;
				}
				purch.add(*book, num);
				break;
			case 2:
				for (int i = 0; i < purch.get_num(); i++)
				{
					books.push_back(find_book_by_ID(mas, purch.get_book_ID(i)));
				}
				book = choose_book(books);
				for (int i = 0; i < mas.size();i++)
				{
					if (mas[i].get_ID() == book->get_ID())
						mas[i].set_num_of_copies(mas[i].get_num_of_copies() + purch.return_books(*book));
				}
				break;
			case 3:
				purch.set_costomerID(userID);
				save_purchase(purch);
				return;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{

		}
	}
}
void Menu::show_modify_user_list_meny()
{
	std::vector<User> mas;
	mas = create_mas<User>();
	int switcher = 0;
	User user;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::wcout << "МЕНЮ МОДИФИКАЦИИ" << std::endl;
		Menu::show_meny(Menu::modify_user_list_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::modify_user_list_meny, Menu::modify_user_list_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			if (!keys.get_ent())
				continue;
			switch (switcher)
			{
			case 0:
				save_change(mas);
				return;
			case 1:
				mas.push_back(create_user(Menu::show_choose_role_menu()));
				break;
			case 2:
				Menu::show_reduct_user_meny(*(choose_user(mas)));
				break;
			case 3:
				delete_element(mas, *(choose_user(mas)));
				break;
			case 4:
				show_all_users(mas);
				break;
			case 5:
				mas[find_User(mas)].view();
				break;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{

		}
		wait();
	}
}
void Menu::show_modify_book_list_meny()
{
	std::vector<Book> mas;
	mas = create_mas<Book>();
	int switcher = 0;
	Book book;
	Keys keys;
	
	while (true)
	{
		keys.all_false();
		system("cls");
		std::wcout << "МЕНЮ МОДИФИКАЦИИ" << std::endl;
		Menu::show_meny(Menu::modify_book_list_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::modify_book_list_meny, Menu::modify_book_list_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			if (!keys.get_ent())
				continue;
			switch (switcher)
			{
			case 0:
				save_change(mas);
				return;
			case 1:
				mas.push_back(create_book());
				break;
			case 2:
				Menu::show_reduct_book_meny(*(choose_book(mas)));
				break;
			case 3:
				book = *(choose_book(mas));
				book_to_del_file(book);
				delete_element(mas, book);
				break;
			case 4:
				mas[find_book(mas)].view();
				break;
			case 5:
				show_all_books(mas);
				break;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{

		}
		wait();
	}
}
void Menu::show_modify_task_list_meny()
{
	std::vector<Task> mas;
	mas = create_mas<Task>();
	int switcher = 0;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::wcout << "МЕНЮ МОДИФИКАЦИИ" << std::endl;
		Menu::show_meny(Menu::modify_task_list_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::modify_task_list_meny, Menu::modify_task_list_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			if (!keys.get_ent())
				continue;
			switch (switcher)
			{
			case 0:
				save_change(mas);
				return;
			case 1:
				mas.push_back(create_task());
				break;
			case 2:
				Menu::show_reduct_task_meny(*(choose_task(mas)));
				break;
			case 3:
				delete_element(mas, *(choose_task(mas)));
				break;
			case 4:
				show_all_tasks(mas);
				break;
			case 5:
				show_all_user_tasks(mas);
				break;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{

		}
		wait();
	}
}
void Menu::show_reduct_book_meny(Book& book)
{
	fy::Transaction<Book> trans(book);
	char word[30], description[500];
	FullName full_name;
	int copies;
	int switcher = 0;
	float price;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		book.view();
		std::wcout << "МЕНЮ РЕДАКТИРОВАНИЯ" << std::endl;
		Menu::show_meny(Menu::reduct_book_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::reduct_book_meny, Menu::reduct_book_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			switch (switcher)
			{
			case 0:
				book = trans.get_data();
				return;
			case 1:
				std::cout << "Введите название книги" << std::endl;
				std::cin.ignore();
				std::cin.get(word, 30);
				book.set_book_name(word);
				break;
			case 2:
				std::cout << "Введите фамилию автора" << std::endl;
				std::cin.ignore();
				std::cin.get(word, 30);
				full_name.set_surname(word);
				std::cout << "Введите имя автора" << std::endl;
				std::cin.ignore();
				std::cin.get(word, 30);
				full_name.set_name(word);
				book.set_Author_name(full_name);
				break;
			case 3:
				std::cout << "Введите цену" << std::endl;
				price = input_float();
				book.set_price(price);
				break;
			case 4:
				std::cout << "Введите количество копий" << std::endl;
				copies = input_int();
				book.set_num_of_copies(copies);
				break;
			case 5:
				std::cout << "Введите описание" << std::endl;
				std::cin.ignore();
				std::cin.get(description, 500);
				book.set_book_name(description);
				break;
			case 6:
				trans.go_previous_state();
				book = trans.get_data();
				break;
			case 7:
				trans.go_next_state();
				book = trans.get_data();
				break;
			}
			if (switcher == 7 || switcher == 6)
				continue;
			trans.Update(book);
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (TransactionPreviousException)
		{
			std::cout << TransactionPreviousException::what() << std::endl;
		}
		catch (TransactionNextException)
		{
			std::cout << TransactionNextException::what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Ошибка" << std::endl;
		}
		wait();
	}
}
void Menu::show_reduct_user_meny(User& user)
{
	fy::Transaction<User> trans(user);
	char word[30];
	FullName full_name;
	int switcher = 0;
	Keys keys;
	char pas[30];
	char check_pas[30];
	while (true)
	{
		keys.all_false();
		system("cls");
		user.view();
		std::wcout << "МЕНЮ РЕДАКТИРОВАНИЯ" << std::endl;
		Menu::show_meny(Menu::reduct_user_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::reduct_user_meny, Menu::reduct_user_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			switch (switcher)
			{
			case 0:
				user = trans.get_data();
				return;
			case 1:
				std::cout << "Введите фамилию" << std::endl;
				std::cin.get(word, 30);
				full_name.set_surname(word);
				std::cout << "Введите имя" << std::endl;
				std::cin.get(word, 30);
				full_name.set_name(word);
				user.set_full_name(full_name);
				break;
			case 2:
				std::cout << "Введите новый логин" << std::endl;
				std::cin.get(word, 30);
				user.set_login(word);
				break;
			case 3:
				while (true) {
					std::cout << "Введите пароль" << std::endl;
					std::cin.ignore();
					enter_pas(pas);
					std::cout << "Повторите ввод" << std::endl;
					enter_pas(check_pas);
					if (compare_сhar(check_pas, pas) == 0)
						break;
					if (Menu::show_conform_menu("Пороли не совпали, хотите ввести заново?"))
						continue;
					else
						break;
				}
				break;
			case 4:
				trans.go_previous_state();
				user = trans.get_data();
				break;
			case 5:
				trans.go_next_state();
				user = trans.get_data();
				break;
			}
			if (switcher == 4 || switcher == 5)
				continue;
			trans.Update(user);
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (TransactionPreviousException)
		{
			std::cout << TransactionPreviousException ::what() << std::endl;
		}
		catch (TransactionNextException)
		{
			std::cout << TransactionNextException::what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Ошибка" << std::endl;
		}
		wait();
	}
}
void Menu::show_reduct_task_meny(Task& task)
{
	fy::Transaction<Task> trans(task);
	char word[400];
	FullName full_name;
	int switcher = 0;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		task.view();
		std::wcout << "МЕНЮ РЕДАКТИРОВАНИЯ" << std::endl;
		Menu::show_meny(Menu::reduct_task_meny, switcher);
		try
		{
			process_keys(keys, switcher, Menu::reduct_task_meny, Menu::reduct_task_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			switch (switcher)
			{
			case 0:
				task = trans.get_data();
				return;
			case 1:
				std::cout << "Введите новое задани" << std::endl;
				std::cin.ignore();
				std::cin.get(word, 400);
				task.set_task(word);
				break;
			case 2:
				task.set_userID(choose_employee_for_task());
				break;
			case 3:
				trans.go_previous_state();
				task = trans.get_data();
				break;
			case 4:
				trans.go_next_state();
				task = trans.get_data();
				break;
			}
			if (switcher == 3 || switcher == 4)
				continue;
			trans.Update(task);
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (TransactionPreviousException)
		{
			std::cout << TransactionPreviousException::what() << std::endl;
		}
		catch (TransactionNextException)
		{
			std::cout << TransactionNextException::what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Ошибка" << std::endl;
		}
		wait();
	}
}


Role Menu::show_choose_role_menu()
{
	int switcher = 0;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		Menu::show_meny(Menu::choose_role_menu, switcher);
		try
		{
			process_keys(keys, switcher, Menu::choose_role_menu, Menu::reduct_user_meny.size());
			if (keys.get_bot() || keys.get_top())
				continue;
			switch (switcher)
			{
			case 0:
				return Role::Customer;
			case 1:
				return Role::Employee;
			case 2:
				return Role::Admin;
			}
		}
		catch (EscException)
		{
			std::cout << EscException::what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Ошибка" << std::endl;
		}
		wait();
	}
}
bool Menu::show_conform_menu(std::string question)
{
	int switcher = 0;
	Keys keys;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::cout << question << std::endl;
		Menu::show_meny(Menu::conform_menu, switcher);
		process_keys(keys, switcher, Menu::conform_menu, Menu::conform_menu.size());
		if (keys.get_bot() || keys.get_top())
			continue;
		if (!keys.get_ent())
			continue;
		switch (switcher)
		{
		case 0:
			return true;
		case 1:
			return false;
		}
	}
}
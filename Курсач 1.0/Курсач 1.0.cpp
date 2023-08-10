#include <iostream>
#include <windows.h>
#include <conio.h>
#include <exception>
#include <fstream>
#include "Menu.h"
#include"functions.h"


void create_files()
{
    std::ofstream fout;
    fout.open(USER_FILE, std::ofstream::app);
    fout.close();
    fout.open(BOOK_FILE, std::ofstream::app);
    fout.close();
    fout.open(BOOK_DEL_FILE, std::ofstream::app);
    fout.close();
    fout.open(TASK_FILE, std::ofstream::app);
    fout.close();
    fout.open(BOOK_ID_FILE, std::ofstream::app);
    fout.close();
    fout.open(USER_ID_FILE, std::ofstream::app);
    fout.close();
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    User user;
    create_files();
    try {
        if (is_empty(USER_FILE))
        {
            if (Menu::show_conform_menu("В системе отсутствует админ. Желаете ли вы его назначить?"))
            {
                user = create_user(Role::Admin);
                save_user(user);
            }
            else
            {
                std::cout << "Программа была прервана" << std::endl;
                return 1;
            }
        }
    }
    catch (EscException)
    {
        return 1;
    }
    Menu::show_main_menu();
}



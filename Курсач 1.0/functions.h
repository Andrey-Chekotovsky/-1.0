#pragma once
#include"Purchase.h"
#include<string>
#include<memory>
#include<fstream>
#include<vector>
#include<conio.h>
#include "Menu.h"
#include "User.h"
#include"Keys.h"
#include"Task.h"
#include <iomanip>
#include<memory>


const std::string USER_FILE = "User.txt";
const std::string PURCHASE_FILE = "Purchase.txt";
const std::string BOOK_FILE = "Book.txt";
const std::string BOOK_DEL_FILE = "BookDEL.txt";
const std::string TASK_FILE = "Task.txt";
const std::string USER_DEL_FILE = "UserDEL.txt";
const std::string USER_ID_FILE = "UserID.txt";
const std::string BOOK_ID_FILE = "BookID.txt";

bool is_empty(std::string name_of_file);

std::string check_type(User);
std::string check_type(Book);
std::string check_type(Purchase);
std::string check_type(Task);


template <class T>
void delete_element(std::vector<T>& mas, T element)
{
    bool conform;
    int del_num;
    EscException excp;
    if (!Menu::show_conform_menu("Вы подтверждаете что хотите удалить объект?"))
        throw excp;
    for (int i = 0; i < mas.size(); i++)
    {
        if (element == mas[i])
            del_num = i;
    }

    typename std::vector<T>::iterator it = mas.begin() + del_num;
    mas.erase(it);
    std::cout << "Удаление успешно выполнено" << std::endl;
}
template <class T>
std::vector<T> create_mas()
{
    std::vector<T> mas;
    std::ifstream fin;
    T obj;
    fin.open(check_type(obj));
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        throw;
    }
    while (fin.read((char*)&obj, sizeof(T)))
    {
        mas.push_back(obj);
    }
    fin.close();
    return mas;
}
template <class T>
void save_change(std::vector<T> mas)
{
    std::ofstream fout;
    T obj;
    fout.open(check_type(obj));
    for (int i = 0; i < mas.size(); i++)
    {
        fout.write((char*)&mas[i], sizeof(T));
    }
    fout.close();
}   


void process_keys(Keys& keys, int& num, std::vector<std::string> vect, int size);
void process_keys(Keys& keys, int& num, std::vector<std::string> vect, Role role);
enum Mode;
void encrypt(User& user);
void decrypt(User& user);
void wait();
int input_int();
float input_float();

User create_user(Role role);
int choose_employee_for_task();
Task create_task();
Book create_book();
std::string check_type(User);
std::string check_type(Book);
std::string check_type(Purchase);

User* choose_user(std::vector<User>& mas);
std::string get_string(Task task);
Task* choose_task(std::vector<Task>& mas);
Task* choose_task(std::vector<Task>& mas, int user_ID);
std::string get_string(Book book);
Book* choose_book(std::vector<Book>& mas);

void make_line(int num);
void show_all_users(std::vector<User> mas);
void show_all_books(std::vector<Book> mas);
void show_all_tasks(std::vector<Task> mas);
void show_all_user_tasks(std::vector<Task> mas);
void show_all_user_tasks(std::vector<Task> mas, int userID);

Book find_book_by_ID(std::vector<Book> mas, int ID);
Book find_book_by_ID(int ID);
int enter_pas(char* pass);
void save_user(User user);
void save_purchase(Purchase& purch);
void show_user_purchases(int user_ID);
int compare_сhar(char origin[30], char compare[30]);
User find_User(char* login);
User find_User(int ID);
int find_User(std::vector<User> mas);
void user_to_del_file(User user);
void book_to_del_file(Book book);
int find_book(std::vector<Book> mas);
void Update_ID_File(int New_ID, std::string ID_file);
void update_user(User user);
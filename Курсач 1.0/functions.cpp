#include "functions.h"



void wait()
{
    char a;
    std::cout << "Нажмите любую клавишу, чтобы продолжить..." << std::endl;
    a = _getch();
}

std::shared_ptr<User> create_user()
{
    std::shared_ptr<User> ptr(new User);
    return ptr;
}

bool is_empty(std::string name_of_file)
{
    std::ofstream fout;
    fout.open(name_of_file, std::ofstream::app);
    fout.seekp(0, std::ios_base::end);
    if (0 == fout.tellp())
        return true;
    else
        return false;
}

void encrypt(User& user)
{
    int size = strlen(user.get_pasword());
    char pas[30];
    strcpy_s(pas, user.get_pasword());
    for (int i = 0; i < size; i++)
    {
        pas[i] = char(user.get_ID() + 1 + int(pas[i]));
    }
    user.set_pasword(pas);
}
void decrypt(User& user)
{
    int size = strlen(user.get_pasword());
    char pas[30];
    strcpy_s(pas, user.get_pasword());
    for (int i = 0; i < size; i++)
    {
        pas[i] = char(int(pas[i]) - user.get_ID() - 1);
    }
    user.set_pasword(pas);
}
int input_int()
{
    int num;
    while (true)
    {
        std::cin >> num;
        if (std::cin.good())
            break;
        std::cin.clear();
        std::cout << "некоректный ввод" << std::endl;
        std::cin.ignore();
    }
    return num;
}
float input_float()
{
    float num;
    while (true)
    {
        std::cin >> num;
        if (std::cin.good())
            break;
        std::cin.clear();
        std::cout << "некоректный ввод" << std::endl;
        std::cin.ignore();
    }
    return num;
}
std::string check_type(User)
{
    return USER_FILE;
}
std::string check_type(Book)
{
    return BOOK_FILE;
}
std::string check_type(Purchase)
{
    return PURCHASE_FILE;
}
std::string check_type(Task)
{
    return TASK_FILE;
}





void process_keys(Keys& keys, int& num, std::vector<std::string> vect, int size)
{
    int a;
    EscException excp;
    while (true)
    {
        a = int(_getch());
        if (a == 72)
        {
            if (num - 1 > -1)
            {
                keys.set_top(true);
                num--;
                break;
            }
        }
        else if (a == 80)
        {
            if (num != vect.size() - 1)
            {
                keys.set_bot(true);
                num++;
                break;
            }
        }
        else if (a == 13)
        {
            keys.set_ent(true);
            break;
        }
        else if (a == 27)
        {
            throw excp;
        }
    }
}
void process_keys(Keys& keys, int& num, std::vector<std::string> vect, Role role)
{
    process_keys(keys, num, vect, vect.size());
    while (!Menu::table_for_user_meny[role][num])
    {
        if (keys.get_bot())
            num++;
        if (keys.get_top())
            num--;
    }
}

template <typename T>
int choose(std::vector<T> mas)
{
    std::vector<std::string> str_mas;
    for (int i = 0; i < mas.size; i++)
    {
        str_mas.push_back(get_string(mas[i]));
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        std::cout << "Выберите нужный объект" << std::endl;
        Menu::show_meny(str_mas, switcher);
        process_keys(keys, switcher, str_mas, str_mas.size());
        if (keys.get_ent())
            break;
    }
    return switcher;
}

Book create_book()
{
    Book book;
    FullName Author_name;
    char book_name[40];
    char description[500];
    int num_of_copies;
    float price;
    std::cin.ignore(1, '\n');
    std::cout << "Введите данные автора" << std::endl;
    Author_name.SetFIO();
    std::cout << "Введите название книиги" << std::endl;
    std::cin.ignore(1, '\n');
    std::cin.getline(book_name, 40);
    std::cout << "Введите описание" << std::endl;
    std::cin.ignore(1, '\n');
    std::cin.getline(description, 500);
    std::cout << "Введите Количество копий" << std::endl;
    while (true) {
        num_of_copies = input_int();
        if (num_of_copies >= 0)
            break;
        std::cout << "Копий не может быть меньше нуля" << std::endl;
    }
    while (true) {
        std::cout << "Введите цену" << std::endl;
        price = input_float();
        if (price > 0)
            break;
        std::cout << "Цена не может быть ниже нуля" << std::endl;
    }
    book.set_Author_name(Author_name);
    book.set_book_name(book_name);
    book.set_description(description);
    book.set_num_of_copies(num_of_copies);
    book.set_price(price);
    book.generate_ID();
    return book;

}
User create_user(Role role)
{
    User user;
    FullName full_name;
    EscException excp;
    char login[30];
    char pasword[30];
    char check_pasvord[30];
    full_name.SetFIO();
    std::cout << "Введите логин" << std::endl;
    std::cin.ignore();
    std::cin.get(login, 30);
    std::cin.ignore();
    while(true) {
        std::cout << "Введите пароль" << std::endl;
        enter_pas(pasword);
        std::cout << "Повторите ввод" << std::endl;
        enter_pas(check_pasvord);
        if (compare_сhar(check_pasvord, pasword) == 0)
            break;
        if (Menu::show_conform_menu("Ввод не совпадает, желаете попробовать снова?"))
            continue;
        else
            throw excp;
    } 
    user.set_full_name(full_name);
    user.set_login(login);
    user.set_pasword(pasword);
    user.set_role(role);
    user.generate_ID();
    encrypt(user);
    return user;
}
int choose_employee_for_task()
{
    std::vector<User> users;
    std::vector<User> use_users;
    users = create_mas<User>();
    for (std::vector<User>::iterator it = users.begin(); it != users.end(); it++)
    {
        if (it->get_role() == Role::Employee)
        {
            use_users.push_back(*it);
        }
    }
    return choose_user(use_users)->get_ID();
}
Task create_task()
{
    int ID = choose_employee_for_task();
    char task_text[400];
    std::cout << "Введите задачу" << std::endl;
    std::cin.ignore();
    std::cin.get(task_text, 400);
    Task task(task_text, ID);
    return task;
}


User* choose_user(std::vector<User>& mas)
{
    std::vector<std::string> string_mas;
    for (int i = 0; i < mas.size(); i++)
    {
        string_mas.push_back(mas[i].get_full_name().get_string());
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        Menu::show_meny(string_mas, switcher);
        process_keys(keys, switcher, string_mas, string_mas.size());
        if (keys.get_ent())
            break;
    }
    return &(mas[switcher]);
}
std::string get_string(Task task)
{
    std::string rezult = task.get_task();
    return rezult;
}
Task* choose_task(std::vector<Task>& mas)
{
    std::vector<std::string> string_mas;
    for (int i = 0; i < mas.size(); i++)
    {
        string_mas.push_back(get_string(mas[i]));
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        Menu::show_meny(string_mas, switcher);
        process_keys(keys, switcher, string_mas, string_mas.size());
        if (keys.get_ent())
            return &mas[switcher];
    }
}
Task* choose_task(std::vector<Task>& mas, int user_ID)
{
    std::vector<std::string> string_mas;
    std::vector<Task*> user_tasks;
    for (int i = 0; i < mas.size(); i++)
    {
        if (mas[i].get_userID() == user_ID)
        {
            string_mas.push_back(get_string(mas[i]));
            user_tasks.push_back(&mas[i]);
        }
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        Menu::show_meny(string_mas, switcher);
        process_keys(keys, switcher, string_mas, string_mas.size());
        if (keys.get_ent())
            return user_tasks[switcher];
    }
}
std::string get_string(Book book)
{
    return book.get_book_name();
}
Book* choose_book(std::vector<Book>& mas)
{
    std::vector<std::string> string_mas;
    for (int i = 0; i < mas.size(); i++)
    {
        string_mas.push_back(get_string(mas[i]));
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        Menu::show_meny(string_mas, switcher);
        process_keys(keys, switcher, string_mas, string_mas.size());
        if (keys.get_ent())
            break;
    }
    return &(mas[switcher]);
}



void make_line(int num)
{
    for (int i = 0; i <= num; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}
void show_all_users(std::vector<User> mas)
{
    make_line(114);
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(2) << "№";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(40) << std::left << "Фамилия Имя ";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(30) << std::right << "Логин" << "|";
    std::cout << std::setw(32) << std::right << "Приоритет" << "|";
    std::cout << std::setw(5) << std::right << "ID" << "|" << std::endl;
    for (int i = 0; i < mas.size(); i++)
    {
        make_line(114);
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(2) << i + 1;
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(40) << std::left << mas[i].get_full_name().get_string();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(30) << std::right << mas[i].get_login();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(32) << ident_role(mas[i].get_role());
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(5) << mas[i].get_ID();
        std::cout << std::setw(1) << "|" << std::endl;
    }
    make_line(114);
}
void show_all_books(std::vector<Book> mas)
{
    int num = 96;
    make_line(num);
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(2) << "№";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(30) << std::left << "Фамилия Имя автора";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(30)  << "Названее" << "|";
    std::cout << std::setw(16) << "Количество копий" << "|";
    std::cout << std::setw(8) << "Цена" << "|";
    std::cout << std::setw(5)  << "ID" << "|" << std::endl;
    for (int i = 0; i < mas.size(); i++)
    {
        make_line(num);
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(2) << i + 1;
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(30) << std::left << mas[i].get_Author_name().get_string();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(30) << mas[i].get_book_name();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(16) << mas[i].get_num_of_copies();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(8) << mas[i].get_price();
        std::cout << std::setw(1) << "|";
        std::cout << std::setw(5) << mas[i].get_ID();
        std::cout << std::setw(1) << "|" << std::endl;
    }
    make_line(num);
}
void show_all_tasks(std::vector<Task> mas)
{
    for (int i = 0; i < mas.size(); i++)
    {
        std::wcout << i + 1 << ". " << mas[i].get_task() << std::endl;
    }
}
void show_all_user_tasks(std::vector<Task> mas)
{
    int ID = choose_employee_for_task();
    show_all_user_tasks(mas, ID);
}
void show_all_user_tasks(std::vector<Task> mas, int userID)
{
    for (int i = 0, j = 1; i < mas.size(); i++)
    {
        if (userID == mas[i].get_userID())
        {
            std::wcout << j << ". " << mas[i].get_task() << std::endl;
            j++;
        }
    }
}

Book find_book_by_ID(std::vector<Book> mas, int ID)
{
    for (int i = 0; i < mas.size(); i++)
    {
        if (ID = mas[i].get_ID())
            return mas[i];
    }
}
int enter_pas(char* pass)  
{
    int counter = 0;
    int ch = 0;
    while (true)
    {
        ch = _getch();
        if (ch == 13)
        {
            break;
        }
        if (ch == 27)
        {
            exit(0);
        }
        if (ch == 8)
        {

            std::cout << (char)8 << ' ' << char(8);

            if (counter > 0)
            {
                pass[counter] = '\0';
                counter--;
            }
        }
        else
        {
            std::cout << '*';
            pass[counter] = (char)ch;
            counter++;
        }
    }
    pass[counter] = '\0';
    std::cout << std::endl;
    return 0;
}
void save_user(User user)
{
    std::ofstream fout;
    fout.open(USER_FILE, std::ofstream::app);
    fout.write((char*)&user, sizeof(User));
    fout.close();
}
void save_purchase(Purchase& purch)
{
    std::ofstream fout;
    fout.open(PURCHASE_FILE, std::ofstream::app);
    fout.write((char*)&purch, sizeof(Purchase));
    fout.close();
}
void show_user_purchases(int user_ID)
{
    std::ifstream fin;
    Purchase purch;
    int num = 35;
    fin.open(PURCHASE_FILE);
    make_line(num);
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(2) << "№";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(15) << std::left << "Куплено книг";
    std::cout << std::setw(1) << "|";
    std::cout << std::setw(15) << std::right << "Цена" << "|" << std::endl;
    for (int i = 0, j = 1; fin.read((char*)&purch, sizeof(Purchase)); i++)
    {
        if (purch.get_costomerID() == user_ID)
        {
            make_line(num);
            std::cout << std::setw(1) << "|";
            std::cout << std::setw(2) << j;
            std::cout << std::setw(1) << "|";
            std::cout << std::setw(15) << std::left << purch.get_number_of_books();
            std::cout << std::setw(1) << "|";
            std::cout << std::setw(15) << std::right << purch.get_price();
            std::cout << std::setw(1) << "|" << std::endl;
            j++;
        }
    }
    make_line(num);
}
int compare_сhar(char origin[30], char compare[30])  
{
    int symb = 0;
    int size = 0;
    if (strlen(compare) <= strlen(origin))
        size = strlen(compare);
    else
        size = strlen(origin);
    while (symb < size)
    {
        if ((int)origin[symb] < (int)compare[symb])
            return -1;
        else if ((int)origin[symb] > (int)compare[symb])
            return 1;
        symb++;
    }
    if (strlen(compare) < strlen(origin))
        return -1;
    if (strlen(compare) > strlen(origin))
        return 1;
    return 0;
}
User find_User(char* login)
{
    User user;
    FileException file_excp;
    FindException find_excp;
    std::ifstream fin;
    fin.open(USER_FILE);
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия базы данных" << std::endl;
        throw file_excp;
    }
    while (fin >> user)
    {
        if (compare_сhar(login, user.get_login()) == 0)
            return user;
    }
    throw find_excp;
}
User find_User(int ID)
{
    User user;
    FileException file_excp;
    FindException find_excp;
    std::ifstream fin;
    fin.open(USER_FILE);
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия базы данных" << std::endl;
        throw file_excp;
    }
    while (fin.read((char*)&user, sizeof(User)))
    {
        if (user.get_ID() == ID)
            return user;
    }
    throw find_excp;
}
int find_User(std::vector<User> mas) 
{
    char login[30];
    FindException excp;
    std::wcout << "Введите логин" << std::endl;
    std::wcin.ignore();
    std::cin.get(login, 40);
    for (int i = 0; i < mas.size(); i++)
    {
        if (compare_сhar(mas[i].get_login(), login) == 0)
        {
            return i;
        }
    }
    throw excp;
}

void user_to_del_file(User user)
{
    std::ofstream fout;
    fout.open(USER_DEL_FILE, std::ofstream::app);
    fout.write((char*)&user, sizeof(User));
    fout.close();
}
void book_to_del_file(Book book)
{
    std::ofstream fout;
    fout.open(BOOK_DEL_FILE, std::ofstream::app);
    fout.write((char*)&book, sizeof(Book));
    fout.close();
}
Book find_book_by_ID(int ID)
{
    Book book;
    FileException file_excp;
    FindException find_excp;
    std::ifstream fin;
    fin.open(BOOK_FILE);
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия базы данных" << std::endl;
        throw file_excp;
    }
    while (fin.read((char*)&book, sizeof(Book)))
    {
        if (ID = book.get_ID())
            return book;
    }
    fin.close();
    fin.open(BOOK_DEL_FILE);
    while (fin.read((char*)&book, sizeof(Book)))
    {
        if (ID = book.get_ID())
            return book;
    }
    throw find_excp;
}
int find_book(std::vector<Book> mas)
{
    char name[40];
    FindException excp;
    std::wcout << "Введите название книги" << std::endl;
    std::cin.clear();
    std::cin.getline(name, 40);
    for (int i = 0; i < mas.size(); i++)
    {
        if (compare_сhar(mas[i].get_book_name(), name) == 0)
        {
            return i;
        }
    }
    throw excp;
}
void Update_ID_File(int New_ID, std::string ID_file)
{
    std::ofstream fout;
    fout.open(ID_file);
    fout.write((char*)&New_ID, sizeof(int));
    fout.close();
}
void update_user(User user)
{
    std::vector<User> mas = create_mas<User>();
    for (int i = 0; i < mas.size(); i++)
    {
        if (mas[i].get_ID() == user.get_ID())
        {
            mas[i] = user;
            break;
        }
    }
    save_change(mas);
}
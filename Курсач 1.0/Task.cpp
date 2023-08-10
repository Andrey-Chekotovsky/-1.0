#include "Task.h"
#include"functions.h"

Task::Task()
{
	this->coomplete = false;
	strcpy_s(this->task, "None");
	this->UserID = -1;
}
Task::Task(char* task, int UserID)
{
	this->coomplete = false;
	strcpy_s(this->task, task);
	this->UserID = UserID;
}
void Task::set_task(char* task)
{
	strcpy_s(this->task, task);
}
char* Task::get_task()
{
	return this->task;
}
void Task::set_userID(int UserID)
{
	this->UserID = UserID;
}
int Task::get_userID()
{
	return this->UserID;
}
void Task::make_complete()
{
	this->coomplete = true;
}
Task::Task(Task const& other)
{
	strcpy_s(this->task, other.task);
	this->UserID = other.UserID;
	this->coomplete = other.coomplete;
}
void Task::operator =(Task const& other)
{
	strcpy_s(this->task, other.task);
	this->UserID = other.UserID;
	this->coomplete = other.coomplete;
}
bool Task::operator ==(Task const& other)
{
	int symb = 0;
	if (strlen(this->task) != strlen(other.task))
	{
		return false;
	}
	for (symb; symb < strlen(other.task); symb++)
	{
		if (int(this->task[symb]) != int(other.task[symb]))
			return false;
	}

	return true;
}
void Task::view()
{
	std::cout << "Работник: " << this->task << std::endl;
	std::cout << "Задача: " << find_User(this->UserID).get_full_name().get_string() << std::endl;
}
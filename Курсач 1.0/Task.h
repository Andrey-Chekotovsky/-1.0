#pragma once
#include<iostream>
#include<string>
#include"User.h"

class Task
{
private:
	int UserID;
	char task[400];
	bool coomplete;
public:
	Task();
	Task(char* task, int UserUD);
	Task(Task const& other);
	void operator =(Task const& other);
	bool operator ==(Task const& other);
	void set_task(char* task);
	char* get_task();
	void set_userID(int UserID);
	int get_userID();
	void make_complete();
	void view();
};


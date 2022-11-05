#pragma once
#include <iostream>
#include <string> 
#include <memory>

template <class T>
class Transaction  
{
	T data;
	std::shared_ptr<Transaction> previous;
	std::shared_ptr<Transaction> next;
	Transaction(T object);
	Transaction* Update(T object);
	std::shared_ptr<Transaction> go_previous_state();
	std::shared_ptr<Transaction> go_next_state();
	T get_data();
};


#pragma once
#include <iostream>
#include <string> 
#include <memory>

template <class T>
class Transaction  // комментарий
{
	T data;
	std::shared_ptr<Transaction> previous;
	std::shared_ptr<Transaction> next;
	Transaction(T object)
	{
		data = object;
		this->previous = NULL;
		this->next = NULL;
	}
	Transaction* Update(T object)
	{
		Transaction* trans = new Transaction(object);
		if (this->next != NULL)
		{
			this->next.~shared_ptr();
		}
		trans->previous = this;
		this->next = trans;
		trans->next = NULL;
		return trans;
	}
	std::shared_ptr<Transaction> go_previous_state()
	{
		if(this->previous != NULL)
			return this->previous;
	}
	std::shared_ptr<Transaction> go_next_state()
	{
		if (this->next != NULL)
			return this->next;
	}
	T get_data()
	{
		return this->data;
	}
};


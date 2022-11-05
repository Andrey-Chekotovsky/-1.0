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
	void Update(T object)
	{
		this->previous = current;
		this->current.reset(new T(object));
	}
	std::shared_ptr<T> Get_previous_state()
	{
		return this->previous;
	}
	std::shared_ptr<T> Get_current_state()
	{
		return this->current;
	}
	void Go_back()
	{
		this->current.~shared_ptr();
		this->current = this->previous;
	}
	T* Return_current()
	{
		return current.get();
	}
	T* Return_previous()
	{
		return previous.get();
	}
	~Transaction()
	{
		this->current.~shared_ptr();
		this->previous.~shared_ptr();
	}
};


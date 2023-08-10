#pragma once
#include <iostream>
#include <string> 
#include <memory>
#include<stack>
#include"Exeptions.h"

namespace fy
{
	template <class T>
	class Transaction
	{
	private:
		T data;
		std::stack<T> previous;
		std::stack<T> next;
	public:
		Transaction(T object)
		{
			data = object;
		}
		void operator =(Transaction<T> const& other)
		{
			this->data = other.data;
			this->next = other.next;
			this->previous = other.previous;
		}
		void Update(T object)
		{
			while (!this->next.empty())
			{
				this->next.pop();
			}
			previous.push(this->data);
			this->data = object;
		}

		void go_previous_state()
		{
			TransactionPreviousException excp;
			if (!this->previous.empty())
			{
				this->next.push(this->data);
				this->data = this->previous.top();
				this->previous.pop();
				return;
			}
			throw excp;
		}
		void go_next_state()
		{
			TransactionNextException excp;
			if (!this->next.empty())
			{
				this->previous.push(this->data);
				this->data = this->next.top();
				this->next.pop();
				return;
			}
			throw excp;
		}
		T get_data()
		{
			return this->data;
		}
	};

}


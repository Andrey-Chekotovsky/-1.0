#include "Transaction.h"

template <class T>
Transaction<T>::Transaction(T object)
{
	data = object;
	this->previous = NULL;
	this->next = NULL;
}

template <class T>
Transaction<T>* Transaction<T>::Update(T object)
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

template <class T>
std::shared_ptr<Transaction<T>> Transaction<T>::go_previous_state()
{
	if (this->previous != NULL)
		return this->previous;
}
template <class T>
std::shared_ptr<Transaction<T>> Transaction<T>::go_next_state()
{
	if (this->next != NULL)
		return this->next;
}
template <class T>
T Transaction<T>::get_data()
{
	return this->data;
}
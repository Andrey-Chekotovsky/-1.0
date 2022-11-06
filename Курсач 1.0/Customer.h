#pragma once
#include "User.h"
#include "Book.h"
class Customer :
    public User
{
public:
    void buy_Book(Book* books, int num_of_books);

};


#pragma once
#include "User.h"
#include "Book.h"
class Customer :
    public User
{
public:
    void meny() override;
    void buy_Book(Book* books, int num_of_books);

};


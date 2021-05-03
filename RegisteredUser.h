#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include<iostream>
#include<string>
#include<list>
#include"book.h"

using namespace std;

class RegisteredUser
{
    private:
        string name, emailID, password;
        list<Book> issuedBooks;
        bool isLoggedIn;

    string setName(string name)
    {
        return this->name = name;
    }

    string setemailID(string emailID)
    {
        return this->emailID = emailID;
    }

    string setPassword(string password)
    {
        return this->password = password;
    }

    bool setIsLoggedIn(bool isLoggedIn)
    {
        return this->isLoggedIn = isLoggedIn;
    }

    list<Book> setIssuedBooks()
    {
        return this->issuedBooks;
    }

    public:
    RegisteredUser() 
    {
        isLoggedIn = false;
    }

    string getName()
    {
        return this->name;
    }

    string getemailID()
    {
        return this->emailID;
    }

    string getPassword()
    {
        return this->password;
    }

    bool getIsLoggedIn()
    {
        return this->isLoggedIn;
    }

    list<Book> getIssuedBooks()
    {
        return this->issuedBooks;
    }

};

#endif
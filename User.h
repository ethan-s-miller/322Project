#ifndef USER_H
#define USER_H

using namespace std;

#include<iostream>
#include"book.h"
#include <iterator>
#include<list>

class User
{
    public:
    User() {};
    ~User() {};
    
    list<Books> searchForBooks(string);
    void printBookDetails(list<Books> bookList);

};

list<Books> User::searchForBooks(string)
{
    
}
void User::printBookDetails(list<Books> bookList)
{

}


#endif
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

    list<Book> *searchForBooks(string, list<Book> *);
    void printBookDetails(list<Book> *bookList);
    void logIn();

};

list<Book>* User::searchForBooks(string bookName, list<Book> *libraryBooks)
{
    list <Book> :: iterator it;
    list <Book> *searchedBooks = new list<Book>;
    for(it = libraryBooks->begin(); it != libraryBooks->end(); ++it)
    {
        string name = (*it).getTitle();
        int flag = 0;
        for(int i = 0; i<bookName.length(); i++)
        {
            if(name[i] == bookName[i])
                continue;
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            searchedBooks->push_back(*it);
    }

    return searchedBooks;
}
void User::printBookDetails(list<Book> *searchedBooks)
{
    if(searchedBooks->size() == 0)
        cout<<"No books found."<<endl;
    else
    {
        cout<<"\nThe search result: "<<endl<<endl;
        list <Book> :: iterator it;
        for(it = searchedBooks->begin(); it != searchedBooks->end(); ++it)
        {
            cout<<(*it).getTitle()<<endl;
            cout<<(*it).getAuthor()<<endl;
            cout<<(*it).getGenre()<<endl;
            cout<<(*it).getISBN()<<endl<<endl<<endl;
        }
    }
}


#endif
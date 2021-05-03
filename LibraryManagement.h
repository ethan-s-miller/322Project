#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANGEMENT_H

using namespace std;

/*
    1 -> Unregistered User
    2 -> Registered User
    4 -> Registered User
    3 -> Administrator
*/

#include<iostream>
#include<list>
#include"User.h"
#include"book.h"

class LibraryManagement
{
    private:


        int userType;
        list<Book> *books;


    protected:
        void setUserType(int);
        void createObject();

    public:
        LibraryManagement()
        { 
            this->userType = 0; 
            books = new list<Book>;
        }
        void displayMenu();
        int getUserType();
        void searchBooks();

};

int LibraryManagement::getUserType()
{
    return this->userType;
}

void LibraryManagement::displayMenu()
{
    int choice = 0;
    cout<<"*******Welcome to the library*******"<<endl<<endl;

    do
    {
        cout<<"Please select from the menu: "<<endl;
        cout<<"\n1. Search for Books.";
        cout<<"\n2. User Login";
        cout<<"\n3. Create Profile";
        cout<<"\n4. Administrator Login.";
        cin >> choice;

        switch (choice)
        {
            case 1:
                setUserType(1);
                break;
            case 2:
                setUserType(2);
                break;
            case 3:
                setUserType(3);
                break;
            case 4:
                setUserType(4);
                break;

            default:
                cout<<"Wrong choice entered.";
        }

    } while (choice<=4 || choice>=1);

    createObject();
    
}

void LibraryManagement::setUserType(int type)
{
    this->userType = type;
}

void LibraryManagement::createObject()
{
    User *user;
    int type = getUserType();
    if(type == 1)
    {
        user = new User;
        string bookName;
        cout<<"\nEnter the Book name: ";
        cin>>bookName;
        list<Book>* searchedBooks = user->searchForBooks(bookName,books);
        user->printBookDetails(searchedBooks);
    }

    else if(type == 2)
    {

    }
    else if(type == 3)
    {

    }
    else if(type == 4)
    {

    }
}

#endif
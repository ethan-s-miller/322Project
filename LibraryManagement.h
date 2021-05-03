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

class LibraryManagement
{
    private:
        int userType;


    protected:
        void setUserType(int);
        void createObject();

    public:
        LibraryManagement(){ this->userType = 0;}
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
    switch (getUserType())
    {
    case 1:
        User user;
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    
    default:
        break;
    }
}

#endif
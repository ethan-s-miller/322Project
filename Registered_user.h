#ifndef REGISTERED_USER
#define REGISTERED_USER
#include "book.h"
class Registered_user
{
private:
    std::string name;
    std::string emailId;
    std::string password;
    std::vector<Book> bookIssued;
    bool isLoggedIn = false;

protected:

    void setEmailId(std::string id) { this->emailId = id;}

    void setPassword(std::string new_password) { this->password = new_password;}
    
    void setIsLoggedIn(bool status) { this->isLoggedIn = status;}
    
    


public:
    Registered_user(std::string name);
    ~Registered_user();
    
    std::vector<Book> getBooksIssued() { return bookIssued;}
    
    std::string getName() {return name;}
    
    std::string getEmailId() {return emailId;}
    
    std::string getPassword() {return password;}
    
    
    
};

Registered_user::Registered_user(std::string name)
{
	this->name = name;
}

Registered_user::~Registered_user()
{
}



#endif

#ifndef REGISTERED_USER
#define REGISTERED_USER
#include "includes.h"
class Registered_user
{
private:
    std::string name;

public:
    Registered_user(std::string name);
    ~Registered_user();
};

Registered_user::Registered_user(std::string name)
{
	this->name = name;
}

Registered_user::~Registered_user()
{
}



#endif

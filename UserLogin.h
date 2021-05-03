#ifndef USERLOGIN_H
#define USERLOGIN_H

#include<iostream>
#include<string>
#include"User.h"

using namespace std;

class UserLogin

{
    private:
     string username, password;
     bool isLogin;

     void setPassword(string password) {this->password = password;}
     void setUsername(string username) {this->username = username;}
     void setIsLogin(bool isLogin) {this->isLogin = isLogin;}
     void searchUserName(string name);
     bool matchPassword(string name, string password);

    public:
        string getPassword() {return this->password;}
        string getUsername() {return this->username;}
        bool getLoggedIn() {return this->isLogin;}

};


#endif
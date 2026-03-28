#ifndef USERLIST_H
#define USERLIST_H
#include <bits/stdc++.h>
#include "user.h"
using namespace std;


class userlist
{
protected:
    vector<user> users;

public:
    void addUser(const user &u); 

    bool login(string uname, string pass);



    void saveToFile(const string &filename);
    void loadFromFile(const string &filename);

    void changePremium(bool a);
    bool isPremium();
};
#endif
#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
using namespace std;

class user
{
    protected:
        string name;
        string password;
    public:
        int id;
        bool logstatus=false;
        bool hasPremium=false;
        user(string a,string b);
        string getName();
        string getPass();
        bool check(string u,string p);
        bool operator==(const user &other) const;
};
#endif
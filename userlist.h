#include <bits/stdc++.h>
#include "user.h"
using namespace std;


class userlist
{
private:
    vector<user> users;

public:
    void addUser(const user &u); //const allows passing temp objects

    bool login(string uname, string pass);

    //ofstream opens a file for writing. Texts are written using out
    //ios::app means append
    void saveToFile(const string &filename);
    // ifstream is used to load the file in the same way
    void loadFromFile(const string &filename);
};

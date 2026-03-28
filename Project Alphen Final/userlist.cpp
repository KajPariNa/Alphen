#include "userlist.h"
#include <fstream>
#include <string>

void userlist::addUser(const user &u)
{
    user new_user = u;
    int new_id = 1;
    if (!users.empty()) 
    {
        new_id = users.back().id + 1;
    }
    new_user.id = new_id;

    users.push_back(new_user);
}

bool userlist::login(string uname, string pass)
{
    user candidate(uname, pass);

    for (auto &usr : users)
    {
        if (usr == candidate)
        {
            usr.logstatus = true;
            return true;
        }
    }
    return false;
}

void userlist::saveToFile(const string &filename)
{
    ofstream out(filename);
    if (!out) return;

    for(size_t i = 0; i < users.size(); i++)
    {
        out << users[i].id << " "
            << users[i].getName() << " "
            << users[i].getPass() << " "
            << users[i].hasPremium << endl;
    } 

    out.close();
}

void userlist::loadFromFile(const string &filename)
{
    ifstream in(filename);
    users.clear();

    if (!in) {
        return;
    }

    int id;
    string u, p;
    bool q;

    while (in >> id >> u >> p >> q)
    {
        user temp(u, p);
        temp.id = id;
        temp.hasPremium = q;
        users.push_back(temp);
    }

    in.close();
}

void userlist::changePremium(bool a)
{
    if (!users.empty()) {
        users.back().hasPremium = a;
    }
}

bool userlist::isPremium()
{
    if (users.empty()) return false;
    return users.back().hasPremium;
}
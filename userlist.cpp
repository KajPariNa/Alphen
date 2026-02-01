#include "userlist.h"

void userlist::addUser(const user &u) //const allows passing temp objects
{                           //&u was used so that actual object was passed here, not a copy object
    users.push_back(u);
}

bool userlist::login(string uname, string pass)
{
    for(int i=0;i<users.size();i++)
    {
        if(users[i].check(uname,pass))
        {
            users[i].logstatus=true;
            return true;
        }
    }
    return false;
}

//ofstream opens a file for writing. Texts are written using out
//ios::app means append
void userlist::saveToFile(const string &filename)
{
    ofstream out(filename,ios::app);
    for(int i=0;i<users.size();i++)
    {
        out << users[i].getName() << " "<< users[i].getPass() << users[i].hasPremium<<endl;
    }
    out.close();
}

// ifstream is used to load the file in the same way
void userlist::loadFromFile(const string &filename)
{
    ifstream in(filename);
    string u, p;
    bool q;

    users.clear();
    while (in>>u>>p>>q)
    {
        users.emplace_back(u, p);
        users.end()->hasPremium=q;
    }
    in.close();
}

void userlist::changePremium(bool a)
{
    users.end()->logstatus=a;
}

bool userlist::isPremium()
{
    return users.end()->hasPremium;
}

#include "user.h"

user::user(string a,string b):name(a),password(b){ }
string user::getName()
{
    return name;
}
string user::getPass()
{
    return password;
}
bool user::check(string u,string p)
{
    return (u==name && p==password);
}
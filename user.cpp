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
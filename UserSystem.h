#ifndef USERSYSTEM_H
#define USERSYSTEM_H

#include <string>

class UserSystem {
private:
    std::string getPassword();
    bool usernameExists(std::string username);
    void dashboard();

public:
    void header();
    void registerUser();
    void loginUser();
};

#endif

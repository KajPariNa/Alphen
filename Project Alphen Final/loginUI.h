#ifndef LOGINUI_H
#define LOGINUI_H
#include "userlist.h"
#include "workoutUI.h"
#include "premiumPlan.h"
#include "monthlyPlan.h"
#include "quarterlyPlan.h"
#include "yearlyPlan.h"

#include <string>

class UserSystem 
{
private:
    int currentUserID = -1;
public:
    std::string getPassword();
    bool usernameExists(std::string username);
    void dashboard();
    void header();
    void registerUser();
    void loginUser();
    void showMainMenu();
};

#endif
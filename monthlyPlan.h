#pragma once
#include "premiumPlan.h"
#include <string>
#include <ctime>
#include <vector>
class monthlyPlan:public premiumPlan {
private:
    time_t activationDate;
    time_t expirationDate;
    int totalDays;
    bool autoRenew;
    bool hasExpired;
    void checkHandleExpiration();
public:
    monthlyPlan(std::string name,std::string username,std::string usermail);
    monthlyPlan(const monthlyPlan& other);
    monthlyPlan& operator=(const monthlyPlan& other);
    bool operator==(const monthlyPlan& other) const;
    friend std::ostream& operator<<(std::ostream& os, const monthlyPlan& plan);
    time_t getActivationDate() const;
    time_t getExpirationDate() const;
    int getTotalDays() const;
    int getRemainingDays() const;
    bool getAutoRenew() const;
    bool getHasExpired() const;
    void setAutoRenew(bool value);
    bool activateMonthlyPlan();
    bool deactivateMonthlyPlan();
    bool renewMonthlyPlan();
    void revertToNormalAccount();
    void displayPlanDetails();
    void showPlanStatus();
};
void listMonthlyUsers(const std::vector<monthlyPlan>& users);

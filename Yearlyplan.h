#pragma once
#include "premiumPlan.h"
#include <string>
#include <ctime>
#include <vector>
class yearlyPlan:public premiumPlan {
private:
    time_t activationDate;
    time_t expirationDate;
    int totalDays;
    bool autoRenew;
    bool hasExpired;
    void checkHandleExpiration();
public:
    yearlyPlan(std::string name,std::string username,std::string usermail);
    yearlyPlan(const yearlyPlan& other);
    yearlyPlan& operator=(const yearlyPlan& other);
    bool operator==(const yearlyPlan& other) const;
    friend std::ostream& operator<<(std::ostream& os, const yearlyPlan& plan);
    time_t getActivationDate() const;
    time_t getExpirationDate() const;
    int getTotalDays() const;
    int getRemainingDays() const;
    bool getAutoRenew() const;
    bool getHasExpired() const;
    void setAutoRenew(bool value);
    bool activateYearlyPlan();
    bool deactivateYearlyPlan();
    bool renewYearlyPlan();
    void revertToNormalAccount();
    void displayPlanDetails();
    void showPlanStatus();
};
void listYearlyUsers(const std::vector<yearlyPlan>& users);

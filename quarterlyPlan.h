#pragma once
#include "premiumPlan.h"
#include <string>
#include <ctime>
#include <vector>
class quarterlyPlan:public premiumPlan {
private:
    time_t activationDate;
    time_t expirationDate;
    int totalDays;
    bool autoRenew;
    bool hasExpired;
    void checkHandleExpiration();
public:
    quarterlyPlan(std::string name,std::string username,std::string usermail);
    quarterlyPlan(const quarterlyPlan& other);
    quarterlyPlan& operator=(const quarterlyPlan& other);
    bool operator==(const quarterlyPlan& other) const;
    friend std::ostream& operator<<(std::ostream& os, const quarterlyPlan& plan);
    time_t getActivationDate() const;
    time_t getExpirationDate() const;
    int getTotalDays() const;
    int getRemainingDays() const;
    bool getAutoRenew() const;
    bool getHasExpired() const;
    void setAutoRenew(bool value);
    bool activateQuarterlyPlan();
    bool deactivateQuarterlyPlan();
    bool renewQuarterlyPlan();
    void revertToNormalAccount();
    void displayPlanDetails();
    void showPlanStatus();
};
void listQuarterlyUsers(const std::vector<quarterlyPlan>& users);

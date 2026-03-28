#pragma once
#include "premiumPlan.h"
#include <string>
#include <ctime>
#include <vector>
class yearlyPlan:public premiumPlan {
private:
    int currentUserID;
    time_t activationDate;
    time_t expirationDate;
    int totalDays;
    bool autoRenew;
    bool hasExpired;
    void checkHandleExpiration();
public:
    yearlyPlan(int userID);
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
};
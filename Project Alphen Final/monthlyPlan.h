#pragma once
#include "premiumPlan.h"
#include <string>
#include <ctime>
#include <vector>
class monthlyPlan:public premiumPlan {
private:
    int currentUserID;
    time_t activationDate;
    time_t expirationDate;
    int totalDays;
    bool autoRenew;
    bool hasExpired;
    void checkHandleExpiration();
public:
    monthlyPlan(int userID);
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
};
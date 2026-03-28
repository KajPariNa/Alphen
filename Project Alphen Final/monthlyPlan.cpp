#include "monthlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

monthlyPlan::monthlyPlan(int userID)
{
    currentUserID=userID;
    totalDays = 30;
}

time_t monthlyPlan::getActivationDate() const{
    return activationDate;
}

time_t monthlyPlan::getExpirationDate() const{
    return expirationDate;
}

int monthlyPlan::getTotalDays() const{
    return totalDays;
}

int monthlyPlan::getRemainingDays() const{
    if(activationDate==0||hasExpired){
        return 0;
    }
    time_t now=time(0);
    double secondsLeft=difftime(expirationDate,now);
    if(secondsLeft<=0){
        return 0;
    }
    int daysLeft=(int)(secondsLeft/86400);
    return daysLeft;
}

bool monthlyPlan::getAutoRenew() const{
    return autoRenew;
}

bool monthlyPlan::getHasExpired() const{
    return hasExpired;
}

void monthlyPlan::setAutoRenew(bool value){
    autoRenew=value;
}

void monthlyPlan::checkHandleExpiration(){
    if(activationDate==0){
        return;
    }
    time_t now=time(0);
    if(difftime(now,expirationDate)>=0){
        hasExpired=true;
        if(autoRenew){
            cout<<"Your monthly plan has expired. Auto-renewing..."<<endl;
            Sleep(2000);
            renewMonthlyPlan();
        }else{
            cout<<"Your monthly plan has expired!"<<endl;
            revertToNormalAccount();
        }
    }
}

bool monthlyPlan::activateMonthlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment process is yet to be done to unlock monthly premium access!"<<endl;
        return false;
    }
    if(getIsActive()&&!hasExpired){
        cout<<"Monthly plan is already active!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Monthly premium plan has been activated successfully!"<<endl;
    cout<<"Activation Date: "<<ctime(&activationDate);
    cout<<"Expiration Date: "<<ctime(&expirationDate);
    cout<<"Duration: "<<totalDays<<" days"<<endl;
    return true;
}

bool monthlyPlan::deactivateMonthlyPlan(){
    if(!getIsActive()){
        cout<<"The monthly plan is in inactive state already"<<endl;
        return false;
    }
    setIsActive(false);
    cout<<"Monthly premium plan has been deactivated. Reverting back to basic/free pack!"<<endl;
    return true;
}

bool monthlyPlan::renewMonthlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment is required to renew the monthly plan!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Monthly plan has been renewed successfully!"<<endl;
    Sleep(1500);
    cout<<"New Activation Date: "<<ctime(&activationDate);
    cout<<"New Expiration Date: "<<ctime(&expirationDate);
    return true;
}

void monthlyPlan::revertToNormalAccount(){
    setIsActive(false);
    hasExpired=true;
    cout<<"Your account has been reverted to the basic/free plan."<<endl;
    cout<<"Upgrade again to enjoy premium features!"<<endl;
}
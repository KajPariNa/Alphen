#include "yearlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

yearlyPlan::yearlyPlan(int userID)
{
    currentUserID=userID;
    totalDays = 365;
}

time_t yearlyPlan::getActivationDate() const{
    return activationDate;
}

time_t yearlyPlan::getExpirationDate() const{
    return expirationDate;
}

int yearlyPlan::getTotalDays() const{
    return totalDays;
}

int yearlyPlan::getRemainingDays() const{
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

bool yearlyPlan::getAutoRenew() const{
    return autoRenew;
}

bool yearlyPlan::getHasExpired() const{
    return hasExpired;
}

void yearlyPlan::setAutoRenew(bool value){
    autoRenew=value;
}

void yearlyPlan::checkHandleExpiration(){
    if(activationDate==0){
        return;
    }
    time_t now=time(0);
    if(difftime(now,expirationDate)>=0){
        hasExpired=true;
        if(autoRenew){
            cout<<"Your yearly plan has expired. Auto-renewing..."<<endl;
            Sleep(2000);
            renewYearlyPlan();
        }else{
            cout<<"Your yearly plan has expired!"<<endl;
            revertToNormalAccount();
        }
    }
}

bool yearlyPlan::activateYearlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment process is yet to be done to unlock yearly premium access!"<<endl;
        return false;
    }
    if(getIsActive()&&!hasExpired){
        cout<<"Yearly plan is already active!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Yearly premium plan has been activated successfully!"<<endl;
    cout<<"Activation Date: "<<ctime(&activationDate);
    cout<<"Expiration Date: "<<ctime(&expirationDate);
    cout<<"Duration: "<<totalDays<<" days"<<endl;
    return true;
}

bool yearlyPlan::deactivateYearlyPlan(){
    if(!getIsActive()){
        cout<<"The yearly plan is in inactive state already"<<endl;
        return false;
    }
    setIsActive(false);
    cout<<"Yearly premium plan has been deactivated. Reverting back to basic/free pack!"<<endl;
    return true;
}

bool yearlyPlan::renewYearlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment is required to renew the yearly plan!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Yearly plan has been renewed successfully!"<<endl;
    Sleep(1500);
    cout<<"New Activation Date: "<<ctime(&activationDate);
    cout<<"New Expiration Date: "<<ctime(&expirationDate);
    return true;
}

void yearlyPlan::revertToNormalAccount(){
    setIsActive(false);
    hasExpired=true;
    cout<<"Your account has been reverted to the basic/free plan."<<endl;
    cout<<"Upgrade again to enjoy premium features!"<<endl;
}
#include "quarterlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

quarterlyPlan::quarterlyPlan(int userID)
{
    currentUserID=userID;
    totalDays = 90;
}

time_t quarterlyPlan::getActivationDate() const{
    return activationDate;
}

time_t quarterlyPlan::getExpirationDate() const{
    return expirationDate;
}

int quarterlyPlan::getTotalDays() const{
    return totalDays;
}

int quarterlyPlan::getRemainingDays() const{
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

bool quarterlyPlan::getAutoRenew() const{
    return autoRenew;
}

bool quarterlyPlan::getHasExpired() const{
    return hasExpired;
}

void quarterlyPlan::setAutoRenew(bool value){
    autoRenew=value;
}

void quarterlyPlan::checkHandleExpiration(){
    if(activationDate==0){
        return;
    }
    time_t now=time(0);
    if(difftime(now,expirationDate)>=0){
        hasExpired=true;
        if(autoRenew){
            cout<<"Your quarterly plan has expired. Auto-renewing..."<<endl;
            Sleep(2000);
            renewQuarterlyPlan();
        }else{
            cout<<"Your quarterly plan has expired!"<<endl;
            revertToNormalAccount();
        }
    }
}

bool quarterlyPlan::activateQuarterlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment process is yet to be done to unlock quarterly premium access!"<<endl;
        return false;
    }
    if(getIsActive()&&!hasExpired){
        cout<<"Quarterly plan is already active!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Quarterly premium plan has been activated successfully!"<<endl;
    cout<<"Activation Date: "<<ctime(&activationDate);
    cout<<"Expiration Date: "<<ctime(&expirationDate);
    cout<<"Duration: "<<totalDays<<" days"<<endl;
    return true;
}

bool quarterlyPlan::deactivateQuarterlyPlan(){
    if(!getIsActive()){
        cout<<"The quarterly plan is in inactive state already"<<endl;
        return false;
    }
    setIsActive(false);
    cout<<"Quarterly premium plan has been deactivated. Reverting back to basic/free pack!"<<endl;
    return true;
}

bool quarterlyPlan::renewQuarterlyPlan(){
    if(!getIsPaid()){
        cout<<"Payment is required to renew the quarterly plan!"<<endl;
        return false;
    }
    activationDate=time(0);
    expirationDate=activationDate+(totalDays*86400);
    hasExpired=false;
    setIsActive(true);
    cout<<"Quarterly plan has been renewed successfully!"<<endl;
    Sleep(1500);
    cout<<"New Activation Date: "<<ctime(&activationDate);
    cout<<"New Expiration Date: "<<ctime(&expirationDate);
    return true;
}

void quarterlyPlan::revertToNormalAccount(){
    setIsActive(false);
    hasExpired=true;
    cout<<"Your account has been reverted to the basic/free plan."<<endl;
    cout<<"Upgrade again to enjoy premium features!"<<endl;
}
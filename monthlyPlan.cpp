#include "monthlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

monthlyPlan::monthlyPlan(string name,string username,string usermail):premiumPlan(name,username,usermail){
    activationDate=0;
    expirationDate=0;
    totalDays=30;
    autoRenew=false;
    hasExpired=false;
}

monthlyPlan::monthlyPlan(const monthlyPlan& other):premiumPlan(other){
    activationDate=other.activationDate;
    expirationDate=other.expirationDate;
    totalDays=other.totalDays;
    autoRenew=other.autoRenew;
    hasExpired=other.hasExpired;
}

monthlyPlan& monthlyPlan::operator=(const monthlyPlan& other){
    if(this!=&other){
        premiumPlan::operator=(other);
        activationDate=other.activationDate;
        expirationDate=other.expirationDate;
        totalDays=other.totalDays;
        autoRenew=other.autoRenew;
        hasExpired=other.hasExpired;
    }
    return *this;
}

bool monthlyPlan::operator==(const monthlyPlan& other) const{
    return premiumPlan::operator==(other);
}

ostream& operator<<(ostream& os,const monthlyPlan& plan){
    os<<static_cast<const premiumPlan&>(plan);
    os<<"Plan Duration: "<<plan.totalDays<<" days"<<endl;
    if(plan.activationDate!=0){
        os<<"Activation Date: "<<ctime(&plan.activationDate);
    }else{
        os<<"Activation Date: Not activated yet"<<endl;
    }
    if(plan.expirationDate!=0){
        os<<"Expiration Date: "<<ctime(&plan.expirationDate);
    }else{
        os<<"Expiration Date: N/A"<<endl;
    }
    os<<"Auto Renew: "<<(plan.autoRenew?"Yes":"No")<<endl;
    os<<"Expired: "<<(plan.hasExpired?"Yes":"No")<<endl;
    return os;
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

void monthlyPlan::displayPlanDetails(){
    checkHandleExpiration();
    setPackagePrice(10000);
    if(getIsPaid()){
        finalPricing();
    }
    cout<<"MONTHLY PREMIUM PLAN DETAILS : "<<endl;
    cout<<"Premium Plan ID : "<<getPlanID()<<endl;
    cout<<"Name : "<<getName()<<endl;
    cout<<"Username : "<<getUsername()<<endl;
    cout<<"E-mail ID : "<<getUsermail()<<endl;
    cout<<"Weight : "<<getWeight()<<endl;
    cout<<"Package Price : "<<getPackagePrice()<<endl;
    cout<<"Discount : "<<getDiscountPercent()<<endl;
    if(getIsPaid()){
        cout<<"Final Price: "<<getFinalPrice()<<endl;
    }else{
        cout<<"Final Price: Not calculated(payment pending)"<<endl;
    }
    cout<<"Active : "<<(getIsActive()?"Yes":"No")<<endl;
    cout<<"Payment : "<<(getIsPaid()?"Cleared":"Not Cleared")<<endl;
    cout<<"Plan Duration : "<<totalDays<<" days"<<endl;
    if(activationDate!=0){
        cout<<"Activation Date : "<<ctime(&activationDate);
    }else{
        cout<<"Activation Date : Not activated yet"<<endl;
    }
    if(expirationDate!=0){
        cout<<"Expiration Date : "<<ctime(&expirationDate);
    }else{
        cout<<"Expiration Date : N/A"<<endl;
    }
    cout<<"Remaining Days : "<<getRemainingDays()<<endl;
    cout<<"Auto Renew : "<<(autoRenew?"Yes":"No")<<endl;
    cout<<"Expired : "<<(hasExpired?"Yes":"No")<<endl;
}

void monthlyPlan::showPlanStatus(){
    checkHandleExpiration();
    cout<<"Monthly Plan Status Loading..."<<endl;
    Sleep(2000);
    cout<<"Username : "<<getUsername()<<endl;
    cout<<"Plan Active : "<<(getIsActive()?"Yes":"No")<<endl;
    cout<<"Payment : "<<(getIsPaid()?"Cleared":"Not Cleared")<<endl;
    cout<<"Expired : "<<(hasExpired?"Yes":"No")<<endl;
    cout<<"Remaining Days : "<<getRemainingDays()<<endl;
    cout<<"Auto Renew : "<<(autoRenew?"Enabled":"Disabled")<<endl;
    if(hasExpired&&!autoRenew){
        cout<<"Your plan has expired. Please renew to continue enjoying premium features."<<endl;
    }else if(getIsActive()&&!hasExpired){
        int rem=getRemainingDays();
        if(rem<=5){
            cout<<"Warning: Your plan is about to expire in "<<rem<<" days!"<<endl;
        }else{
            cout<<"Your monthly plan is running smoothly."<<endl;
        }
    }
}

void listMonthlyUsers(const vector<monthlyPlan>& users){
    if(users.empty()){
        cout<<"No monthly premium users available."<<endl;
        return;
    }
    cout<<"Registered Monthly Premium Users : "<<endl;
    for(int i=0;i<users.size();i++){
        cout<<i+1<<". "
            <<users[i].getName()
            <<" ("<<users[i].getUsername()<<")"<<endl;
    }
}

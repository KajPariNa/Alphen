#include "yearlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

yearlyPlan::yearlyPlan(string name,string username,string usermail):premiumPlan(name,username,usermail){
    activationDate=0;
    expirationDate=0;
    totalDays=365;
    autoRenew=false;
    hasExpired=false;
}

yearlyPlan::yearlyPlan(const yearlyPlan& other):premiumPlan(other){
    activationDate=other.activationDate;
    expirationDate=other.expirationDate;
    totalDays=other.totalDays;
    autoRenew=other.autoRenew;
    hasExpired=other.hasExpired;
}

yearlyPlan& yearlyPlan::operator=(const yearlyPlan& other){
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

bool yearlyPlan::operator==(const yearlyPlan& other) const{
    return premiumPlan::operator==(other);
}

ostream& operator<<(ostream& os,const yearlyPlan& plan){
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

void yearlyPlan::displayPlanDetails(){
    checkHandleExpiration();
    setPackagePrice(80000);
    if(getIsPaid()){
        finalPricing();
    }
    cout<<"YEARLY PREMIUM PLAN DETAILS : "<<endl;
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

void yearlyPlan::showPlanStatus(){
    checkHandleExpiration();
    cout<<"Yearly Plan Status Loading..."<<endl;
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
        if(rem<=30){
            cout<<"Warning: Your plan is about to expire in "<<rem<<" days!"<<endl;
        }else{
            cout<<"Your yearly plan is running smoothly."<<endl;
        }
    }
}

void listYearlyUsers(const vector<yearlyPlan>& users){
    if(users.empty()){
        cout<<"No yearly premium users available."<<endl;
        return;
    }
    cout<<"Registered Yearly Premium Users : "<<endl;
    for(int i=0;i<users.size();i++){
        cout<<i+1<<". "
            <<users[i].getName()
            <<" ("<<users[i].getUsername()<<")"<<endl;
    }
}

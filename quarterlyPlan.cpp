#include "quarterlyPlan.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

quarterlyPlan::quarterlyPlan(string name,string username,string usermail):premiumPlan(name,username,usermail){
    activationDate=0;
    expirationDate=0;
    totalDays=90;
    autoRenew=false;
    hasExpired=false;
}

quarterlyPlan::quarterlyPlan(const quarterlyPlan& other):premiumPlan(other){
    activationDate=other.activationDate;
    expirationDate=other.expirationDate;
    totalDays=other.totalDays;
    autoRenew=other.autoRenew;
    hasExpired=other.hasExpired;
}

quarterlyPlan& quarterlyPlan::operator=(const quarterlyPlan& other){
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

bool quarterlyPlan::operator==(const quarterlyPlan& other) const{
    return premiumPlan::operator==(other);
}

ostream& operator<<(ostream& os,const quarterlyPlan& plan){
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

void quarterlyPlan::displayPlanDetails(){
    checkHandleExpiration();
    setPackagePrice(25000);
    if(getIsPaid()){
        finalPricing();
    }
    cout<<"QUARTERLY PREMIUM PLAN DETAILS : "<<endl;
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

void quarterlyPlan::showPlanStatus(){
    checkHandleExpiration();
    cout<<"Quarterly Plan Status Loading..."<<endl;
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
        if(rem<=15){
            cout<<"Warning: Your plan is about to expire in "<<rem<<" days!"<<endl;
        }else{
            cout<<"Your quarterly plan is running smoothly."<<endl;
        }
    }
}

void listQuarterlyUsers(const vector<quarterlyPlan>& users){
    if(users.empty()){
        cout<<"No quarterly premium users available."<<endl;
        return;
    }
    cout<<"Registered Quarterly Premium Users : "<<endl;
    for(int i=0;i<users.size();i++){
        cout<<i+1<<". "
            <<users[i].getName()
            <<" ("<<users[i].getUsername()<<")"<<endl;
    }
}

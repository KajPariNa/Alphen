//update1 : 28.01.26
#include<bits/stdc++.h>
using namespace std;

class premiumPlan{
    private:
        static int planCounter;
        int planID;
        string name;
        string username;
        string usermail;
        double weight;
        double packagePrice;
        double discountPercent;
        bool isActive;
        bool isPaid;
    public:
        premiumPlan(int a,string b,string c,string d):planID(a),name(b),username(c),usermail(d),weight(0.0),packagePrice(0.0),discountPercent(0.0),isActive(false),isPaid(false){
            planCounter++;
        }
        premiumPlan(const premiumPlan& other);
        static int getPlanCounter();
        int getPlanID() const;
        string getName() const;
        string getUsername() const;
        string getUsermail() const;
        double getWeight() const;
        double getPackagePrice() const;
        double getDiscountPercent() const;
        bool getIsActive() const;
        bool getIsPaid() const;
        void setplanID(int e);
        void setName(string f);
        void setUsername(string g);
        void setUsermail(string h);
        void setWeight(double i);
        void setPackagePrice(double j);
        void setDiscountPercent(double k);
        void setIsActive(bool l);
        void setIsPaid(bool m);
        premiumPlan& operator=(const premiumPlan& other);
        bool operator==(const premiumPlan& other) const;
        friend ostream& operator<<(ostream& os,const premiumPlan& plan);
        bool activatePremiumPlan();
        bool deactivatePremiumPlan();
        double applyPromoCodeDeal();
        double finalPricing();
        bool hasDonePaymentProcess(string n);
        void displayPlanDetails() const;
        void displayBillingInfo() const;
        void displayPlanStatus() const;
        void dietChart(double weight,double height);
        double daily_calorie_burner_tracker();
        double daily_calorie_intake_tracker();
        void famousRandQuotes();
        void sigma_power_index();
};

int premiumPlan::planCounter=0;

premiumPlan::premiumPlan(const premiumPlan& other){
    planID=other.planID;
    name=other.name;
    username=other.username;
    usermail=other.usermail;
    weight=other.weight;
    packagePrice=other.packagePrice;
    discountPercent=other.discountPercent;
    isActive=other.isActive;
    isPaid=other.isPaid;
}

int premiumPlan::getPlanCounter(){
    return planCounter;
}

int premiumPlan::getPlanID() const{
    return planID;
}

string premiumPlan::getName() const{
    return name;
}

string premiumPlan::getUsername() const{
    return username;
}

string premiumPlan::getUsermail() const{
    return usermail;
}

double premiumPlan::getWeight() const{
    return weight;
}

double premiumPlan::getPackagePrice() const{
    return packagePrice;
}

double premiumPlan::getDiscountPercent() const{
    return discountPercent;
}

bool premiumPlan::getIsActive() const{
    return isActive;
}

bool premiumPlan::getIsPaid() const{
    return isPaid;
}

void premiumPlan::setplanID(int e){
    planID=e;
}

void premiumPlan::setName(string f){
    name=f;
}

void premiumPlan::setUsername(string g){
    username=g;
}

void premiumPlan::setUsermail(string h){
    usermail=h;
}

void premiumPlan::setWeight(double i){
    weight=i;
}

void premiumPlan::setPackagePrice(double j){
    packagePrice=j;
}

void premiumPlan::setDiscountPercent(double k){
    discountPercent=k;
}

void premiumPlan::setIsActive(bool l){
    isActive=l;
}

void premiumPlan::setIsPaid(bool m){
    isPaid=m;
}

premiumPlan& premiumPlan::operator=(const premiumPlan& other){
    if(this!=&other){
        planID=other.planID;
        name=other.name;
        username=other.username;
        usermail=other.usermail;
        weight=other.weight;
        packagePrice=other.packagePrice;
        discountPercent=other.discountPercent;
        isActive=other.isActive;
        isPaid=other.isPaid;
    }
    return *this;
}

bool premiumPlan::operator==(const premiumPlan& other) const{
    if(planID==other.planID && username==other.username && usermail==other.usermail){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os,const premiumPlan& plan){
    os<<"Plan ID: "<<plan.planID<<endl
       <<"Name: "<<plan.name<<endl
       <<"Username: "<<plan.username<<endl
       <<"Email: "<<plan.usermail<<endl
       <<"Package Price: $"<<fixed<<setprecision(2)<<plan.packagePrice<<endl
       <<"Discount: "<<plan.discountPercent<<"%"<<endl
       <<"Status: "<<(plan.isActive?"Active":"Inactive")<<endl
       <<"Payment: "<<(plan.isPaid?"Paid":"Unpaid")<<endl;
    return os;
}

bool premiumPlan::activatePremiumPlan(){
    if(!isPaid){
        cout<<"Payment process is yet to be done to unlock premium access!"<<endl;
        return false;
    }
    isActive=true;
    cout<<"Alphen premium plan has been activated successfully. Thanks for trying out our premium plan!"<<endl;
    return true;
}

bool premiumPlan::deactivatePremiumPlan(){
    if(!isActive){
        cout<<"The premium plan is in inactive state already"<<endl;
        return false;
    }
    isActive=false;
    cout<<"Alphen Premium plan has been deactivated. Reverting back to basic/free pack!"<<endl;
    return true;
}

double premiumPlan::applyPromoCodeDeal(){
    string promoCodes[5]={"atlas2","draco5","theseus7","trek_ZA10","icarus15"};
    double promoDiscRate[5]={2.0,5.0,7.0,10.0,15.0};
    int luckyFive[5]={0};
    for(int i=0;i<5;i++){
        luckyFive[i]=rand()%100+1;
    }
    int guess;
    cout<<"There are 5 promo codes in offer for you. You have to guess a number between 1 to 100. Any random 5 values will hold the 5 related promo code offer. You get only one chance. Guess the 1 of the 5 random numbers to give yourself a chance to win relevant discount."<<endl;
    cin>>guess;
    for(int i=0;i<5;i++){
        if(guess==luckyFive[i]){
            cout<<"CONGRATULATIONS!!! YOU HAVE ACQUIRED ONE OF THE PROMO CODES!"<<endl;
            cout<<"Promo Code Applied : "<<promoCodes[i]<<endl;
            cout<<"Achieved Discount Percentage : "<<promoDiscRate[i]<<"%"<<endl;
            discountPercent = promoDiscRate[i];
            return promoDiscRate[i]/100;
        }
    }
    cout<<"No promo code matched. Bad luck! Better luck next time (in your dreams perhaps!)"<<endl;
    discountPercent=0.0;
    return 0.0;
}

double premiumPlan::finalPricing(){
    double discount=packagePrice*(discountPercent/100.0);
    return packagePrice-discount;
}

int main(){
    srand(time(0));
    return 0;
}

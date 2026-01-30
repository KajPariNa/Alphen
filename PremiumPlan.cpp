#include<bits/stdc++.h>
#include<windows.h>
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
        double finalPrice;
        bool isActive;
        bool isPaid;
    public:
        premiumPlan(int a,string b,string c,string d):planID(a),name(b),username(c),usermail(d),weight(0.0),packagePrice(0.0),discountPercent(0.0),isActive(false),isPaid(false),finalPrice(0.0){
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
        double getFinalPrice() const;
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
        bool hasDonePaymentProcess();
        void displayPlanDetails();
        void dietChart();
        double daily_calorie_burner_tracker();
        double daily_calorie_intake_tracker();
        void net_calorie_per_day_tracker();
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
    finalPrice=other.finalPrice;
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

double premiumPlan::getFinalPrice() const{
    return finalPrice;
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
        finalPrice=other.finalPrice;
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
       <<"Weight: "<<plan.weight<<endl
       <<"Package Price: $"<<fixed<<setprecision(2)<<plan.packagePrice<<endl
       <<"Discount: "<<plan.discountPercent<<"%"<<endl
       <<"Final Price: "<<plan.finalPrice<<endl
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
    Sleep(5000);
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
    finalPrice=packagePrice-discount;
    return finalPrice;
}

bool premiumPlan::hasDonePaymentProcess(){
    applyPromoCodeDeal();
    double fp=finalPricing();
    finalPrice=fp;
    cout<<"Your total payable amount is : "<<fp<<" taka only"<<endl;
    cout<<"PROCESSING YOUR AMOUNT..."<<endl;
    Sleep(2000);
    cout<<"PAYMENT DONE! WELCOME TO ALPHEN!!"<<endl;
    isPaid=true;
    return true;
}

void premiumPlan::displayPlanDetails(){
    cout<<"Before showing you the plan details, we need to gather one information"<<endl;
    cout<<"Enter your weight : "<<endl;
    double w;
    cin>>w;
    setWeight(w);
    setPackagePrice(10000);
    if(isPaid){
        finalPricing();
    }
    cout<<"PREMIUM PLAN DETAILS : "<<endl;
    cout<<"Premium Plan ID : "<<planID<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Username : "<<username<<endl;
    cout<<"E-mail ID : "<<usermail<<endl;
    cout<<"Weight : "<<getWeight()<<endl;
    cout<<"Package Price : "<<packagePrice<<endl;
    cout<<"Discount : "<<discountPercent<<endl;
     if(isPaid){
        cout <<"Final Price: "<<finalPrice<<endl;
     }
    else{
        cout<<"Final Price: Not calculated(payment pending)"<<endl;
    }
    cout<<"Active : "<<(isActive?"Yes":"No")<<endl;
    cout<<"Payment : "<<(isPaid?"Cleared":"Not Cleared")<<endl;
}

void premiumPlan::dietChart(){
    double w;
    cout<<"Enter your current weight in kg : "<<endl;
    cin>>w;
    double h;
    cout<<"Enter your current height in cm : "<<endl;
    cin>>h;
    double bmi=w/((h/100)*(h/100));
    cout<<"Your BMI is : "<<bmi<<endl;
    cout<<"Your perfect diet-chart is loading..."<<endl;
    Sleep(3000);
    vector<string>mealTimes={
        "Breakfast",
        "Lunch",
        "Evening snack",
        "Dinner"
    };
    if(bmi<18.5){
        cout<<"Category : UNDERWEIGHT"<<endl;
        cout<<"Goal : Gaining necessary weight in a healthy manner"<<endl;
        vector<vector<string>>menuPerMeal={
            {"Whole milk","2 boiled eggs","Bread with peanut butter"},
            {"Rice","Meat","Vegetables"},
            {"Yogurt","Fruit smoothie","Roasted peanuts"},
            {"Rice","Vegetables","Meat/Fish"}
        };
        for(int i=0;i<menuPerMeal.size();i++){
            cout<<mealTimes[i]<<":"<<endl;
            for(int j=0;j<menuPerMeal[i].size();j++){
                cout<<menuPerMeal[i][j]<<endl;
            }
        }
    }
    else if(bmi>=18.5&&bmi<25){
        cout<<"Category : PERFECT"<<endl;
        cout<<"Goal : Maintaining consistency"<<endl;
        vector<vector<string>>menuPerMeal={
            {"Oatmeal", "Boiled egg", "Fruit"},
            {"Rice", "Meat", "Vegetables"},
            {"Green tea", "Roasted chickpeas", "Nuts"},
            {"Soup/Flatbreads", "Salad", "Protein source"}
        };
        for(int i=0;i<menuPerMeal.size();i++){
            cout<<mealTimes[i]<<":"<<endl;
            for(int j=0;j<menuPerMeal[i].size();j++){
                cout<<menuPerMeal[i][j]<<endl;
            }
        }
    }
    else if(bmi>=25&&bmi<30){
        cout<<"Category : OVERWEIGHT"<<endl;
        cout<<"Goal : Losing fat"<<endl;
        vector<vector<string>>menuPerMeal={
            {"Omelet", "Green tea", "FlatBreads"},
            {"Brown rice", "Grilled fish", "Salad"},
            {"Low sugar fruit", "Green tea", "Nuts"},
            {"Soup/1 cup rice", "Steamed vegetables", "Lean protein"}
        };
        for(int i=0;i<menuPerMeal.size();i++){
            cout<<mealTimes[i]<<":"<<endl;
            for(int j=0;j<menuPerMeal[i].size();j++){
                cout<<menuPerMeal[i][j]<<endl;
            }
        }
    }
    else{
        cout<<"CATEGORY : OBESE"<<endl;
        cout<<"Goal : Immediate weight loss"<<endl;
        vector<vector<string>>menuPerMeal={
            {"Oats", "Boiled egg", "Green tea"},
            {"Small brown rice", "Vegetables", "Lean protein"},
            {"Fruit (small)", "Water"},
            {"Soup only", "Vegetables", "No carbs"}
        };
        for(int i=0;i<menuPerMeal.size();i++){
            cout<<mealTimes[i]<<":"<<endl;
            for(int j=0;j<menuPerMeal[i].size();j++){
                cout<<menuPerMeal[i][j]<<endl;
            }
        }
    }
}

double daily_calorie_burner_tracker(){
    
}
double daily_calorie_intake_tracker(){
    
}

int main(){
    srand(time(0));
    return 0;
}

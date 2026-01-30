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
        premiumPlan(string b,string c,string d):planID(++planCounter),name(b),username(c),usermail(d),weight(0.0),packagePrice(0.0),discountPercent(0.0),isActive(false),isPaid(false),finalPrice(0.0){}
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
        double daily_calorie_intake_tracker();
        double daily_calorie_burner_tracker();
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

double premiumPlan::daily_calorie_intake_tracker(){
    map<string,double>foodCalories={
        {"rice",130}, {"brownrice",112}, {"roti",120}, {"chapati",120},
        {"paratha",260}, {"naan",270}, {"khichuri",180}, {"pulao",220},
        {"biryani",350}, {"friedrice",250}, {"dal",160},
        {"chickencurry",240}, {"chickenfry",300}, {"beefcurry",280},
        {"muttoncurry",330}, {"fishcurry",200}, {"friedfish",260},
        {"eggcurry",210}, {"omelet",150}, {"boiledegg",78},
        {"vegetablecurry",150}, {"bharta",180}, {"salad",70},
        {"chickpeas",220}, {"paneercurry",320},
        {"burger",300}, {"sandwich",260}, {"shawarma",350},
        {"pizza",285}, {"fries",365}, {"friedchicken",320},
        {"roll",290}, {"momos",240}, {"chowmein",300}, {"pasta",320},
        {"samosa",260}, {"singara",250}, {"pakora",200},
        {"biscuits",150}, {"cake",340}, {"donut",280},
        {"chocolate",230},
        {"banana",105}, {"apple",95}, {"mango",200},
        {"orange",62}, {"milk",122}, {"lassi",220},
        {"tea",90}, {"softdrink",140}
    };
    int items;
    cout<<"Enter the number of food items consumed today: ";
    cin>>items;
    double totalCalories=0.0;
    for (int i=1; i<=items;i++) {
        string food;
        int servings;
        cout <<"Food "<<i<<"name(lowercase, no spaces):";
        cin>>food;
        cout<<"Servings: ";
        cin>>servings;
        if(foodCalories.count(food)){
            totalCalories+=foodCalories[food]*servings;
        }else{
            cout<<"Food not found"<<endl;
            cout<<"Select food category: "<<endl;
            cout<<"1. Staple "<<endl;
            cout<<"2. Protein "<<endl;
            cout<<"3. Vegetable/Fruits "<<endl;
            cout<<"4. Fast Food "<<endl;
            cout<<"5.Sweet "<<endl;
            int choice;
            cin>>choice;
            double estimatedCalories=0.0;

            switch(choice){
                case 1:estimatedCalories=200; break;
                case 2:estimatedCalories=250; break;
                case 3:estimatedCalories=120; break;
                case 4:estimatedCalories=350; break;
                case 5:estimatedCalories=300; break;
                default:
                    cout <<"Invalid choice.Skipped"<<endl;
                    continue;
            }
            totalCalories+=estimatedCalories*servings;
        }
    }
    cout<<"Total daily calorie intake: "<<totalCalories<<" kcal"<<endl;
    return totalCalories;
}

double premiumPlan::daily_calorie_burner_tracker() {
    map<string, double> activityBurnRate = {
        {"walking", 4.0},
        {"fast walking", 5.5},
        {"running", 10.0},
        {"sprinting", 15.0},
        {"cycling", 8.0},
        {"skipping", 12.0},
        {"pushups", 8.5},
        {"situps", 7.5},
        {"gym workout", 9.0},
        {"weight lifting", 6.0},
        {"cardio", 10.5},
        {"yoga", 3.0},
        {"stretching", 2.5},
        {"meditation", 1.5},
        {"football", 9.5},
        {"cricket", 6.5},
        {"badminton", 7.5},
        {"basketball", 9.0},
        {"swimming", 11.0},
        {"stair climbing", 8.5},
        {"household work", 3.5},
        {"cleaning", 4.0},
        {"gardening", 4.5}
    };

    int n;
    cout << "Enter number of activities performed today: ";
    cin >> n;

    cin.ignore();
    double totalBurned = 0.0;

    for(int i = 0; i < n; i++) {
        string activity;
        double minutes;

        cout << endl << "Enter activity name: ";
        getline(cin, activity);

        cout << "Enter duration (in minutes): ";
        cin >> minutes;
        cin.ignore();

        double burnPerMinute;

        if(activityBurnRate.count(activity)) {
            burnPerMinute = activityBurnRate[activity];
        } else {
            cout << "Activity not found. Estimating average burn..." << endl;
            burnPerMinute = 5.0;
        }

        double burned = burnPerMinute * minutes;
        totalBurned += burned;

        cout << "Calories burned from " << activity << ": "
             << burned << " kcal" << endl;
    }

    cout << endl << "Total calories burned today: "
         << totalBurned << " kcal" << endl;

    return totalBurned;
}

void premiumPlan::net_calorie_per_day_tracker() {
    double intake = daily_calorie_intake_tracker();
    cout << endl;

    double burned = daily_calorie_burner_tracker();
    cout << endl;

    double netCalories = intake - burned;

    cout<<"Your daily calorie stats is loading..."<<endl;
    Sleep(2000);
    cout << "Total Calorie Intake  : " << intake << " kcal" << endl;
    cout << "Total Calories Burned : " << burned << " kcal" << endl;
    cout << "Net Calories (Intake - Burned): "
         << netCalories << " kcal" << endl;

    cout << endl;

    if(netCalories > 300) {
        cout << "Status : CALORIE SURPLUS" << endl;
        cout << "Impact : Likely weight gain if continued." << endl;
    }
    else if(netCalories >= -300 && netCalories <= 300) {
        cout << "Status : CALORIE MAINTENANCE" << endl;
        cout << "Impact : Weight likely to remain stable." << endl;
    }
    else {
        cout << "Status : CALORIE DEFICIT" << endl;
        cout << "Impact : Likely weight loss if maintained." << endl;
    }
}

int main(){
    srand(time(0));
    return 0;
}

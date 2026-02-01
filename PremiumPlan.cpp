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
        double lastIntake = -1;
        double lastBurned = -1;
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
    if(username==other.username && usermail==other.usermail){
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
     map<string,double> foodCalories = {
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

    cout << "Available food items (use lowercase, no spaces):"<<endl;
    for (auto &f : foodCalories)
        cout << "- " << f.first << " (" << f.second << " kcal/serving)\n";
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
    lastIntake = totalCalories;
    return totalCalories;
}

double premiumPlan::daily_calorie_burner_tracker() {
        map<string, double> activityBurnRate = {
        {"walking",4.0}, {"fast walking",5.5}, {"running",10.0},
        {"sprinting",15.0}, {"cycling",8.0}, {"skipping",12.0},
        {"pushups",8.5}, {"situps",7.5}, {"gym workout",9.0},
        {"weight lifting",6.0}, {"cardio",10.5}, {"yoga",3.0},
        {"stretching",2.5}, {"meditation",1.5}, {"football",9.5},
        {"cricket",6.5}, {"badminton",7.5}, {"basketball",9.0},
        {"swimming",11.0}, {"stair climbing",8.5},
        {"household work",3.5}, {"cleaning",4.0}, {"gardening",4.5}
    };

    cout << "Available activities:"<<endl;
    for (auto &a : activityBurnRate)
        cout << "- " << a.first << " (" << a.second << " kcal/min)"<<endl;

    int n;
    cout << "Enter number of activities performed today: ";
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

    lastBurned = totalBurned;
    return totalBurned;
}

void premiumPlan::net_calorie_per_day_tracker() {
    double intake = lastIntake;
    double burned = lastBurned;
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

void premiumPlan::famousRandQuotes() {
    vector<string>quotes={
        "Arnold Schwarzenegger: Strength does not come from winning. Your struggles develop your strengths.",
        "Muhammad Ali: I hated every minute of training, but I said, don't quit.",
        "Bruce Lee: Do not pray for an easy life. Pray for the strength to endure a difficult one.",
        "Michael Jordan: Some people want it to happen. Some wish it would happen. Others make it happen.",
        "Dwayne Johnson: Success isn’t always about greatness. It’s about consistency.",
        "Kobe Bryant: The moment you give up is the moment you let someone else win.",
        "David Goggins: You are in danger of living a life so comfortable that you never realize your true potential.",
        "Ronnie Coleman: Everybody wants to be a bodybuilder, but nobody wants to lift heavy weights.",
        "Usain Bolt: I trained 4 years to run 9 seconds. People give up when they don’t see results in 2 months.",
        "Cristiano Ronaldo: Talent without working hard is nothing.",
        "LeBron James: You have to be able to accept failure to get better.",
        "Conor McGregor: Doubt is only removed by action.",
        "Sylvester Stallone: Every champion was once a contender who refused to give up.",
        "Serena Williams: Luck has nothing to do with it. I’ve spent many hours working.",
        "Mike Tyson: Discipline is doing what you hate to do but doing it like you love it.",
        "Jocko Willink: Discipline equals freedom.",
        "Tom Brady: Suffer in silence and let success make the noise.",
        "Elon Musk: When something is important enough, you do it even if the odds are not in your favor.",
        "Steve Jobs: I’m convinced that about half of what separates the successful from the non-successful is perseverance.",
        "Bill Gates: It’s fine to celebrate success, but it is more important to heed the lessons of failure.",
        "Mark Zuckerberg: The biggest risk is not taking any risk.",
        "Jeff Bezos: If you never want to be criticized, don’t do anything new.",
        "Henry Ford: Whether you think you can or you think you can’t, you’re right.",
        "Napoleon Hill: Strength and growth come only through continuous effort and struggle.",
        "Thomas Edison: Opportunity is missed by most people because it is dressed in overalls and looks like work.",
        "Walt Disney: All our dreams can come true if we have the courage to pursue them.",
        "Abraham Lincoln: Discipline is choosing between what you want now and what you want most.",
        "Marcus Aurelius: You have power over your mind, not outside events.",
        "Seneca: Difficulties strengthen the mind, as labor does the body.",
        "Plato: Lack of activity destroys the good condition of every human being.",
        "Socrates: No man has the right to be an amateur in physical training.",
        "Aristotle: We are what we repeatedly do. Excellence is a habit.",
        "Sun Tzu: Victorious warriors win first and then go to war.",
        "Confucius: It does not matter how slowly you go as long as you do not stop.",
        "Leonardo da Vinci: Iron rusts from disuse; stagnant water loses purity.",
        "Nikola Tesla: The present is theirs; the future, for which I really worked, is mine.",
        "Albert Einstein: Life is like riding a bicycle. To keep your balance, you must keep moving.",
        "Stephen Hawking: However difficult life may seem, there is always something you can do.",
        "Neil Armstrong: Difficulties are things that show a person what they are.",
        "Malcolm X: Don’t be in a hurry, but don’t waste time.",
        "Martin Luther King Jr.: If you can’t fly then run, if you can’t run then walk.",
        "Nelson Mandela: It always seems impossible until it’s done.",
        "Bruce Buffer: It’s time to push beyond your limits.",
        "Floyd Mayweather: Hard work, dedication.",
        "Khabib Nurmagomedov: Discipline will take you places motivation can’t.",
        "Anderson Silva: I fight to improve myself, not to prove myself.",
        "Manny Pacquiao: Hard work is the key to success.",
        "Tiger Woods: No matter how good you get, you can always get better.",
        "Rafael Nadal: I am not afraid of losing. I’m afraid of not trying.",
        "Roger Federer: You have to believe in the long-term plan.",
        "Adidas: Impossible is nothing.",
        "Lionel Messi: You have to fight to reach your dream.",
        "Zlatan Ibrahimović: Pressure is something you feel when you don’t know what you’re doing.",
        "Pep Guardiola: Success is not about perfection, it’s about effort.",
        "Alex Ferguson: Hard work without talent is a shame, but talent without hard work is a tragedy.",
        "Jordan Peterson: Compare yourself to who you were yesterday, not to who someone else is today.",
        "Andrew Huberman: Consistency rewires the nervous system.",
        "Joe Rogan: Discipline beats motivation every day.",
        "Goggins (Navy SEAL): Suffering is the true test of life.",
        "Bear Grylls: Fear is the mind-killer. Push forward.",
        "Chris Bumstead: Results come from years, not weeks.",
        "Jay Cutler: You don’t drown by falling in water. You drown by staying there.",
        "Rich Piana: Eat big, train hard, stay dedicated.",
        "Frank Zane: The mind is the strongest muscle.",
        "Lou Ferrigno: Never give up. You only get one life.",
        "Eddie Hall: Strength is built through pain.",
        "Hafthor Bjornsson: Small progress is still progress.",
        "Brian Shaw: One rep at a time.",
        "Nick Walker: Stay hungry.",
        "Chris Heria: Control your body, control your life.",
        "Cal Newport: Discipline is freedom disguised as routine.",
        "Julius Caesar: If you must break the law, do it to seize power—otherwise obey it.",
        "Epictetus: First say to yourself what you would be, then do what you have to do."
    };
    cout <<"Loading your daily dose of motivation..."<< endl;
    Sleep(1200);
    int index = rand() % quotes.size();
    cout<<quotes[index]<<endl;
}

void premiumPlan::sigma_power_index(){
    double intake = lastIntake;
    double burned = lastBurned;
    double netCalories = intake - burned;

    int trainingScore = 0;
    int nutritionScore = 0;
    int consistencyScore = 0;
    int awarenessScore = 0;

    if (burned >= 800)
    {
        trainingScore = 35;
    }
    else if (burned >= 600)
    {
        trainingScore = 30;
    }
    else if (burned >= 400)
    {
        trainingScore = 24;
    }
    else if (burned >= 200)
    {
        trainingScore = 15;
    }
    else
    {
        trainingScore = 6;
    }

    if (abs(netCalories) <= 150)
    {
        nutritionScore = 30;
    }
    else if (abs(netCalories) <= 300)
    {
        nutritionScore = 24;
    }
    else if (abs(netCalories) <= 500)
    {
        nutritionScore = 18;
    }
    else if (abs(netCalories) <= 800)
    {
        nutritionScore = 10;
    }
    else
    {
        nutritionScore = 4;
    }

    if (burned > 0 && intake > 0)
    {
        consistencyScore = 20;
    }
    else if (burned > 0)
    {
        consistencyScore = 12;
    }
    else
    {
        consistencyScore = 5;
    }

    if (weight > 0)
    {
        awarenessScore = 15;
    }
    else
    {
        awarenessScore = 6;
    }

    int sigmaIndex = trainingScore +
                     nutritionScore +
                     consistencyScore +
                     awarenessScore;

    cout << "Performance Breakdown Loading..." << endl;
    Sleep(5000);
    cout << "Training Output      : " << trainingScore << "/35" << endl;
    cout << "Nutrition Discipline : " << nutritionScore << "/30" << endl;
    cout << "Consistency Indicator: " << consistencyScore << "/20" << endl;
    cout << "Body Awareness       : " << awarenessScore << "/15" << endl;

    cout << endl << "SIGMA POWER INDEX : " << sigmaIndex << " / 100" << endl << endl;

    if (sigmaIndex >= 85)
    {
        cout << "CATEGORY : ELITE SIGMA" << endl;
        cout << "PROFILE  : Fully system-driven. High discipline." << endl;
    }
    else if (sigmaIndex >= 70)
    {
        cout << "CATEGORY : DISCIPLINED BUILDER" << endl;
        cout << "PROFILE  : Strong habits. Minor refinement needed." << endl;
    }
    else if (sigmaIndex >= 50)
    {
        cout << "CATEGORY : STRUCTURE FORMING" << endl;
        cout << "PROFILE  : Effort exists, discipline unstable." << endl;
    }
    else if (sigmaIndex >= 30)
    {
        cout << "CATEGORY : INCONSISTENT" << endl;
        cout << "PROFILE  : Random effort. Needs routine." << endl;
    }
    else
    {
        cout << "CATEGORY : COMFORT ZONE" << endl;
        cout << "PROFILE  : No system. No pressure. No progress." << endl;
    }
}

void listUsers(const vector<premiumPlan>& users)
{
    if (users.empty())
    {
        cout << "No premium users available.\n";
        return;
    }

    cout << "\n--- Registered Premium Users ---\n";
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << i + 1 << ". "
             << users[i].getName()
             << " (" << users[i].getUsername() << ")\n";
    }
}


int main(){
    srand(time(0));

    vector<premiumPlan> users;
    int choice = -1;

    while (choice != 0)
    {
        cout << "========= ALPHEN PREMIUM SYSTEM ========="<<endl;;
        cout << "1. Add New Premium User"<<endl;;
        cout << "2. Delete Premium User"<<endl;;
        cout << "3. List All Users"<<endl;;
        cout << "4. Select User & Open Premium Menu"<<endl;;
        cout << "0. Exit Program"<<endl;;
        cout << "Enter choice: "<<endl;;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if (choice == 1)
        {
            string name, username, email;

            cout << "Name: ";
            getline(cin, name);

            cout << "Username: ";
            getline(cin, username);

            cout << "Email: ";
            getline(cin, email);

            premiumPlan newUser(name, username, email);
            users.push_back(newUser);

            cout << "Premium user added successfully.\n";
        }

        else if (choice == 2)
        {
            listUsers(users);
            if (users.empty()) continue;

            int index;
            cout << "Enter user number to delete: ";
            cin >> index;

            if (index < 1 || index > users.size())
            {
                cout << "Invalid selection.\n";
            }
            else
            {
                users.erase(users.begin() + index - 1);
                cout << "User deleted successfully.\n";
            }
        }

        else if (choice == 3)
        {
            listUsers(users);
        }

        else if (choice == 4)
        {
            listUsers(users);
            if (users.empty()) continue;

            int userIndex;
            cout << "Select user number: ";
            cin >> userIndex;

            if (userIndex < 1 || userIndex > users.size())
            {
                cout << "Invalid user index.\n";
                continue;
            }

            premiumPlan &pp = users[userIndex - 1];
            int subChoice = -1;

            while (subChoice != 0)
            {
                cout << "====== PREMIUM USER MENU ======"<<endl;
                cout << "1. Display Plan Details"<<endl;
                cout << "2. Apply Promo Code Deal"<<endl;
                cout << "3. Complete Payment Process"<<endl;
                cout << "4. Activate Premium Plan"<<endl;
                cout << "5. Deactivate Premium Plan"<<endl;
                cout << "6. Show Diet Chart"<<endl;
                cout << "7. Daily Calorie Intake Tracker"<<endl;
                cout << "8. Daily Calorie Burn Tracker"<<endl;
                cout << "9. Net Calorie Per Day Tracker"<<endl;
                cout << "10. Show Random Motivational Quote"<<endl;
                cout << "11. Calculate Sigma Power Index"<<endl;
                cout << "12. Print Full Plan (operator<<)"<<endl;
                cout << "0. Back to Main Menu"<<endl;
                cout << "Enter choice: "<<endl;
                cin >> subChoice;

                switch (subChoice)
                {
                    case 1: pp.displayPlanDetails(); break;
                    case 2: pp.applyPromoCodeDeal(); break;
                    case 3: pp.hasDonePaymentProcess(); break;
                    case 4: pp.activatePremiumPlan(); break;
                    case 5: pp.deactivatePremiumPlan(); break;
                    case 6: pp.dietChart(); break;
                    case 7: pp.daily_calorie_intake_tracker(); break;
                    case 8: pp.daily_calorie_burner_tracker(); break;
                    case 9: pp.net_calorie_per_day_tracker(); break;
                    case 10: pp.famousRandQuotes(); break;
                    case 11: pp.sigma_power_index(); break;
                    case 12: cout << pp << endl; break;
                    case 0: break;
                    default: cout << "Invalid option."<<endl;;
                }
            }
        }

        else if (choice == 0)
        {
            cout << "Exiting Alphen Premium System..."<<endl;
        }
        else
        {
            cout << "Invalid choice."<<endl;
        }
    }

    return 0;
}

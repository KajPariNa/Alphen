#pragma once
#include<string>
#include<iostream>
#include<vector>
class premiumPlan{
    private:
        static int planCounter;
        int planID;
        std::string name;
        std::string username;
        std::string usermail;
        double weight;
        double packagePrice;
        double discountPercent;
        double finalPrice;
        bool isActive;
        bool isPaid;
        double lastIntake = -1;
        double lastBurned = -1;
    public:
        premiumPlan(std::string b,std::string c,std::string d):planID(++planCounter),name(b),username(c),usermail(d),weight(0.0),packagePrice(0.0),discountPercent(0.0),isActive(false),isPaid(false),finalPrice(0.0){}
        premiumPlan(const premiumPlan& other);
        static int getPlanCounter();
        int getPlanID() const;
        std::string getName() const;
        std::string getUsername() const;
        std::string getUsermail() const;
        double getWeight() const;
        double getPackagePrice() const;
        double getDiscountPercent() const;
        double getFinalPrice() const;
        bool getIsActive() const;
        bool getIsPaid() const;
        void setName(std::string f);
        void setUsername(std::string g);
        void setUsermail(std::string h);
        void setWeight(double i);
        void setPackagePrice(double j);
        void setDiscountPercent(double k);
        void setIsActive(bool l);
        void setIsPaid(bool m);
        premiumPlan& operator=(const premiumPlan& other);
        bool operator==(const premiumPlan& other) const;
        friend std::ostream& operator<<(std::ostream& os,const premiumPlan& plan);
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

void listUsers(const std::vector<premiumPlan>& users);

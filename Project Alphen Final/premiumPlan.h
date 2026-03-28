#pragma once
#include<string>
#include<iostream>
#include<vector>
class premiumPlan{
    private:
        int currentUserID;
    protected:
        double weight;
        double packagePrice;
        double discountPercent;
        double finalPrice;
        bool isActive;
        bool isPaid;
        double lastIntake = -1;
        double lastBurned = -1;
    public:
        premiumPlan();
        premiumPlan(int userID);
        double getWeight() const;
        double getPackagePrice() const;
        double getDiscountPercent() const;
        double getFinalPrice() const;
        bool getIsActive() const;
        bool getIsPaid() const;
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
        bool loadPremiumStatusFromUsersFile(const std::string& filePath = "users.txt");
        bool checkPremiumAccess(const std::string& filePath = "users.txt");
        bool updatePremiumStatusInFile(const std::string& filePath);
};
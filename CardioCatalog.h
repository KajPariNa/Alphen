#ifndef CARDIOCATALOG_H
#define CARDIOCATALOG_H

#include <bits/stdc++.h>
using namespace std;

#include "CardioFocus.h"
#include "CardioWorkout.h"

class CardioCatalog {
private:
    CardioFocus focus;
    vector<string> options;
    vector<CardioWorkout> workouts;

    void loadHIIT();
    void loadEndurance();
    void loadRecovery();
    void loadFatLoss();

public:
    CardioCatalog(CardioFocus focus = CardioFocus());

    void loadDefaults();

    // overloading
    void addOption(string o);
    void addOption(vector<string> os);

    // overloading
    void addWorkout(const CardioWorkout& w);
    void addWorkout(vector<CardioWorkout> ws);

    vector<CardioWorkout> getWorkouts() const;

    friend ostream& operator<<(ostream& os, const CardioCatalog& c);
    friend istream& operator>>(istream& is, CardioCatalog& c);
};

#endif

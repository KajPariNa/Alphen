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

public:
    CardioCatalog(CardioFocus focus = CardioFocus());

    void loadDefaults();

    void addOption(string o);
    void addOption(vector<string> os);

    void addWorkout(CardioWorkout w);
    void addWorkout(vector<CardioWorkout> ws);

    vector<CardioWorkout> getWorkouts() const;

    void showOptions() const;
    void showWorkouts() const;
};

#endif

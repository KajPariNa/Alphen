#ifndef STRENGTHCATALOG_H
#define STRENGTHCATALOG_H

#include <bits/stdc++.h>
using namespace std;

#include "StrengthSplit.h"
#include "StrengthWorkout.h"

class WorkoutPlan; // friend class

class StrengthCatalog {
private:
    StrengthSplit split;
    vector<string> machines;
    vector<StrengthWorkout> workouts;

    void loadPushDefaults();
    void loadPullDefaults();
    void loadLegsDefaults();

public:
    StrengthCatalog(StrengthSplit split = StrengthSplit("Push"));

    void loadDefaults();

    // overloading
    void addMachine(string m);
    void addMachine(vector<string> ms);

    // overloading
    void addWorkout(const StrengthWorkout& w);
    void addWorkout(vector<StrengthWorkout> ws);

    vector<StrengthWorkout> getWorkouts() const;

    friend class WorkoutPlan;

    friend ostream& operator<<(ostream& os, const StrengthCatalog& c);
    friend istream& operator>>(istream& is, StrengthCatalog& c);
};

#endif

#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H

#include <bits/stdc++.h>
using namespace std;

#include "StrengthWorkout.h"
#include "CardioWorkout.h"
#include "HybridWorkout.h"

class WorkoutPlan {
private:
    string planName;
    vector<StrengthWorkout> strengthList;
    vector<CardioWorkout> cardioList;
    vector<HybridWorkout> hybridList;

public:
    WorkoutPlan(string planName = "Plan");

    // overloading
    void addWorkout(StrengthWorkout w);
    void addWorkout(CardioWorkout w);
    void addWorkout(HybridWorkout w);

    void showPlan() const;
    void runPlan() const;
};

#endif

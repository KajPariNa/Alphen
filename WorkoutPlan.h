#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H

#include <bits/stdc++.h>
using namespace std;

#include "Workout.h"
#include "StrengthCatalog.h"

class WorkoutPlan {
private:
    string planName;
    vector<Workout*> plan;

public:
    WorkoutPlan(string planName = "Plan");

    void addWorkout(Workout* w);
    void showPlan() const;
    void runPlan() const;

    // friend class demo: access StrengthCatalog private vector
    void stealOneStrengthWorkout(StrengthCatalog& c);

    friend ostream& operator<<(ostream& os, const WorkoutPlan& p);
};

#endif

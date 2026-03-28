#ifndef GLOBALWORKOUTPLANS_H
#define GLOBALWORKOUTPLANS_H
#include "workoutPlan.h"
#include <bits/stdc++.h>
using namespace std;
class GlobalWorkoutPlans
{
public:
    vector<WorkoutPlan> plans;
    //WorkoutPlan createPlan();
    void addPlan(WorkoutPlan plan);
    void displayPlans(int id);
    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);
};
#endif
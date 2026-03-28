#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H
#include "strengthWorkoutList.h"
#include "cardioWorkoutList.h"
#include <bits/stdc++.h>
using namespace std;

class WorkoutPlan
{
public:
    int planID;
    int userID;
    string planName;

    vector<int> strengths;
    vector<int> cardios;

    WorkoutPlan(int pid, int uid, string name);
    void addStrength(int idx);
    void addCardio(int idx);
    int getUserID() const;
    void display() const;
    string serialize() const;
    static WorkoutPlan deserialize(ifstream &in);
};

#endif
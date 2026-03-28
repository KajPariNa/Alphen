#ifndef STRENGTHWORKOUTLIST_H
#define STRENGTHWORKOUTLIST_H
#include <bits/stdc++.h>
#include "StrengthWorkout.h"
#include "workoutList.h"
using namespace std;

class swl : public WorkoutList<StrengthWorkout>
{
public:
    void addWorkout();
    void displayWorkouts() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};
#endif
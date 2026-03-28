#ifndef CARDIOWORKOUTLIST_H
#define CARDIOWORKOUTLIST_H
#include <bits/stdc++.h>
#include "CardioWorkout.h"
#include "workoutList.h"
using namespace std;

class cwl : public WorkoutList<CardioWorkout>
{
public:
    void addWorkout();
    void displayWorkouts() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};
#endif
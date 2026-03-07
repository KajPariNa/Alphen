#ifndef LEGS_H
#define LEGS_H

#include <bits/stdc++.h>
#include "StrengthWorkout.h"
using namespace std;

class Legs : public StrengthWorkout {
protected:
    string sectionName;

public:
    Legs();
    Legs(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
         int sets, int reps, string targetMuscle, string sectionName);

    void setSectionName(string sectionName);
    string getSectionName() const;
};

#endif
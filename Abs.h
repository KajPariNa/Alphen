#ifndef ABS_H
#define ABS_H

#include <bits/stdc++.h>
#include "StrengthWorkout.h"
using namespace std;

class Abs : virtual public StrengthWorkout {
protected:
    string sectionName;

public:
    Abs();
    Abs(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
        int sets, int reps, string targetMuscle, string sectionName);

    void setSectionName(string sectionName);
    string getSectionName() const;
};

#endif
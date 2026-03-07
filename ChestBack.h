#ifndef CHESTBACK_H
#define CHESTBACK_H

#include <bits/stdc++.h>
#include "StrengthWorkout.h"
using namespace std;

class ChestBack : virtual public StrengthWorkout {
protected:
    string sectionName;

public:
    ChestBack();
    ChestBack(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
              int sets, int reps, string targetMuscle, string sectionName);

    void setSectionName(string sectionName);
    string getSectionName() const;
};

#endif
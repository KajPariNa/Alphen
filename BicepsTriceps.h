#ifndef BICEPSTRICEPS_H
#define BICEPSTRICEPS_H

#include <bits/stdc++.h>
#include "StrengthWorkout.h"
using namespace std;

class BicepsTriceps : virtual public StrengthWorkout {
protected:
    string sectionName;

public:
    BicepsTriceps();
    BicepsTriceps(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                  int sets, int reps, string targetMuscle, string sectionName);

    void setSectionName(string sectionName);
    string getSectionName() const;
};

#endif
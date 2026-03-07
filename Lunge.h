#ifndef LUNGE_H
#define LUNGE_H

#include <bits/stdc++.h>
#include "Legs.h"
using namespace std;

class Lunge : public Legs {
private:
    int stepCount;

public:
    Lunge();
    Lunge(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
          int sets, int reps, string targetMuscle, string sectionName, int stepCount);

    void setStepCount(int stepCount);
    int getStepCount() const;
    int getTotalSteps() const;
};

#endif
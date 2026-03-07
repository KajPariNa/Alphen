#ifndef ELLIPTICALTRAINER_H
#define ELLIPTICALTRAINER_H

#include <bits/stdc++.h>
#include "CardioWorkout.h"
using namespace std;

class EllipticalTrainer : public CardioWorkout {
private:
    int resistanceLevel;

public:
    EllipticalTrainer();
    EllipticalTrainer(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                      double distance, double speed, int resistanceLevel);

    void setResistanceLevel(int resistanceLevel);
    int getResistanceLevel() const;
    int getEffortScore() const;
};

#endif
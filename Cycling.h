#ifndef CYCLING_H
#define CYCLING_H

#include <bits/stdc++.h>
#include "CardioWorkout.h"
using namespace std;

class Cycling : public CardioWorkout {
private:
    int gearLevel;

public:
    Cycling();
    Cycling(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
            double distance, double speed, int gearLevel);

    void setGearLevel(int gearLevel);
    int getGearLevel() const;
    int getEffortScore() const;
};

#endif
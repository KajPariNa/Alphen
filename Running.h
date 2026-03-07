#ifndef RUNNING_H
#define RUNNING_H

#include <bits/stdc++.h>
#include "CardioWorkout.h"
using namespace std;

class Running : public CardioWorkout {
private:
    bool outdoor;

public:
    Running();
    Running(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
            double distance, double speed, bool outdoor);

    void setOutdoor(bool outdoor);
    bool getOutdoor() const;
    string getMode() const;
};

#endif
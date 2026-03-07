#ifndef PULLUP_H
#define PULLUP_H

#include <bits/stdc++.h>
#include "ChestBack.h"
using namespace std;

class PullUp : virtual public ChestBack {
private:
    bool assisted;

public:
    PullUp();
    PullUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
           int sets, int reps, string targetMuscle, string sectionName, bool assisted);

    void setAssisted(bool assisted);
    bool getAssisted() const;
    int getDifficultyLevel() const;
};

#endif
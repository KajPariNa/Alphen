#ifndef PUSHUP_H
#define PUSHUP_H

#include <bits/stdc++.h>
#include "ChestBack.h"
using namespace std;

class PushUp : virtual public ChestBack {
private:
    bool weighted;

public:
    PushUp();
    PushUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
           int sets, int reps, string targetMuscle, string sectionName, bool weighted);

    void setWeighted(bool weighted);
    bool getWeighted() const;
    int getDifficultyLevel() const;
};

#endif
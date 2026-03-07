#ifndef SQUAT_H
#define SQUAT_H

#include <bits/stdc++.h>
#include "Legs.h"
using namespace std;

class Squat : virtual public Legs {
private:
    bool weighted;

public:
    Squat();
    Squat(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
          int sets, int reps, string targetMuscle, string sectionName, bool weighted);

    void setWeighted(bool weighted);
    bool getWeighted() const;
    int getDifficultyLevel() const;
};

#endif
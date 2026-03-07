#ifndef DIAMONDPUSHUP_H
#define DIAMONDPUSHUP_H

#include <bits/stdc++.h>
#include "BicepsTriceps.h"
using namespace std;

class DiamondPushUp : public BicepsTriceps {
private:
    bool elevatedFeet;

public:
    DiamondPushUp();
    DiamondPushUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                  int sets, int reps, string targetMuscle, string sectionName, bool elevatedFeet);

    void setElevatedFeet(bool elevatedFeet);
    bool getElevatedFeet() const;
    int getDifficultyLevel() const;
};

#endif
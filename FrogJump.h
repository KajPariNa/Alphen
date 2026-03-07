#ifndef FROGJUMP_H
#define FROGJUMP_H

#include <bits/stdc++.h>
#include "Legs.h"
using namespace std;

class FrogJump : public Legs {
private:
    int jumpCount;

public:
    FrogJump();
    FrogJump(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
             int sets, int reps, string targetMuscle, string sectionName, int jumpCount);

    void setJumpCount(int jumpCount);
    int getJumpCount() const;
    int getTotalJumps() const;
};

#endif
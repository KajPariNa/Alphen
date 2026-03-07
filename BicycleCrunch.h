#ifndef BICYCLECRUNCH_H
#define BICYCLECRUNCH_H

#include <bits/stdc++.h>
#include "Abs.h"
using namespace std;

class BicycleCrunch : public Abs {
private:
    int twistCount;

public:
    BicycleCrunch();
    BicycleCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                  int sets, int reps, string targetMuscle, string sectionName, int twistCount);

    void setTwistCount(int twistCount);
    int getTwistCount() const;
    int getTotalTwists() const;
};

#endif
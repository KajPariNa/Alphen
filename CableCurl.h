#ifndef CABLECURL_H
#define CABLECURL_H

#include <bits/stdc++.h>
#include "BicepsTriceps.h"
using namespace std;

class CableCurl : virtual public BicepsTriceps {
private:
    double cableResistance;

public:
    CableCurl();
    CableCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
              int sets, int reps, string targetMuscle, string sectionName, double cableResistance);

    void setCableResistance(double cableResistance);
    double getCableResistance() const;
    double getTrainingLoad() const;
};

#endif
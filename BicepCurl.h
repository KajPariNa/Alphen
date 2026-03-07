#ifndef BICEPCURL_H
#define BICEPCURL_H

#include <bits/stdc++.h>
#include "BicepsTriceps.h"
using namespace std;

class BicepCurl : virtual public BicepsTriceps {
private:
    double dumbbellWeight;

public:
    BicepCurl();
    BicepCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
              int sets, int reps, string targetMuscle, string sectionName, double dumbbellWeight);

    void setDumbbellWeight(double dumbbellWeight);
    double getDumbbellWeight() const;
    double getTrainingLoad() const;
};

#endif
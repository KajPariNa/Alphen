#ifndef BARBELLCURL_H
#define BARBELLCURL_H

#include <bits/stdc++.h>
#include "BicepsTriceps.h"
using namespace std;

class BarbellCurl : public BicepsTriceps {
private:
    double barbellWeight;

public:
    BarbellCurl();
    BarbellCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                int sets, int reps, string targetMuscle, string sectionName, double barbellWeight);

    void setBarbellWeight(double barbellWeight);
    double getBarbellWeight() const;
    double getTrainingLoad() const;
};

#endif
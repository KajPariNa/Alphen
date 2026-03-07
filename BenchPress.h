#ifndef BENCHPRESS_H
#define BENCHPRESS_H

#include <bits/stdc++.h>
#include "ChestBack.h"
using namespace std;

class BenchPress : virtual public ChestBack {
private:
    double barbellWeight;

public:
    BenchPress();
    BenchPress(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
               int sets, int reps, string targetMuscle, string sectionName, double barbellWeight);

    void setBarbellWeight(double barbellWeight);
    double getBarbellWeight() const;
    double getTrainingLoad() const;
};

#endif
#ifndef DUMBBELLROW_H
#define DUMBBELLROW_H

#include <bits/stdc++.h>
#include "ChestBack.h"
using namespace std;

class DumbbellRow : public ChestBack {
private:
    double dumbbellWeight;

public:
    DumbbellRow();
    DumbbellRow(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                int sets, int reps, string targetMuscle, string sectionName, double dumbbellWeight);

    void setDumbbellWeight(double dumbbellWeight);
    double getDumbbellWeight() const;
    double getTrainingLoad() const;
};

#endif
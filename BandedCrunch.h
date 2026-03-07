#ifndef BANDEDCRUNCH_H
#define BANDEDCRUNCH_H

#include <bits/stdc++.h>
#include "Abs.h"
using namespace std;

class BandedCrunch : public Abs {
private:
    double bandResistance;

public:
    BandedCrunch();
    BandedCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                 int sets, int reps, string targetMuscle, string sectionName, double bandResistance);

    void setBandResistance(double bandResistance);
    double getBandResistance() const;
    double getTrainingLoad() const;
};

#endif
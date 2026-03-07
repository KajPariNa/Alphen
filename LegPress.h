#ifndef LEGPRESS_H
#define LEGPRESS_H

#include <bits/stdc++.h>
#include "Legs.h"
using namespace std;

class LegPress : virtual public Legs {
private:
    double machineWeight;

public:
    LegPress();
    LegPress(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
             int sets, int reps, string targetMuscle, string sectionName, double machineWeight);

    void setMachineWeight(double machineWeight);
    double getMachineWeight() const;
    double getTrainingLoad() const;
};

#endif
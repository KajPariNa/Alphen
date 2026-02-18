#ifndef HYBRIDWORKOUT_H
#define HYBRIDWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "StrengthWorkout.h"
#include "CardioWorkout.h"

class HybridWorkout : public StrengthWorkout, public CardioWorkout {
private:
    string hybridMode;

public:
    HybridWorkout();
    HybridWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                  int weight, int sets, int reps, int rest, string muscleGroup,
                  int duration, int targetHR, double distance, double calPerMin, string focus, string environment,
                  string hybridMode);

    void setHybridMode(string m);
    string getHybridMode() const;

    void perform() const;
    void displayHybrid() const;
};

#endif

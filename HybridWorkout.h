#ifndef HYBRIDWORKOUT_H
#define HYBRIDWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "StrengthWorkout.h"
#include "CardioWorkout.h"

class HybridWorkout : public StrengthWorkout, public CardioWorkout {
private:
    string hybridMode;

    void print(ostream& os) const override;   // for operator<<
    void read(istream& is);                   // for operator>>

public:
    HybridWorkout(); // default

    HybridWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                  int weight, int sets, int reps, int rest, string muscleGroup,
                  int duration, int targetHR, double distance, double calPerMin, string focus, string environment,
                  string hybridMode);

    void performWorkout() const override;

    friend ostream& operator<<(ostream& os, const HybridWorkout& h);
    friend istream& operator>>(istream& is, HybridWorkout& h);
};

#endif

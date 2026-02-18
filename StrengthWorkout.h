#ifndef STRENGTHWORKOUT_H
#define STRENGTHWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "Workout.h"

class StrengthWorkout : virtual public Workout {
protected:
    int weight;
    int sets;
    int reps;
    int rest;
    string muscleGroup;

    void print(ostream& os) const override;

public:
    StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                    int weight, int sets, int reps, int rest, string muscleGroup);

    StrengthWorkout(); // default for operator>>

    void performWorkout() const override;

    friend ostream& operator<<(ostream& os, const StrengthWorkout& s);
    friend istream& operator>>(istream& is, StrengthWorkout& s);

    int getSets() const;
    string getMuscleGroup() const;
};

#endif

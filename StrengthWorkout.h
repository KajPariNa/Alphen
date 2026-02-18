// ========================= StrengthWorkout.h =========================
#ifndef STRENGTHWORKOUT_H
#define STRENGTHWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "workout.h"

class StrengthWorkout : public Workout {
private:
    int weight;
    int sets;        // strength has sets (NO duration)
    int reps;
    int restPeriod;
    string muscleGroup;

public:
    StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                    int weight, int sets, int reps, int restPeriod, string muscleGroup);

    void performWorkout() const override;
    void displayStrengthDetails() const;

    int getWeight() const;
    int getSets() const;
    int getReps() const;
    int getRestPeriod() const;
    string getMuscleGroup() const;
};

#endif

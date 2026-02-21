#ifndef STRENGTHWORKOUT_H
#define STRENGTHWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "Workout.h"

class StrengthWorkout : virtual public Workout {
private:
    int weight;
    int sets;
    int reps;
    int rest;
    string muscleGroup;

public:
    StrengthWorkout();
    StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                    int weight, int sets, int reps, int rest, string muscleGroup);

    void setWeight(int w);
    void setSets(int s);
    void setReps(int r);
    void setRest(int r);
    void setMuscleGroup(string m);

    int getWeight() const;
    int getSets() const;
    int getReps() const;
    int getRest() const;
    string getMuscleGroup() const;

    void perform() const;
    void displayStrength() const;
};

#endif

#ifndef STRENGTHWORKOUT_H
#define STRENGTHWORKOUT_H

#include <bits/stdc++.h>
#include "Workout.h"
using namespace std;

class StrengthWorkout : virtual public Workout {
protected:
    int sets;
    int reps;
    string targetMuscle;

public:
    StrengthWorkout();
    StrengthWorkout(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                    int sets, int reps, string targetMuscle);

    void setSets(int sets);
    void setReps(int reps);
    void setTargetMuscle(string targetMuscle);

    int getSets() const;
    int getReps() const;
    string getTargetMuscle() const;

    int getTotalReps() const;
};

#endif
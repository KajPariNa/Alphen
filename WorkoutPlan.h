// ========================= WorkoutPlan.h =========================
#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H

#include <bits/stdc++.h>
using namespace std;

#include "workout.h"

class WorkoutPlan {
private:
    string planName;
    string intensity;
    vector<Workout*> workouts;

public:
    WorkoutPlan(string planName, string intensity);

    void addWorkout(Workout* workout);
    void displayAllWorkouts() const;
    void performAllWorkouts() const;
};

#endif

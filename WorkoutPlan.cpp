// ========================= WorkoutPlan.cpp =========================
#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan(string planName, string intensity)
    : planName(planName), intensity(intensity) {}

void WorkoutPlan::addWorkout(Workout* workout) {
    workouts.push_back(workout);
}

void WorkoutPlan::displayAllWorkouts() const {
    cout << "Workout Plan: " << planName << "\n";
    cout << "Intensity: " << intensity << "\n\n";

    for (auto w : workouts) {
        w->displayDetails();
        cout << "---------------------------\n";
    }
}

void WorkoutPlan::performAllWorkouts() const {
    for (auto w : workouts) {
        w->performWorkout();
        cout << "===========================\n";
    }
}

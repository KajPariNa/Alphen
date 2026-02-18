// ========================= main.cpp =========================
#include <bits/stdc++.h>
using namespace std;

#include "CardioWorkout.h"
#include "StrengthWorkout.h"
#include "WorkoutPlan.h"

int main() {
    StrengthWorkout s1(
        "Push Ups", 200, "None", "Medium", "Keep back straight",
        0, 4, 15, 60, "Chest"
    );

    CardioWorkout c1(
        "Running", 400, "Shoes", "Hard", "Maintain steady pace",
        45, 140, 5.0, 8.5, "High", "Outdoor"
    );

    WorkoutPlan plan("Summer Plan", "Medium");
    plan.addWorkout(&s1);
    plan.addWorkout(&c1);

    plan.displayAllWorkouts();
    plan.performAllWorkouts();

    return 0;
}

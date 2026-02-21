#include <bits/stdc++.h>
using namespace std;

#include "StrengthCatalog.h"
#include "CardioCatalog.h"
#include "WorkoutPlan.h"

int main() {
    StrengthCatalog sc(StrengthSplit("Push"));
    sc.loadDefaults();

    CardioCatalog cc(CardioFocus("HIIT", "Outdoor"));
    cc.loadDefaults();

    vector<StrengthWorkout> sw = sc.getWorkouts();
    vector<CardioWorkout> cw = cc.getWorkouts();

    WorkoutPlan plan("My Plan");
    plan.addWorkout(sw[0]);
    plan.addWorkout(cw[0]);

    HybridWorkout h1(
        "Hybrid Day", 700, "Mixed", "Hard", "Combined session",
        30, 3, 12, 60, "Full Body",
        15, 165, 2.0, 15.0, "HIIT", "Outdoor",
        "Circuit"
    );
    plan.addWorkout(h1);

    plan.showPlan();
    plan.runPlan();
    return 0;
}

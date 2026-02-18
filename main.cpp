#include <bits/stdc++.h>
using namespace std;

#include "StrengthSplit.h"
#include "StrengthCatalog.h"
#include "CardioFocus.h"
#include "CardioCatalog.h"
#include "WorkoutPlan.h"
#include "HybridWorkout.h"

int main() {
    StrengthCatalog sc(StrengthSplit("Push"));
    sc.loadDefaults();

    CardioCatalog cc(CardioFocus("HIIT", "Outdoor"));
    cc.loadDefaults();

    cout << sc << "\n";
    cout << cc << "\n";

    vector<StrengthWorkout> sw = sc.getWorkouts();
    vector<CardioWorkout> cw = cc.getWorkouts();

    StrengthWorkout s1 = sw[0];
    CardioWorkout c1 = cw[0];

    HybridWorkout h1(
        "Hybrid Circuit", 600, "Mixed", "Hard", "Strength + Cardio combined",
        30, 3, 12, 60, "Full Body",
        15, 165, 2.0, 15.0, "HIIT", "Outdoor",
        "Circuit"
    );

    WorkoutPlan plan("My Plan");
    plan.addWorkout(&s1);
    plan.addWorkout(&c1);
    plan.addWorkout(&h1);

    // friend class demo
    plan.stealOneStrengthWorkout(sc);

    plan.showPlan();
    plan.runPlan();

    return 0;
}

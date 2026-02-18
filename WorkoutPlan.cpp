#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan(string planName) : planName(planName) {}

void WorkoutPlan::addWorkout(Workout* w) { plan.push_back(w); }

void WorkoutPlan::showPlan() const {
    cout << *this;
}

void WorkoutPlan::runPlan() const {
    cout << "\n=== RUNNING PLAN: " << planName << " ===\n";
    for (auto w : plan) {
        w->performWorkout();
        cout << "=================\n";
    }
}

void WorkoutPlan::stealOneStrengthWorkout(StrengthCatalog& c) {
    if (!c.workouts.empty()) {
        static StrengthWorkout stolen = c.workouts[0];
        plan.push_back(&stolen);
    }
}

ostream& operator<<(ostream& os, const WorkoutPlan& p) {
    os << "\n=== PLAN: " << p.planName << " ===\n";
    for (auto w : p.plan) {
        os << "----------------\n";
        os << *w; // polymorphic print
    }
    return os;
}

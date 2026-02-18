#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan(string planName) : planName(planName) {}

void WorkoutPlan::addWorkout(StrengthWorkout w) { strengthList.push_back(w); }
void WorkoutPlan::addWorkout(CardioWorkout w) { cardioList.push_back(w); }
void WorkoutPlan::addWorkout(HybridWorkout w) { hybridList.push_back(w); }

void WorkoutPlan::showPlan() const {
    cout << "\n=== PLAN: " << planName << " ===\n";

    cout << "\n--- Strength ---\n";
    for (const auto &s : strengthList) {
        cout << "-----------------\n";
        s.displayStrength();
    }

    cout << "\n--- Cardio ---\n";
    for (const auto &c : cardioList) {
        cout << "-----------------\n";
        c.displayCardio();
    }

    cout << "\n--- Hybrid ---\n";
    for (const auto &h : hybridList) {
        cout << "-----------------\n";
        h.displayHybrid();
    }
}

void WorkoutPlan::runPlan() const {
    cout << "\n=== RUNNING PLAN: " << planName << " ===\n";

    cout << "\n--- Strength ---\n";
    for (const auto &s : strengthList) s.perform();

    cout << "\n--- Cardio ---\n";
    for (const auto &c : cardioList) c.perform();

    cout << "\n--- Hybrid ---\n";
    for (const auto &h : hybridList) h.perform();
}

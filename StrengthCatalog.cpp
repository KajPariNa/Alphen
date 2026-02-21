#include "StrengthCatalog.h"

StrengthCatalog::StrengthCatalog(StrengthSplit split) : split(split) {}

void StrengthCatalog::loadPushDefaults() {
    machines = {"Bench Press Machine", "Chest Fly Machine", "Shoulder Press"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Bench Press", 250, "Bench", "Hard", "Controlled", 40, 4, 10, 90, "Chest"));
    workouts.push_back(StrengthWorkout("Overhead Press", 220, "Machine", "Medium", "No lockout", 25, 3, 12, 75, "Shoulders"));
}

void StrengthCatalog::loadPullDefaults() {
    machines = {"Lat Pulldown", "Seated Row", "Cable Face Pull"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Lat Pulldown", 220, "Machine", "Medium", "Squeeze lats", 35, 4, 10, 90, "Back"));
    workouts.push_back(StrengthWorkout("Seated Row", 200, "Machine", "Medium", "Neutral spine", 30, 4, 12, 90, "Back"));
}

void StrengthCatalog::loadLegsDefaults() {
    machines = {"Leg Press", "Leg Extension", "Hamstring Curl"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Leg Press", 300, "Machine", "Hard", "Full ROM", 80, 4, 12, 120, "Legs"));
    workouts.push_back(StrengthWorkout("Leg Extension", 160, "Machine", "Medium", "Pause top", 25, 3, 15, 90, "Quads"));
}

void StrengthCatalog::loadDefaults() {
    if (split.isPush()) loadPushDefaults();
    else if (split.isPull()) loadPullDefaults();
    else if (split.isLegs()) loadLegsDefaults();
    else { machines.clear(); workouts.clear(); }
}

void StrengthCatalog::addMachine(string m) { machines.push_back(m); }
void StrengthCatalog::addMachine(vector<string> ms) { for (auto &x : ms) machines.push_back(x); }

void StrengthCatalog::addWorkout(StrengthWorkout w) { workouts.push_back(w); }
void StrengthCatalog::addWorkout(vector<StrengthWorkout> ws) { for (auto &x : ws) workouts.push_back(x); }

vector<StrengthWorkout> StrengthCatalog::getWorkouts() const { return workouts; }

void StrengthCatalog::showMachines() const {
    cout << "Machines (" << split.getSplit() << "):\n";
    for (auto &m : machines) cout << "- " << m << "\n";
}

void StrengthCatalog::showWorkouts() const {
    cout << "Strength Workouts (" << split.getSplit() << "):\n";
    for (auto &w : workouts) {
        cout << "-----------------\n";
        w.displayStrength();
    }
}

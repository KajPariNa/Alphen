#include "StrengthCatalog.h"

StrengthCatalog::StrengthCatalog(StrengthSplit split) : split(split) {}

void StrengthCatalog::loadPushDefaults() {
    machines = {"Bench Press Machine", "Chest Fly Machine", "Shoulder Press", "Tricep Pushdown Cable"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Bench Press", 250, "Bench", "Hard", "Controlled reps", 40, 4, 10, 90, "Chest"));
    workouts.push_back(StrengthWorkout("Overhead Press", 220, "Machine", "Medium", "No lockout", 25, 3, 12, 75, "Shoulders"));
}

void StrengthCatalog::loadPullDefaults() {
    machines = {"Lat Pulldown", "Seated Row", "Cable Face Pull", "Bicep Curl Cable"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Lat Pulldown", 220, "Machine", "Medium", "Squeeze lats", 35, 4, 10, 90, "Back"));
    workouts.push_back(StrengthWorkout("Seated Row", 200, "Machine", "Medium", "Neutral spine", 30, 4, 12, 90, "Back"));
}

void StrengthCatalog::loadLegsDefaults() {
    machines = {"Leg Press", "Leg Extension", "Hamstring Curl", "Calf Raise Machine"};
    workouts.clear();
    workouts.push_back(StrengthWorkout("Leg Press", 300, "Machine", "Hard", "Full ROM", 80, 4, 12, 120, "Legs"));
    workouts.push_back(StrengthWorkout("Leg Extension", 160, "Machine", "Medium", "Pause top", 25, 3, 15, 90, "Quads"));
}

void StrengthCatalog::loadDefaults() {
    if (split.isPush()) loadPushDefaults();
    else if (split.isPull()) loadPullDefaults();
    else if (split.isLegs()) loadLegsDefaults();
    else { machines = {"Cable Machine"}; workouts.clear(); }
}

void StrengthCatalog::addMachine(string m) { machines.push_back(m); }
void StrengthCatalog::addMachine(vector<string> ms) { for (auto &x : ms) machines.push_back(x); }

void StrengthCatalog::addWorkout(const StrengthWorkout& w) { workouts.push_back(w); }
void StrengthCatalog::addWorkout(vector<StrengthWorkout> ws) { for (auto &x : ws) workouts.push_back(x); }

vector<StrengthWorkout> StrengthCatalog::getWorkouts() const { return workouts; }

ostream& operator<<(ostream& os, const StrengthCatalog& c) {
    os << "StrengthCatalog split=" << c.split.getSplit() << "\n";
    os << "Machines:\n";
    for (auto &m : c.machines) os << "- " << m << "\n";
    os << "Workouts:\n";
    for (auto &w : c.workouts) {
        os << "-----\n" << w;
    }
    return os;
}

istream& operator>>(istream& is, StrengthCatalog& c) {
    // read split only, then auto-load
    string sp;
    is >> sp;
    c.split.setSplit(sp);
    c.loadDefaults();
    return is;
}

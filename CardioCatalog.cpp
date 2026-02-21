#include "CardioCatalog.h"

CardioCatalog::CardioCatalog(CardioFocus focus) : focus(focus) {}

void CardioCatalog::loadHIIT() {
    options = {"Air Bike", "Rowing Machine", "Sprints"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Sprint Intervals", 350, "None", "Hard", "30s on / 60s off",
                                     20, 170, 3.0, 18.0, "HIIT", focus.getLocation()));
}

void CardioCatalog::loadEndurance() {
    options = {"Long Run", "Steady Cycling"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Long Run", 500, "Shoes", "Hard", "Steady pace",
                                     60, 150, 8.0, 8.5, "Endurance", focus.getLocation()));
}

void CardioCatalog::loadDefaults() {
    if (focus.getFocus() == "HIIT") loadHIIT();
    else loadEndurance();
}

void CardioCatalog::addOption(string o) { options.push_back(o); }
void CardioCatalog::addOption(vector<string> os) { for (auto &x : os) options.push_back(x); }

void CardioCatalog::addWorkout(CardioWorkout w) { workouts.push_back(w); }
void CardioCatalog::addWorkout(vector<CardioWorkout> ws) { for (auto &x : ws) workouts.push_back(x); }

vector<CardioWorkout> CardioCatalog::getWorkouts() const { return workouts; }

void CardioCatalog::showOptions() const {
    cout << "Cardio Options (" << focus.getFocus() << ", " << focus.getLocation() << "):\n";
    for (auto &o : options) cout << "- " << o << "\n";
}

void CardioCatalog::showWorkouts() const {
    cout << "Cardio Workouts (" << focus.getFocus() << ", " << focus.getLocation() << "):\n";
    for (auto &w : workouts) {
        cout << "-----------------\n";
        w.displayCardio();
    }
}

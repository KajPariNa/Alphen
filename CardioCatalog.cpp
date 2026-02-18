#include "CardioCatalog.h"

CardioCatalog::CardioCatalog(CardioFocus focus) : focus(focus) {}

void CardioCatalog::loadHIIT() {
    options = {"Air Bike", "Rowing Machine", "Sprints (" + focus.getLocation() + ")", "Jump Rope"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Sprint Intervals", 350, "None", "Hard", "30s on / 60s off",
                                     20, 170, 3.0, 18.0, "HIIT", focus.getLocation()));
}

void CardioCatalog::loadRecovery() {
    options = {"Incline Walk (" + focus.getLocation() + ")", "Easy Cycle", "Light Row"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Incline Walk", 220, "Treadmill", "Easy", "Light pace",
                                     30, 120, 2.0, 7.0, "Recovery", "Indoor"));
}

void CardioCatalog::loadFatLoss() {
    options = {"Treadmill Jog", "Elliptical", "Cycling"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Jog + Walk", 300, "Shoes", "Medium", "2min jog / 1min walk",
                                     35, 140, 4.0, 9.0, "FatLoss", focus.getLocation()));
}

void CardioCatalog::loadEndurance() {
    options = {"Long Run (" + focus.getLocation() + ")", "Steady Cycling", "Steady Row"};
    workouts.clear();
    workouts.push_back(CardioWorkout("Long Run", 500, "Shoes", "Hard", "Steady pace",
                                     60, 150, 8.0, 8.5, "Endurance", focus.getLocation()));
}

void CardioCatalog::loadDefaults() {
    string f = focus.getFocus();
    if (f == "HIIT") loadHIIT();
    else if (f == "Recovery") loadRecovery();
    else if (f == "FatLoss") loadFatLoss();
    else loadEndurance();
}

void CardioCatalog::addOption(string o) { options.push_back(o); }
void CardioCatalog::addOption(vector<string> os) { for (auto &x : os) options.push_back(x); }

void CardioCatalog::addWorkout(const CardioWorkout& w) { workouts.push_back(w); }
void CardioCatalog::addWorkout(vector<CardioWorkout> ws) { for (auto &x : ws) workouts.push_back(x); }

vector<CardioWorkout> CardioCatalog::getWorkouts() const { return workouts; }

ostream& operator<<(ostream& os, const CardioCatalog& c) {
    os << "CardioCatalog focus=" << c.focus.getFocus() << " location=" << c.focus.getLocation() << "\n";
    os << "Options:\n";
    for (auto &o : c.options) os << "- " << o << "\n";
    os << "Workouts:\n";
    for (auto &w : c.workouts) {
        os << "-----\n" << w;
    }
    return os;
}

istream& operator>>(istream& is, CardioCatalog& c) {
    // read focus + location then auto-load
    string f, loc;
    is >> f >> loc;
    c.focus.setFocus(f);
    c.focus.setLocation(loc);
    c.loadDefaults();
    return is;
}

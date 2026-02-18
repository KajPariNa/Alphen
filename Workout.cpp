#include "Workout.h"

Workout::Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type)
    : name(name), caloriesBurned(caloriesBurned), equipment(equipment), difficulty(difficulty), notes(notes), type(type) {}

Workout::~Workout() {}

void Workout::print(ostream& os) const {
    os << "Workout: " << name << "\n";
    os << "Type: " << type << "\n";
    os << "Calories: " << caloriesBurned << "\n";
    os << "Equipment: " << equipment << "\n";
    os << "Difficulty: " << difficulty << "\n";
    os << "Notes: " << notes << "\n";
}

ostream& operator<<(ostream& os, const Workout& w) {
    w.print(os); // virtual dispatch
    return os;
}

string Workout::getName() const { return name; }
string Workout::getType() const { return type; }

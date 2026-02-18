// ========================= Workout.cpp =========================
#include "workout.h"

Workout::Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type)
    : name(name), caloriesBurned(caloriesBurned), equipment(equipment), difficulty(difficulty), notes(notes), type(type) {}

Workout::~Workout() {}

void Workout::displayDetails() const {
    cout << "Workout: " << name << "\n";
    cout << "Type: " << type << "\n";
    cout << "Calories Burned: " << caloriesBurned << " kcal\n";
    cout << "Equipment: " << equipment << "\n";
    cout << "Difficulty: " << difficulty << "\n";
    cout << "Notes: " << notes << "\n";
}

string Workout::getName() const { return name; }
int Workout::getCaloriesBurned() const { return caloriesBurned; }
string Workout::getEquipment() const { return equipment; }
string Workout::getDifficulty() const { return difficulty; }
string Workout::getNotes() const { return notes; }
string Workout::getType() const { return type; }

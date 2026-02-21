#include "Workout.h"

Workout::Workout()
    : name("Unnamed"), caloriesBurned(0), equipment("None"), difficulty("Easy"), notes("-"), type("Unknown") {}

Workout::Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type)
    : name(name), caloriesBurned(caloriesBurned), equipment(equipment), difficulty(difficulty), notes(notes), type(type) {}

void Workout::setName(string n) { name = n; }
void Workout::setCaloriesBurned(int c) { caloriesBurned = c; }
void Workout::setEquipment(string e) { equipment = e; }
void Workout::setDifficulty(string d) { difficulty = d; }
void Workout::setNotes(string n) { notes = n; }
void Workout::setType(string t) { type = t; }

string Workout::getName() const { return name; }
int Workout::getCaloriesBurned() const { return caloriesBurned; }
string Workout::getEquipment() const { return equipment; }
string Workout::getDifficulty() const { return difficulty; }
string Workout::getNotes() const { return notes; }
string Workout::getType() const { return type; }

void Workout::display() const {
    cout << "Name: " << name << "\n";
    cout << "Type: " << type << "\n";
    cout << "Calories: " << caloriesBurned << "\n";
    cout << "Equipment: " << equipment << "\n";
    cout << "Difficulty: " << difficulty << "\n";
    cout << "Notes: " << notes << "\n";
}

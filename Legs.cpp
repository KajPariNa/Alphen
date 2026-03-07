#include "Legs.h"

Legs::Legs() : StrengthWorkout() {
    sectionName = "";
}

Legs::Legs(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
           int sets, int reps, string targetMuscle, string sectionName)
    : StrengthWorkout(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle) {
    this->sectionName = sectionName;
}

void Legs::setSectionName(string sectionName) {
    this->sectionName = sectionName;
}

string Legs::getSectionName() const {
    return sectionName;
}
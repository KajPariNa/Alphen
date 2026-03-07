#include "Abs.h"

Abs::Abs() : StrengthWorkout() {
    sectionName = "";
}

Abs::Abs(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
         int sets, int reps, string targetMuscle, string sectionName)
    : StrengthWorkout(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle) {
    this->sectionName = sectionName;
}

void Abs::setSectionName(string sectionName) {
    this->sectionName = sectionName;
}

string Abs::getSectionName() const {
    return sectionName;
}
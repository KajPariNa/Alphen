#include "ChestBack.h"

ChestBack::ChestBack() : StrengthWorkout() {
    sectionName = "";
}

ChestBack::ChestBack(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                     int sets, int reps, string targetMuscle, string sectionName)
    : StrengthWorkout(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle) {
    this->sectionName = sectionName;
}

void ChestBack::setSectionName(string sectionName) {
    this->sectionName = sectionName;
}

string ChestBack::getSectionName() const {
    return sectionName;
}
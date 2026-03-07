#include "BicepsTriceps.h"

BicepsTriceps::BicepsTriceps() : StrengthWorkout() {
    sectionName = "";
}

BicepsTriceps::BicepsTriceps(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                             int sets, int reps, string targetMuscle, string sectionName)
    : StrengthWorkout(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle) {
    this->sectionName = sectionName;
}

void BicepsTriceps::setSectionName(string sectionName) {
    this->sectionName = sectionName;
}

string BicepsTriceps::getSectionName() const {
    return sectionName;
}
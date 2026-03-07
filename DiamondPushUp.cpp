#include "DiamondPushUp.h"

DiamondPushUp::DiamondPushUp() : BicepsTriceps() {
    elevatedFeet = false;
}

DiamondPushUp::DiamondPushUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                             int sets, int reps, string targetMuscle, string sectionName, bool elevatedFeet)
    : BicepsTriceps(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->elevatedFeet = elevatedFeet;
}

void DiamondPushUp::setElevatedFeet(bool elevatedFeet) {
    this->elevatedFeet = elevatedFeet;
}

bool DiamondPushUp::getElevatedFeet() const {
    return elevatedFeet;
}

int DiamondPushUp::getDifficultyLevel() const {
    return elevatedFeet ? 2 : 1;
}
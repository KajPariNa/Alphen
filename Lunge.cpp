#include "Lunge.h"

Lunge::Lunge() : Legs() {
    stepCount = 0;
}

Lunge::Lunge(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
             int sets, int reps, string targetMuscle, string sectionName, int stepCount)
    : Legs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->stepCount = stepCount;
}

void Lunge::setStepCount(int stepCount) {
    this->stepCount = stepCount;
}

int Lunge::getStepCount() const {
    return stepCount;
}

int Lunge::getTotalSteps() const {
    return stepCount * getSets();
}
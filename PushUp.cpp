#include "PushUp.h"

PushUp::PushUp() : ChestBack() {
    weighted = false;
}

PushUp::PushUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
               int sets, int reps, string targetMuscle, string sectionName, bool weighted)
    : ChestBack(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->weighted = weighted;
}

void PushUp::setWeighted(bool weighted) {
    this->weighted = weighted;
}

bool PushUp::getWeighted() const {
    return weighted;
}

int PushUp::getDifficultyLevel() const {
    return weighted ? 2 : 1;
}
#include "Squat.h"

Squat::Squat() : Legs() {
    weighted = false;
}

Squat::Squat(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
             int sets, int reps, string targetMuscle, string sectionName, bool weighted)
    : Legs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->weighted = weighted;
}

void Squat::setWeighted(bool weighted) {
    this->weighted = weighted;
}

bool Squat::getWeighted() const {
    return weighted;
}

int Squat::getDifficultyLevel() const {
    return weighted ? 2 : 1;
}
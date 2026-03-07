#include "PullUp.h"

PullUp::PullUp() : ChestBack() {
    assisted = false;
}

PullUp::PullUp(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
               int sets, int reps, string targetMuscle, string sectionName, bool assisted)
    : ChestBack(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->assisted = assisted;
}

void PullUp::setAssisted(bool assisted) {
    this->assisted = assisted;
}

bool PullUp::getAssisted() const {
    return assisted;
}

int PullUp::getDifficultyLevel() const {
    return assisted ? 1 : 2;
}
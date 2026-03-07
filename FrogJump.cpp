#include "FrogJump.h"

FrogJump::FrogJump() : Legs() {
    jumpCount = 0;
}

FrogJump::FrogJump(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                   int sets, int reps, string targetMuscle, string sectionName, int jumpCount)
    : Legs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->jumpCount = jumpCount;
}

void FrogJump::setJumpCount(int jumpCount) {
    this->jumpCount = jumpCount;
}

int FrogJump::getJumpCount() const {
    return jumpCount;
}

int FrogJump::getTotalJumps() const {
    return jumpCount * getSets();
}
#include "Cycling.h"

Cycling::Cycling() : CardioWorkout() {
    gearLevel = 0;
}

Cycling::Cycling(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                 double distance, double speed, int gearLevel)
    : CardioWorkout(workoutName, category, difficulty, duration, caloriesBurned, distance, speed) {
    this->gearLevel = gearLevel;
}

void Cycling::setGearLevel(int gearLevel) {
    this->gearLevel = gearLevel;
}

int Cycling::getGearLevel() const {
    return gearLevel;
}

int Cycling::getEffortScore() const {
    return gearLevel * duration;
}
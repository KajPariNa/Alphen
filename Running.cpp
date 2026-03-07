#include "Running.h"

Running::Running() : CardioWorkout() {
    outdoor = true;
}

Running::Running(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                 double distance, double speed, bool outdoor)
    : CardioWorkout(workoutName, category, difficulty, duration, caloriesBurned, distance, speed) {
    this->outdoor = outdoor;
}

void Running::setOutdoor(bool outdoor) {
    this->outdoor = outdoor;
}

bool Running::getOutdoor() const {
    return outdoor;
}

string Running::getMode() const {
    return outdoor ? "Outdoor" : "Treadmill";
}
#include "EllipticalTrainer.h"

EllipticalTrainer::EllipticalTrainer() : CardioWorkout() {
    resistanceLevel = 0;
}

EllipticalTrainer::EllipticalTrainer(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                                     double distance, double speed, int resistanceLevel)
    : CardioWorkout(workoutName, category, difficulty, duration, caloriesBurned, distance, speed) {
    this->resistanceLevel = resistanceLevel;
}

void EllipticalTrainer::setResistanceLevel(int resistanceLevel) {
    this->resistanceLevel = resistanceLevel;
}

int EllipticalTrainer::getResistanceLevel() const {
    return resistanceLevel;
}

int EllipticalTrainer::getEffortScore() const {
    return resistanceLevel * duration;
}
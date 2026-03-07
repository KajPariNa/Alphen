#include "CardioWorkout.h"

CardioWorkout::CardioWorkout() : Workout() {
    distance = 0.0;
    speed = 0.0;
}

CardioWorkout::CardioWorkout(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                             double distance, double speed)
    : Workout(workoutName, category, difficulty, duration, caloriesBurned) {
    this->distance = distance;
    this->speed = speed;
}

void CardioWorkout::setDistance(double distance) {
    this->distance = distance;
}

void CardioWorkout::setSpeed(double speed) {
    this->speed = speed;
}

double CardioWorkout::getDistance() const {
    return distance;
}

double CardioWorkout::getSpeed() const {
    return speed;
}
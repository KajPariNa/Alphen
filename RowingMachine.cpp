#include "RowingMachine.h"

RowingMachine::RowingMachine() : CardioWorkout() {
    strokeRate = 0.0;
}

RowingMachine::RowingMachine(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                             double distance, double speed, double strokeRate)
    : CardioWorkout(workoutName, category, difficulty, duration, caloriesBurned, distance, speed) {
    this->strokeRate = strokeRate;
}

void RowingMachine::setStrokeRate(double strokeRate) {
    this->strokeRate = strokeRate;
}

double RowingMachine::getStrokeRate() const {
    return strokeRate;
}

double RowingMachine::getEstimatedStrokes() const {
    return strokeRate * duration;
}
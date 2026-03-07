#include "BenchPress.h"

BenchPress::BenchPress() : ChestBack() {
    barbellWeight = 0.0;
}

BenchPress::BenchPress(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                       int sets, int reps, string targetMuscle, string sectionName, double barbellWeight)
    : ChestBack(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->barbellWeight = barbellWeight;
}

void BenchPress::setBarbellWeight(double barbellWeight) {
    this->barbellWeight = barbellWeight;
}

double BenchPress::getBarbellWeight() const {
    return barbellWeight;
}

double BenchPress::getTrainingLoad() const {
    return barbellWeight * getTotalReps();
}
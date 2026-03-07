#include "BarbellCurl.h"

BarbellCurl::BarbellCurl() : BicepsTriceps() {
    barbellWeight = 0.0;
}

BarbellCurl::BarbellCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                         int sets, int reps, string targetMuscle, string sectionName, double barbellWeight)
    : BicepsTriceps(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->barbellWeight = barbellWeight;
}

void BarbellCurl::setBarbellWeight(double barbellWeight) {
    this->barbellWeight = barbellWeight;
}

double BarbellCurl::getBarbellWeight() const {
    return barbellWeight;
}

double BarbellCurl::getTrainingLoad() const {
    return barbellWeight * getTotalReps();
}
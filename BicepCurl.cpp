#include "BicepCurl.h"

BicepCurl::BicepCurl() : BicepsTriceps() {
    dumbbellWeight = 0.0;
}

BicepCurl::BicepCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                     int sets, int reps, string targetMuscle, string sectionName, double dumbbellWeight)
    : BicepsTriceps(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->dumbbellWeight = dumbbellWeight;
}

void BicepCurl::setDumbbellWeight(double dumbbellWeight) {
    this->dumbbellWeight = dumbbellWeight;
}

double BicepCurl::getDumbbellWeight() const {
    return dumbbellWeight;
}

double BicepCurl::getTrainingLoad() const {
    return dumbbellWeight * getTotalReps();
}
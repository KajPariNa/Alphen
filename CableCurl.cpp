#include "CableCurl.h"

CableCurl::CableCurl() : BicepsTriceps() {
    cableResistance = 0.0;
}

CableCurl::CableCurl(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                     int sets, int reps, string targetMuscle, string sectionName, double cableResistance)
    : BicepsTriceps(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->cableResistance = cableResistance;
}

void CableCurl::setCableResistance(double cableResistance) {
    this->cableResistance = cableResistance;
}

double CableCurl::getCableResistance() const {
    return cableResistance;
}

double CableCurl::getTrainingLoad() const {
    return cableResistance * getTotalReps();
}
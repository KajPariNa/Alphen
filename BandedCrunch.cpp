#include "BandedCrunch.h"

BandedCrunch::BandedCrunch() : Abs() {
    bandResistance = 0.0;
}

BandedCrunch::BandedCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                           int sets, int reps, string targetMuscle, string sectionName, double bandResistance)
    : Abs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->bandResistance = bandResistance;
}

void BandedCrunch::setBandResistance(double bandResistance) {
    this->bandResistance = bandResistance;
}

double BandedCrunch::getBandResistance() const {
    return bandResistance;
}

double BandedCrunch::getTrainingLoad() const {
    return bandResistance * getTotalReps();
}
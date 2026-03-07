#include "DumbbellRow.h"

DumbbellRow::DumbbellRow() : ChestBack() {
    dumbbellWeight = 0.0;
}

DumbbellRow::DumbbellRow(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                         int sets, int reps, string targetMuscle, string sectionName, double dumbbellWeight)
    : ChestBack(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->dumbbellWeight = dumbbellWeight;
}

void DumbbellRow::setDumbbellWeight(double dumbbellWeight) {
    this->dumbbellWeight = dumbbellWeight;
}

double DumbbellRow::getDumbbellWeight() const {
    return dumbbellWeight;
}

double DumbbellRow::getTrainingLoad() const {
    return dumbbellWeight * getTotalReps();
}
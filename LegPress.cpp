#include "LegPress.h"

LegPress::LegPress() : Legs() {
    machineWeight = 0.0;
}

LegPress::LegPress(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                   int sets, int reps, string targetMuscle, string sectionName, double machineWeight)
    : Legs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->machineWeight = machineWeight;
}

void LegPress::setMachineWeight(double machineWeight) {
    this->machineWeight = machineWeight;
}

double LegPress::getMachineWeight() const {
    return machineWeight;
}

double LegPress::getTrainingLoad() const {
    return machineWeight * getTotalReps();
}
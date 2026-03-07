#include "AbCoasterCrunch.h"

AbCoasterCrunch::AbCoasterCrunch() : Abs() {
    machineLevel = 0;
}

AbCoasterCrunch::AbCoasterCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                                 int sets, int reps, string targetMuscle, string sectionName, int machineLevel)
    : Abs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->machineLevel = machineLevel;
}

void AbCoasterCrunch::setMachineLevel(int machineLevel) {
    this->machineLevel = machineLevel;
}

int AbCoasterCrunch::getMachineLevel() const {
    return machineLevel;
}

int AbCoasterCrunch::getEffortScore() const {
    return machineLevel * getSets();
}
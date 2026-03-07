#include "BicycleCrunch.h"

BicycleCrunch::BicycleCrunch() : Abs() {
    twistCount = 0;
}

BicycleCrunch::BicycleCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                             int sets, int reps, string targetMuscle, string sectionName, int twistCount)
    : Abs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->twistCount = twistCount;
}

void BicycleCrunch::setTwistCount(int twistCount) {
    this->twistCount = twistCount;
}

int BicycleCrunch::getTwistCount() const {
    return twistCount;
}

int BicycleCrunch::getTotalTwists() const {
    return twistCount * getSets();
}
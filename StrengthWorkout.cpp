#include "StrengthWorkout.h"

StrengthWorkout::StrengthWorkout() : Workout() {
    sets = 0;
    reps = 0;
    targetMuscle = "";
}

StrengthWorkout::StrengthWorkout(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                                 int sets, int reps, string targetMuscle)
    : Workout(workoutName, category, difficulty, duration, caloriesBurned) {
    this->sets = sets;
    this->reps = reps;
    this->targetMuscle = targetMuscle;
}

void StrengthWorkout::setSets(int sets) {
    this->sets = sets;
}

void StrengthWorkout::setReps(int reps) {
    this->reps = reps;
}

void StrengthWorkout::setTargetMuscle(string targetMuscle) {
    this->targetMuscle = targetMuscle;
}

int StrengthWorkout::getSets() const {
    return sets;
}

int StrengthWorkout::getReps() const {
    return reps;
}

string StrengthWorkout::getTargetMuscle() const {
    return targetMuscle;
}

int StrengthWorkout::getTotalReps() const {
    return sets * reps;
}
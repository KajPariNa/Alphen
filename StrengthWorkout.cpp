// ========================= StrengthWorkout.cpp =========================
#include "StrengthWorkout.h"

StrengthWorkout::StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                                 int weight, int sets, int reps, int restPeriod, string muscleGroup)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Strength"),
      weight(weight),
      sets(sets),
      reps(reps),
      restPeriod(restPeriod),
      muscleGroup(muscleGroup) {}

void StrengthWorkout::performWorkout() const {
    cout << "Performing Strength: " << name << "\n";
    cout << "Weight: " << weight << " kg\n";
    cout << "Sets: " << sets << "\n";
    cout << "Reps: " << reps << "\n";
    cout << "Rest: " << restPeriod << " sec\n";
    cout << "Muscle Group: " << muscleGroup << "\n";
}

void StrengthWorkout::displayStrengthDetails() const {
    displayDetails();
    cout << "Weight: " << weight << " kg\n";
    cout << "Sets: " << sets << "\n";
    cout << "Reps: " << reps << "\n";
    cout << "Rest Period: " << restPeriod << " sec\n";
    cout << "Muscle Group: " << muscleGroup << "\n";
}

int StrengthWorkout::getWeight() const { return weight; }
int StrengthWorkout::getSets() const { return sets; }
int StrengthWorkout::getReps() const { return reps; }
int StrengthWorkout::getRestPeriod() const { return restPeriod; }
string StrengthWorkout::getMuscleGroup() const { return muscleGroup; }

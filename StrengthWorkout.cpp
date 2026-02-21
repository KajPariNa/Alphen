#include "StrengthWorkout.h"

StrengthWorkout::StrengthWorkout()
    : Workout("Unnamed", 0, "None", "Easy", "-", "Strength"),
      weight(0), sets(0), reps(0), rest(0), muscleGroup("Unknown") {}

StrengthWorkout::StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                                 int weight, int sets, int reps, int rest, string muscleGroup)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Strength"),
      weight(weight), sets(sets), reps(reps), rest(rest), muscleGroup(muscleGroup) {}

void StrengthWorkout::setWeight(int w) { weight = w; }
void StrengthWorkout::setSets(int s) { sets = s; }
void StrengthWorkout::setReps(int r) { reps = r; }
void StrengthWorkout::setRest(int r) { rest = r; }
void StrengthWorkout::setMuscleGroup(string m) { muscleGroup = m; }

int StrengthWorkout::getWeight() const { return weight; }
int StrengthWorkout::getSets() const { return sets; }
int StrengthWorkout::getReps() const { return reps; }
int StrengthWorkout::getRest() const { return rest; }
string StrengthWorkout::getMuscleGroup() const { return muscleGroup; }

void StrengthWorkout::perform() const {
    cout << "[Strength] " << name << " | " << sets << "x" << reps
         << " | weight=" << weight << "kg | rest=" << rest
         << "s | muscle=" << muscleGroup << "\n";
}

void StrengthWorkout::displayStrength() const {
    display();
    cout << "Weight: " << weight << " kg\n";
    cout << "Sets: " << sets << "\n";
    cout << "Reps: " << reps << "\n";
    cout << "Rest: " << rest << " sec\n";
    cout << "Muscle Group: " << muscleGroup << "\n";
}

#include "StrengthWorkout.h"

StrengthWorkout::StrengthWorkout()
    : Workout("Unnamed", 0, "None", "Easy", "-", "Strength"),
      weight(0), sets(0), reps(0), rest(0), muscleGroup("Unknown") {}

StrengthWorkout::StrengthWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                                 int weight, int sets, int reps, int rest, string muscleGroup)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Strength"),
      weight(weight), sets(sets), reps(reps), rest(rest), muscleGroup(muscleGroup) {}

void StrengthWorkout::performWorkout() const {
    cout << "[Strength] " << name << " | " << sets << "x" << reps
         << " | weight=" << weight << "kg | rest=" << rest
         << "s | muscle=" << muscleGroup << "\n";
}

void StrengthWorkout::print(ostream& os) const {
    Workout::print(os);
    os << "Weight: " << weight << " kg\n";
    os << "Sets: " << sets << "\n";
    os << "Reps: " << reps << "\n";
    os << "Rest: " << rest << " sec\n";
    os << "Muscle Group: " << muscleGroup << "\n";
}

ostream& operator<<(ostream& os, const StrengthWorkout& s) {
    s.print(os);
    return os;
}

istream& operator>>(istream& is, StrengthWorkout& s) {
    // simple input order:
    // name calories equipment difficulty notes weight sets reps rest muscleGroup
    is >> ws;
    getline(is, s.name);

    is >> s.caloriesBurned;
    is >> ws; getline(is, s.equipment);
    is >> ws; getline(is, s.difficulty);
    is >> ws; getline(is, s.notes);

    is >> s.weight >> s.sets >> s.reps >> s.rest;
    is >> ws; getline(is, s.muscleGroup);

    s.type = "Strength";
    return is;
}

int StrengthWorkout::getSets() const { return sets; }
string StrengthWorkout::getMuscleGroup() const { return muscleGroup; }

#include "HybridWorkout.h"

HybridWorkout::HybridWorkout()
    : Workout("Unnamed", 0, "None", "Easy", "-", "Hybrid"),
      StrengthWorkout(), CardioWorkout(),
      hybridMode("Circuit") {}

HybridWorkout::HybridWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                             int weight, int sets, int reps, int rest, string muscleGroup,
                             int duration, int targetHR, double distance, double calPerMin, string focus, string environment,
                             string hybridMode)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Hybrid"),
      StrengthWorkout(name, caloriesBurned, equipment, difficulty, notes, weight, sets, reps, rest, muscleGroup),
      CardioWorkout(name, caloriesBurned, equipment, difficulty, notes, duration, targetHR, distance, calPerMin, focus, environment),
      hybridMode(hybridMode) {}

void HybridWorkout::performWorkout() const {
    cout << "[Hybrid - " << hybridMode << "] " << name << "\n";
    cout << "---- Strength Part ----\n";
    StrengthWorkout::performWorkout();
    cout << "---- Cardio Part ----\n";
    CardioWorkout::performWorkout();
}

void HybridWorkout::print(ostream& os) const {
    Workout::print(os);
    os << "Hybrid Mode: " << hybridMode << "\n";
    os << "--- Strength Info ---\n";
    os << "Weight: " << weight << " kg | Sets: " << sets << " | Reps: " << reps
       << " | Rest: " << rest << " sec | Muscle: " << muscleGroup << "\n";
    os << "--- Cardio Info ---\n";
    os << "Duration: " << duration << " min | HR: " << targetHR
       << " | Dist: " << distance << " km | Cal/Min: " << calPerMin
       << " | Focus: " << focus << " | Env: " << environment << "\n";
}

void HybridWorkout::read(istream& is) {
    // name calories equipment difficulty notes
    is >> ws; getline(is, name);
    is >> caloriesBurned;
    is >> ws; getline(is, equipment);
    is >> ws; getline(is, difficulty);
    is >> ws; getline(is, notes);

    // strength
    is >> weight >> sets >> reps >> rest;
    is >> ws; getline(is, muscleGroup);

    // cardio
    is >> duration >> targetHR >> distance >> calPerMin;
    is >> ws; getline(is, focus);
    is >> ws; getline(is, environment);

    // hybrid mode
    is >> ws; getline(is, hybridMode);

    type = "Hybrid";
}

ostream& operator<<(ostream& os, const HybridWorkout& h) {
    h.print(os);   // safe (member function)
    return os;
}

istream& operator>>(istream& is, HybridWorkout& h) {
    h.read(is);    // safe (member function)
    return is;
}

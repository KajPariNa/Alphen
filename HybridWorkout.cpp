#include "HybridWorkout.h"

HybridWorkout::HybridWorkout()
    : Workout("Unnamed Hybrid", 0, "Mixed", "Medium", "-", "Hybrid"),
      StrengthWorkout(), CardioWorkout(),
      hybridMode("Circuit") {
    type = "Hybrid";
}

HybridWorkout::HybridWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                             int weight, int sets, int reps, int rest, string muscleGroup,
                             int duration, int targetHR, double distance, double calPerMin, string focus, string environment,
                             string hybridMode)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Hybrid"),
      StrengthWorkout(name, caloriesBurned, equipment, difficulty, notes, weight, sets, reps, rest, muscleGroup),
      CardioWorkout(name, caloriesBurned, equipment, difficulty, notes, duration, targetHR, distance, calPerMin, focus, environment),
      hybridMode(hybridMode) {
    type = "Hybrid";
}

void HybridWorkout::setHybridMode(string m) { hybridMode = m; }
string HybridWorkout::getHybridMode() const { return hybridMode; }

void HybridWorkout::perform() const {
    cout << "\n[Hybrid - " << hybridMode << "] " << name << "\n";
    cout << "---- Strength Part ----\n";
    StrengthWorkout::perform();
    cout << "---- Cardio Part ----\n";
    CardioWorkout::perform();
}

void HybridWorkout::displayHybrid() const {
    cout << "\n=== Hybrid Workout ===\n";
    display();
    cout << "Hybrid Mode: " << hybridMode << "\n\n";
    cout << "--- Strength Details ---\n";
    StrengthWorkout::displayStrength();
    cout << "\n--- Cardio Details ---\n";
    CardioWorkout::displayCardio();
}

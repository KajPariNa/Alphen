// ========================= CardioWorkout.cpp =========================
#include "CardioWorkout.h"

CardioWorkout::CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                             int duration, int heartRate, double distance, double caloriesPerMinute,
                             string effortLevel, string environment)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Cardio"),
      duration(duration),
      heartRate(heartRate),
      distance(distance),
      caloriesPerMinute(caloriesPerMinute),
      effortLevel(effortLevel),
      environment(environment) {}

void CardioWorkout::performWorkout() const {
    cout << "Performing Cardio: " << name << "\n";
    cout << "Duration: " << duration << " minutes\n";
    cout << "Target HR: " << heartRate << " bpm\n";
    cout << "Distance: " << distance << " km\n";
    cout << "Effort: " << effortLevel << "\n";
    cout << "Environment: " << environment << "\n";
    cout << "Estimated Calories: " << (caloriesPerMinute * duration) << "\n";
}

void CardioWorkout::displayCardioDetails() const {
    displayDetails();
    cout << "Duration: " << duration << " minutes\n";
    cout << "Heart Rate: " << heartRate << " bpm\n";
    cout << "Distance: " << distance << " km\n";
    cout << "Calories/Min: " << caloriesPerMinute << "\n";
    cout << "Effort Level: " << effortLevel << "\n";
    cout << "Environment: " << environment << "\n";
}

int CardioWorkout::getDuration() const { return duration; }
int CardioWorkout::getHeartRate() const { return heartRate; }
double CardioWorkout::getDistance() const { return distance; }
double CardioWorkout::getCaloriesPerMinute() const { return caloriesPerMinute; }
string CardioWorkout::getEffortLevel() const { return effortLevel; }
string CardioWorkout::getEnvironment() const { return environment; }

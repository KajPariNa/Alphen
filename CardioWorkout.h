// ========================= CardioWorkout.h =========================
#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "workout.h"

class CardioWorkout : public Workout {
private:
    int duration; // ONLY cardio has duration
    int heartRate;
    double distance;
    double caloriesPerMinute;
    string effortLevel;
    string environment;

public:
    CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                  int duration, int heartRate, double distance, double caloriesPerMinute,
                  string effortLevel, string environment);

    void performWorkout() const override;
    void displayCardioDetails() const;

    int getDuration() const;
    int getHeartRate() const;
    double getDistance() const;
    double getCaloriesPerMinute() const;
    string getEffortLevel() const;
    string getEnvironment() const;
};

#endif

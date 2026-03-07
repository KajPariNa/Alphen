#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include <bits/stdc++.h>
#include "Workout.h"
using namespace std;

class CardioWorkout : virtual public Workout {
protected:
    double distance;
    double speed;

public:
    CardioWorkout();
    CardioWorkout(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                  double distance, double speed);

    void setDistance(double distance);
    void setSpeed(double speed);

    double getDistance() const;
    double getSpeed() const;
};

#endif
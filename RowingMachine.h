#ifndef ROWINGMACHINE_H
#define ROWINGMACHINE_H

#include <bits/stdc++.h>
#include "CardioWorkout.h"
using namespace std;

class RowingMachine : public CardioWorkout {
private:
    double strokeRate;

public:
    RowingMachine();
    RowingMachine(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                  double distance, double speed, double strokeRate);

    void setStrokeRate(double strokeRate);
    double getStrokeRate() const;
    double getEstimatedStrokes() const;
};

#endif
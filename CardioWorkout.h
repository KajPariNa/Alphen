#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "Workout.h"

class CardioWorkout : virtual public Workout {
protected:
    int duration;
    int targetHR;
    double distance;
    double calPerMin;
    string focus;
    string environment;

    void print(ostream& os) const override;

public:
    CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                  int duration, int targetHR, double distance, double calPerMin, string focus, string environment);

    CardioWorkout(); // default for operator>>

    void performWorkout() const override;

    friend ostream& operator<<(ostream& os, const CardioWorkout& c);
    friend istream& operator>>(istream& is, CardioWorkout& c);

    int getDuration() const;
    string getFocus() const;
};

#endif

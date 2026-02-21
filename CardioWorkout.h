#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include <bits/stdc++.h>
using namespace std;

#include "Workout.h"

class CardioWorkout : virtual public Workout {
private:
    int duration;        // only cardio has duration
    int targetHR;
    double distance;
    double calPerMin;
    string focus;
    string environment;

public:
    CardioWorkout();
    CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                  int duration, int targetHR, double distance, double calPerMin, string focus, string environment);

    void setDuration(int d);
    void setTargetHR(int hr);
    void setDistance(double dist);
    void setCalPerMin(double cpm);
    void setFocus(string f);
    void setEnvironment(string e);

    int getDuration() const;
    int getTargetHR() const;
    double getDistance() const;
    double getCalPerMin() const;
    string getFocus() const;
    string getEnvironment() const;

    void perform() const;
    void displayCardio() const;
};

#endif

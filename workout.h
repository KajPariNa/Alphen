// ========================= Workout.h =========================
#ifndef WORKOUT_H
#define WORKOUT_H

#include <bits/stdc++.h>
using namespace std;

class Workout {
protected:
    string name;
    int caloriesBurned;
    string equipment;
    string difficulty;
    string notes;
    string type; // "Cardio" or "Strength"

public:
    Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type);
    virtual ~Workout();
    virtual void performWorkout() const = 0;

    void displayDetails() const;

    string getName() const;
    int getCaloriesBurned() const;
    string getEquipment() const;
    string getDifficulty() const;
    string getNotes() const;
    string getType() const;
};

#endif

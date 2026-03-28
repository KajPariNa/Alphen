#ifndef WORKOUT_H
#define WORKOUT_H

#include <bits/stdc++.h>
using namespace std;

class Workout {
protected:
    string workoutName;
    string category;
    string difficulty;
    int duration;
    int caloriesBurned;

public:
    Workout();
    Workout(string workoutName, string category, string difficulty, int duration, int caloriesBurned);

    void setWorkoutName(string workoutName);
    void setCategory(string category);
    void setDifficulty(string difficulty);
    void setDuration(int duration);
    void setCaloriesBurned(int caloriesBurned);

    string getWorkoutName() const;
    string getCategory() const;
    string getDifficulty() const;
    int getDuration() const;
    int getCaloriesBurned() const;
};

#endif
#include "Workout.h"

Workout::Workout() {
    workoutName = "";
    category = "";
    difficulty = "";
    duration = 0;
    caloriesBurned = 0;
}

Workout::Workout(string workoutName, string category, string difficulty, int duration, int caloriesBurned) {
    this->workoutName = workoutName;
    this->category = category;
    this->difficulty = difficulty;
    this->duration = duration;
    this->caloriesBurned = caloriesBurned;
}

void Workout::setWorkoutName(string workoutName) {
    this->workoutName = workoutName;
}

void Workout::setCategory(string category) {
    this->category = category;
}

void Workout::setDifficulty(string difficulty) {
    this->difficulty = difficulty;
}

void Workout::setDuration(int duration) {
    this->duration = duration;
}

void Workout::setCaloriesBurned(int caloriesBurned) {
    this->caloriesBurned = caloriesBurned;
}

string Workout::getWorkoutName() const {
    return workoutName;
}

string Workout::getCategory() const {
    return category;
}

string Workout::getDifficulty() const {
    return difficulty;
}

int Workout::getDuration() const {
    return duration;
}

int Workout::getCaloriesBurned() const {
    return caloriesBurned;
}
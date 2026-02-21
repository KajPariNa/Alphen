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
    string type;

public:
    Workout();
    Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type);

    void setName(string n);
    void setCaloriesBurned(int c);
    void setEquipment(string e);
    void setDifficulty(string d);
    void setNotes(string n);
    void setType(string t);

    string getName() const;
    int getCaloriesBurned() const;
    string getEquipment() const;
    string getDifficulty() const;
    string getNotes() const;
    string getType() const;

    void display() const; // normal function (no operator overloading)
};

#endif

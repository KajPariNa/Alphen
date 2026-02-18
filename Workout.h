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

    // polymorphic printing (used by operator<<)
    virtual void print(ostream& os) const;

public:
    Workout(string name, int caloriesBurned, string equipment, string difficulty, string notes, string type);
    virtual ~Workout();

    virtual void performWorkout() const = 0;

    // stream output for base reference/polymorphism
    friend ostream& operator<<(ostream& os, const Workout& w);

    string getName() const;
    string getType() const;
};

#endif

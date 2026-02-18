#ifndef STRENGTHCATALOG_H
#define STRENGTHCATALOG_H

#include <bits/stdc++.h>
using namespace std;

#include "StrengthSplit.h"
#include "StrengthWorkout.h"

class StrengthCatalog {
private:
    StrengthSplit split;
    vector<string> machines;
    vector<StrengthWorkout> workouts;

    void loadPushDefaults();
    void loadPullDefaults();
    void loadLegsDefaults();

public:
    StrengthCatalog(StrengthSplit split = StrengthSplit("Push"));

    void loadDefaults();

    void addMachine(string m);
    void addMachine(vector<string> ms);

    void addWorkout(StrengthWorkout w);
    void addWorkout(vector<StrengthWorkout> ws);

    vector<StrengthWorkout> getWorkouts() const;

    void showMachines() const;
    void showWorkouts() const;
};

#endif

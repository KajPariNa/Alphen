#ifndef ABCOASTERCRUNCH_H
#define ABCOASTERCRUNCH_H

#include <bits/stdc++.h>
#include "Abs.h"
using namespace std;

class AbCoasterCrunch : public Abs {
private:
    int machineLevel;

public:
    AbCoasterCrunch();
    AbCoasterCrunch(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                    int sets, int reps, string targetMuscle, string sectionName, int machineLevel);

    void setMachineLevel(int machineLevel);
    int getMachineLevel() const;
    int getEffortScore() const;
};

#endif
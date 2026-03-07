#ifndef HANGINGLEGRAISE_H
#define HANGINGLEGRAISE_H

#include <bits/stdc++.h>
#include "Abs.h"
using namespace std;

class HangingLegRaise : public Abs {
private:
    bool bentKnee;

public:
    HangingLegRaise();
    HangingLegRaise(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                    int sets, int reps, string targetMuscle, string sectionName, bool bentKnee);

    void setBentKnee(bool bentKnee);
    bool getBentKnee() const;
    int getDifficultyLevel() const;
};

#endif
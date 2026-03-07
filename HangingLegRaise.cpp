#include "HangingLegRaise.h"

HangingLegRaise::HangingLegRaise() : Abs() {
    bentKnee = false;
}

HangingLegRaise::HangingLegRaise(string workoutName, string category, string difficulty, int duration, int caloriesBurned,
                                 int sets, int reps, string targetMuscle, string sectionName, bool bentKnee)
    : Abs(workoutName, category, difficulty, duration, caloriesBurned, sets, reps, targetMuscle, sectionName) {
    this->bentKnee = bentKnee;
}

void HangingLegRaise::setBentKnee(bool bentKnee) {
    this->bentKnee = bentKnee;
}

bool HangingLegRaise::getBentKnee() const {
    return bentKnee;
}

int HangingLegRaise::getDifficultyLevel() const {
    return bentKnee ? 1 : 2;
}
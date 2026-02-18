#include "CardioWorkout.h"

CardioWorkout::CardioWorkout()
    : Workout("Unnamed", 0, "None", "Easy", "-", "Cardio"),
      duration(0), targetHR(0), distance(0), calPerMin(0), focus("Endurance"), environment("Indoor") {}

CardioWorkout::CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                             int duration, int targetHR, double distance, double calPerMin, string focus, string environment)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Cardio"),
      duration(duration), targetHR(targetHR), distance(distance), calPerMin(calPerMin), focus(focus), environment(environment) {}

void CardioWorkout::performWorkout() const {
    cout << "[Cardio] " << name << " | " << duration << "min | HR=" << targetHR
         << " | dist=" << distance << "km | focus=" << focus
         << " | env=" << environment << " | estCal=" << (calPerMin * duration) << "\n";
}

void CardioWorkout::print(ostream& os) const {
    Workout::print(os);
    os << "Duration: " << duration << " min\n";
    os << "Target HR: " << targetHR << "\n";
    os << "Distance: " << distance << " km\n";
    os << "Cal/Min: " << calPerMin << "\n";
    os << "Focus: " << focus << "\n";
    os << "Environment: " << environment << "\n";
}

ostream& operator<<(ostream& os, const CardioWorkout& c) {
    c.print(os);
    return os;
}

istream& operator>>(istream& is, CardioWorkout& c) {
    // name calories equipment difficulty notes duration targetHR distance calPerMin focus environment
    is >> ws;
    getline(is, c.name);

    is >> c.caloriesBurned;
    is >> ws; getline(is, c.equipment);
    is >> ws; getline(is, c.difficulty);
    is >> ws; getline(is, c.notes);

    is >> c.duration >> c.targetHR >> c.distance >> c.calPerMin;
    is >> ws; getline(is, c.focus);
    is >> ws; getline(is, c.environment);

    c.type = "Cardio";
    return is;
}

int CardioWorkout::getDuration() const { return duration; }
string CardioWorkout::getFocus() const { return focus; }

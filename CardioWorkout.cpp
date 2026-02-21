#include "CardioWorkout.h"

CardioWorkout::CardioWorkout()
    : Workout("Unnamed", 0, "None", "Easy", "-", "Cardio"),
      duration(0), targetHR(0), distance(0), calPerMin(0), focus("Endurance"), environment("Indoor") {}

CardioWorkout::CardioWorkout(string name, int caloriesBurned, string equipment, string difficulty, string notes,
                             int duration, int targetHR, double distance, double calPerMin, string focus, string environment)
    : Workout(name, caloriesBurned, equipment, difficulty, notes, "Cardio"),
      duration(duration), targetHR(targetHR), distance(distance), calPerMin(calPerMin), focus(focus), environment(environment) {}

void CardioWorkout::setDuration(int d) { duration = d; }
void CardioWorkout::setTargetHR(int hr) { targetHR = hr; }
void CardioWorkout::setDistance(double dist) { distance = dist; }
void CardioWorkout::setCalPerMin(double cpm) { calPerMin = cpm; }
void CardioWorkout::setFocus(string f) { focus = f; }
void CardioWorkout::setEnvironment(string e) { environment = e; }

int CardioWorkout::getDuration() const { return duration; }
int CardioWorkout::getTargetHR() const { return targetHR; }
double CardioWorkout::getDistance() const { return distance; }
double CardioWorkout::getCalPerMin() const { return calPerMin; }
string CardioWorkout::getFocus() const { return focus; }
string CardioWorkout::getEnvironment() const { return environment; }

void CardioWorkout::perform() const {
    cout << "[Cardio] " << name << " | " << duration << "min"
         << " | HR=" << targetHR
         << " | dist=" << distance << "km"
         << " | focus=" << focus
         << " | env=" << environment
         << " | estCal=" << (calPerMin * duration) << "\n";
}

void CardioWorkout::displayCardio() const {
    display();
    cout << "Duration: " << duration << " min\n";
    cout << "Target HR: " << targetHR << "\n";
    cout << "Distance: " << distance << " km\n";
    cout << "Cal/Min: " << calPerMin << "\n";
    cout << "Focus: " << focus << "\n";
    cout << "Environment: " << environment << "\n";
}

#include "strengthWorkoutList.h"

void swl::addWorkout()
{
    StrengthWorkout legPress("Leg Press", "Strength", "Intermediate", 30, 300,6,15,"upper legs");

    workouts.push_back(legPress);

    StrengthWorkout benchPress("Bench Press", "Strength", "Intermediate", 30, 320, 5, 10, "chest");
    workouts.push_back(benchPress);

    StrengthWorkout squats("Squats", "Strength", "Intermediate", 35, 350, 5, 12, "lower body");
    workouts.push_back(squats);

    StrengthWorkout deadlift("Deadlift", "Strength", "Advanced", 30, 360, 5, 8, "lower back");
    workouts.push_back(deadlift);

    StrengthWorkout shoulderPress("Shoulder Press", "Strength", "Beginner", 25, 200, 4, 12, "shoulders");
    workouts.push_back(shoulderPress);

    StrengthWorkout bicepCurl("Bicep Curl", "Strength", "Beginner", 20, 150, 4, 15, "biceps");
    workouts.push_back(bicepCurl);

    StrengthWorkout tricepPushdown("Tricep Pushdown", "Strength", "Beginner", 20, 160, 4, 12, "triceps");
    workouts.push_back(tricepPushdown);

    StrengthWorkout lunges("Lunges", "Strength", "Intermediate", 30, 280, 5, 12, "legs");
    workouts.push_back(lunges);

    StrengthWorkout latPulldown("Lat Pulldown", "Strength", "Intermediate", 25, 260, 4, 10, "back");
    workouts.push_back(latPulldown);

    StrengthWorkout calfRaises("Calf Raises", "Strength", "Beginner", 15, 120, 4, 20, "calves");
    workouts.push_back(calfRaises);
}

void swl::saveToFile(const string& filename) const
{
    ofstream out(filename);
    if (!out) return;

    for (const auto& workout : workouts)
    {
        out << workout.getWorkoutName() << ","
            << workout.getCategory() << ","
            << workout.getDifficulty() << ","
            << workout.getDuration() << ","
            << workout.getCaloriesBurned() << ","
            << workout.getSets() << ","
            << workout.getReps() << ","
            << workout.getTargetMuscle() << endl;
    }

    out.close();
}

void swl::loadFromFile(const string& filename)
{
    ifstream in(filename);
    workouts.clear();

    if (!in) {
        return;
    }

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string workoutName, category, difficulty, targetMuscle;
        int duration, caloriesBurned, sets, reps;

        getline(ss, workoutName, ',');
        getline(ss, category, ',');
        getline(ss, difficulty, ',');
        ss >> duration;
        ss.ignore();
        ss >> caloriesBurned;
        ss.ignore();
        ss >> sets;
        ss.ignore();
        ss >> reps;
        ss.ignore();
        getline(ss, targetMuscle);

        workouts.emplace_back(workoutName, category, difficulty, duration, caloriesBurned,
                              sets, reps, targetMuscle);
    }

    in.close();
}

void swl::displayWorkouts() const
{
    for (const auto& workout : workouts)
    {
        cout << "Workout Name: " << workout.getWorkoutName() << endl;
        cout << "Category: " << workout.getCategory() << endl;
        cout << "Difficulty: " << workout.getDifficulty() << endl;
        cout << "Duration: " << workout.getDuration() << " minutes" << endl;
        cout << "Calories Burned: " << workout.getCaloriesBurned() << endl;
        cout << "Sets: " << workout.getSets() << endl;
        cout << "Reps: " << workout.getReps() << endl;
        cout << "Target Muscle: " << workout.getTargetMuscle() << endl;
        cout << "-----------------------------" << endl;
    }
}
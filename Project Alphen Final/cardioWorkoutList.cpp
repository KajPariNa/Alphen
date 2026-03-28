#include "cardioWorkoutList.h"

void cwl::addWorkout()
{
    CardioWorkout running("Running", "Cardio", "Beginner", 30, 300, 5.0, 10.0);

    workouts.push_back(running);

    CardioWorkout cycling("Cycling", "Cardio", "Beginner", 40, 350, 12.0, 20.0);
    workouts.push_back(cycling);

    CardioWorkout jumpingRope("Jump Rope", "Cardio", "Beginner", 15, 200, 0.0, 0.0);
    workouts.push_back(jumpingRope);

    CardioWorkout briskWalking("Brisk Walking", "Cardio", "Beginner", 45, 250, 3.5, 6.0);
    workouts.push_back(briskWalking);

    CardioWorkout stairClimbing("Stair Climbing", "Cardio", "Intermediate", 20, 220, 0.0, 0.0);
    workouts.push_back(stairClimbing);

    CardioWorkout rowing("Rowing", "Cardio", "Intermediate", 30, 320, 0.0, 0.0);
    workouts.push_back(rowing);

    CardioWorkout swimming("Swimming", "Cardio", "Intermediate", 35, 330, 0.5, 1.0);
    workouts.push_back(swimming);

    CardioWorkout burpees("Burpees", "Cardio", "Advanced", 15, 250, 0.0, 0.0);
    workouts.push_back(burpees);

    CardioWorkout mountainClimbers("Mountain Climbers", "Cardio", "Intermediate", 20, 210, 0.0, 0.0);
    workouts.push_back(mountainClimbers);

    CardioWorkout hiit("HIIT Session", "Cardio", "Advanced", 25, 400, 0.0, 0.0);
    workouts.push_back(hiit);
}

void cwl::displayWorkouts() const
{
    for (const auto& workout : workouts)
    {
        cout << "Workout Name: " << workout.getWorkoutName() << endl;
        cout << "Category: " << workout.getCategory() << endl;
        cout << "Difficulty: " << workout.getDifficulty() << endl;
        cout << "Duration: " << workout.getDuration() << " minutes" << endl;
        cout << "Calories Burned: " << workout.getCaloriesBurned() << " kcal" << endl;
        cout << "Distance: " << workout.getDistance() << " km" << endl;
        cout << "Speed: " << workout.getSpeed() << " km/h" << endl;
        cout << "-----------------------------\n";
    }
}

void cwl::saveToFile(const string& filename) const
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
            << workout.getDistance() << ","
            << workout.getSpeed() << endl;
    }

    out.close();
}

void cwl::loadFromFile(const string& filename)
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
        string workoutName, category, difficulty;
        int duration, caloriesBurned;
        double distance, speed;

        getline(ss, workoutName, ',');
        getline(ss, category, ',');
        getline(ss, difficulty, ',');
        ss >> duration;
        ss.ignore();
        ss >> caloriesBurned;
        ss.ignore();
        ss >> distance;
        ss.ignore();
        ss >> speed;

        workouts.emplace_back(workoutName, category, difficulty, duration, caloriesBurned, distance, speed);
    }

    in.close();
}
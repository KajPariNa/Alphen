#ifndef WORKOUTUI_H
#define WORKOUTUI_H

class WorkoutUI {
private:
    int currentUserID;

    void clearScreen() const;
    void pause() const;

public:
    WorkoutUI(int userID);
    void showWorkoutMenu();

private:
    void createNewPlan();
    void viewMyPlans();
    void browseWorkouts();
};

#endif
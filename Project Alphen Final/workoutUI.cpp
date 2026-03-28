#include "workoutUI.h"
#include "globalWorkoutPlans.h"
#include "strengthWorkoutList.h"
#include "cardioWorkoutList.h"
#include "workoutPlan.h"
#include "exceptions.h"
#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;

WorkoutUI::WorkoutUI(int userID) : currentUserID(userID) {}

void WorkoutUI::clearScreen() const {
    system("cls");
}

void WorkoutUI::pause() const {
    cout << "\nPress any key to continue...";
    _getch();
}

void WorkoutUI::createNewPlan() {
    clearScreen();
    cout << "\n=== CREATE NEW WORKOUT PLAN ===\n\n";

    string planName;
    cout << "Enter Plan Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, planName);

    try
    {
        GlobalWorkoutPlans gwp;
        gwp.loadFromFile("GlobalPlans.txt");

        int nextID = 1;
        for (const auto& p : gwp.plans) {
            if (p.planID >= nextID) nextID = p.planID + 1;
        }

        WorkoutPlan newPlan(nextID, currentUserID, planName);

        // Strength
        cout << "\n=== Strength Workouts (0-9) ===\n";
        swl sw;
        sw.addWorkout();
        sw.displayWorkouts();

        cout << "\nEnter strength numbers (-1 to finish):\n";
        int num;
        while (cin >> num) {
            if (num == -1) break;
            if (num >= 0 && num <= 9) {
                newPlan.addStrength(num);
                cout << "Added #" << num << endl;
            }
            else
            {
                cout << "Invalid number! Enter a value between 0-9 or -1 to stop.\n";
            }
        }

        // Cardio
        cout << "\n=== Cardio Workouts (0-9) ===\n";
        cwl cw;
        cw.addWorkout();
        cw.displayWorkouts();

        cout << "\nEnter cardio numbers (-1 to finish):\n";
        while (cin >> num) {
            if (num == -1) break;
            if (num >= 0 && num <= 9) {
                newPlan.addCardio(num);
                cout << "Added #" << num << endl;
            }
            else
            {
                cout << "Invalid number! Enter a value between 0-9 or -1 to stop.\n";
            }
        }

        gwp.addPlan(newPlan);

        if (!gwp.saveToFile("GlobalPlans.txt"))
            throw FileException();

        cout << "\nPlan '" << planName << "' created successfully!\n";
    }
    catch (const FileException& e)
    {
        cout << "\n" << e.what() << "\n";
        cout << "Could not save workout plan. Please try again.\n";
    }
    catch (const UserException& e)
    {
        cout << "\nWorkout plan error: " << e.what() << "\n";
    }

    pause();
}

void WorkoutUI::viewMyPlans()
{
    clearScreen();
    cout << "\n=== MY WORKOUT PLANS ===\n\n";

    try
    {
        GlobalWorkoutPlans gwp;

        if (!gwp.loadFromFile("GlobalPlans.txt"))
            throw FileException();

        gwp.displayPlans(currentUserID);

        cout << "\nEnter plan number to view details (0 = back): ";
        int n;
        cin >> n;
        if (n <= 0) return;

        int count = 0;
        bool found = false;

        for (const auto& p : gwp.plans)
        {
            if (p.getUserID() == currentUserID)
            {
                count++;
                if (count == n)
                {
                    clearScreen();
                    cout << "\n=== PLAN DETAILS ===\n\n";
                    p.display();
                    pause();
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << "\nInvalid plan number!\n";
            pause();
        }
    }
    catch (const FileException& e)
    {
        cout << "\n" << e.what() << "\n";
        cout << "Could not load workout plans.\n";
        pause();
    }
    catch (const UserException& e)
    {
        cout << "\nError viewing plans: " << e.what() << "\n";
        pause();
    }
}

void WorkoutUI::browseWorkouts() {
    int choice;
    do {
        clearScreen();
        cout << "\n=== BROWSE WORKOUTS ===\n";
        cout << "1. Strength Workouts\n";
        cout << "2. Cardio Workouts\n";
        cout << "3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        try
        {
            if (choice == 1) {
                clearScreen();
                cout << "\n=== STRENGTH WORKOUTS ===\n";
                swl sw;
                sw.addWorkout();
                sw.displayWorkouts();
                pause();
            }
            else if (choice == 2) {
                clearScreen();
                cout << "\n=== CARDIO WORKOUTS ===\n";
                cwl cw;
                cw.addWorkout();
                cw.displayWorkouts();
                pause();
            }
            else if (choice != 3)
            {
                cout << "\nInvalid choice! Please select 1, 2, or 3.\n";
                pause();
            }
        }
        catch (const UserException& e)
        {
            cout << "\nBrowse error: " << e.what() << "\n";
            pause();
        }

    } while (choice != 3);
}

void WorkoutUI::showWorkoutMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n====================================\n";
        cout << "         WORKOUT MENU\n";
        cout << "====================================\n\n";

        cout << "1. Create New Plan\n";
        cout << "2. View My Plans\n";
        cout << "3. Browse Workouts\n";
        cout << "4. Back to Dashboard\n\n";

        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice) {
                case 1: createNewPlan();  break;
                case 2: viewMyPlans();    break;
                case 3: browseWorkouts(); break;
                case 4: return;
                default:
                    cout << "\nInvalid choice!\n";
                    pause();
            }
        }
        catch (const FileException& e)
        {
            cout << "\n" << e.what() << "\n";
            pause();
        }
        catch (const UserException& e)
        {
            cout << "\nWorkout menu error: " << e.what() << "\n";
            pause();
        }

    } while (true);
}

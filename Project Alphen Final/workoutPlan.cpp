#include "workoutPlan.h"

WorkoutPlan::WorkoutPlan(int pid, int uid, string name)
{
    planID = pid;
    userID = uid;
    planName = name;
}

void WorkoutPlan::addStrength(int idx)
{
    strengths.push_back(idx);
}

void WorkoutPlan::addCardio(int idx)
{
    cardios.push_back(idx);
}

int WorkoutPlan::getUserID() const
{
    return userID;
}

void WorkoutPlan::display() const
{
    cout << "Plan ID     : " << planID << endl;
    cout << "User ID     : " << userID << endl;
    cout << "Plan Name   : " << planName << endl << endl;

    swl sw;
    cwl cw;
    sw.addWorkout();
    cw.addWorkout();

    cout << "=== STRENGTH WORKOUTS ===\n";
    if (strengths.empty())
        cout << "No strength workouts.\n";
    else
    {
        for (size_t i = 0; i < strengths.size(); i++)
        {
            int idx = strengths[i];
            if (idx >= 0 && idx < (int)sw.workouts.size())
            {
                cout << (i+1) << ". ";
                sw.workouts[idx].display();
                cout << "-----------------------------\n";
            }
        }
    }

    cout << "\n=== CARDIO WORKOUTS ===\n";
    if (cardios.empty())
        cout << "No cardio workouts.\n";
    else
    {
        for (size_t i = 0; i < cardios.size(); i++)
        {
            int idx = cardios[i];
            if (idx >= 0 && idx < (int)cw.workouts.size())
            {
                cout << (i+1) << ". ";
                cw.workouts[idx].display();
                cout << "-----------------------------\n";
            }
        }
    }
}

string WorkoutPlan::serialize() const
{
    stringstream ss;
    ss << planID << "," << userID << "," << planName << "\n";
    ss << strengths.size() << "\n";
    for (int id : strengths) ss << id << " ";
    ss << "\n";
    ss << cardios.size() << "\n";
    for (int id : cardios) ss << id << " ";
    ss << "\n";
    return ss.str();
}

WorkoutPlan WorkoutPlan::deserialize(ifstream &in)
{
    string line;
    if (!getline(in, line) || line.empty()) 
        return WorkoutPlan(0, 0, "");

    stringstream ss(line);
    int pid = 0, uid = 0;
    string name = "";

    ss >> pid;
    ss.ignore();
    ss >> uid;
    ss.ignore();
    getline(ss, name);

    WorkoutPlan plan(pid, uid, name);

    int n = 0;
    in >> n;
    for (int i = 0; i < n; i++) {
        int id = 0;
        in >> id;
        plan.strengths.push_back(id);
    }
    string dummy;
    getline(in, dummy);

    in >> n;
    for (int i = 0; i < n; i++) {
        int id = 0;
        in >> id;
        plan.cardios.push_back(id);
    }
    getline(in, dummy);

    return plan;
}
#include "globalWorkoutPlans.h"
#include <fstream>
#include <sstream>

void GlobalWorkoutPlans::addPlan(WorkoutPlan plan)
{
    plans.push_back(plan);
}

void GlobalWorkoutPlans::displayPlans(int id) 
{
    int cnt = 1;
    bool found = false;

    cout << "Your Workout Plans:\n\n";

    for (const auto& p : plans)
    {
        if (id == p.getUserID())
        {
            cout << cnt << ". " << p.planName << endl;
            cnt++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No plans found for your account.\n";
        cout << "Create a new plan using option 1.\n";
    }
}

bool GlobalWorkoutPlans::saveToFile(const string& filename) const
{
    ofstream out(filename);
    if (!out) return false;

    for (const auto& plan : plans)
    {
        out << plan.serialize();
    }
    out.close();
    return true;
}

bool GlobalWorkoutPlans::loadFromFile(const string& filename)
{
    ifstream in(filename);
    plans.clear();

    if (!in.is_open()) return false;

    string line;
    while (getline(in, line))
    {
        // Skip garbage lines (empty or no comma)
        if (line.empty() || line.find(',') == string::npos) continue;

        stringstream ss(line);
        int pid = 0, uid = 0;
        string name;

        if (!(ss >> pid)) continue;
        ss.ignore();
        if (!(ss >> uid)) continue;
        ss.ignore();
        getline(ss, name);

        if (name.empty() || pid <= 0) continue;

        WorkoutPlan plan(pid, uid, name);

        int n = 0;
        if (!(in >> n)) break;
        for (int i = 0; i < n; i++)
        {
            int id = 0;
            if (in >> id)
                plan.strengths.push_back(id);
        }
        getline(in, line); // clean up

        if (!(in >> n)) break;
        for (int i = 0; i < n; i++)
        {
            int id = 0;
            if (in >> id)
                plan.cardios.push_back(id);
        }
        getline(in, line); // clean up

        plans.push_back(plan);
    }

    in.close();
    return true;
}
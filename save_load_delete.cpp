#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

enum ExerciseID : unsigned int {
    ID_EXIT = 0u,
    ID_STRENGTH_WORKOUT = 1u,
    ID_CARDIO_WORKOUT = 2u,
    ID_CHEST_BACK = 11u,
    ID_LEGS = 12u,
    ID_BICEPS_TRICEPS = 13u,
    ID_ABS = 14u,
    ID_DUMBBELL_ROW = 101u,
    ID_BENCH_PRESS = 102u,
    ID_PUSHUP = 103u,
    ID_PULLUP = 104u,
    ID_SQUAT = 201u,
    ID_LEG_PRESS = 202u,
    ID_CALF_RAISE = 203u,
    ID_FROG_JUMP = 204u,
    ID_LUNGE = 205u,
    ID_BICEP_CURL = 301u,
    ID_CABLE_CURL = 302u,
    ID_BARBELL_CURL = 303u,
    ID_DIAMOND_PUSHUP = 304u,
    ID_BANDED_CRUNCH = 401u,
    ID_ABCOASTER_CRUNCH = 402u,
    ID_BICYCLE_CRUNCH = 403u,
    ID_HANGING_LEG_RAISE = 404u,
    ID_CYCLING = 21u,
    ID_ELLIPTICAL_TRAINER = 22u,
    ID_ROWING_MACHINE = 23u,
    ID_RUNNING = 24u
};


Exercise* createExerciseByID(unsigned int id)
{
    switch (id)
    {
        case ID_DUMBBELL_ROW:       return new DumbbellRow();
        case ID_BENCH_PRESS:        return new BenchPress();
        case ID_PUSHUP:             return new Pushup();
        case ID_PULLUP:             return new Pullup();
        case ID_SQUAT:              return new Squat();
        case ID_LEG_PRESS:          return new LegPress();
        case ID_CALF_RAISE:         return new CalfRaise();
        case ID_FROG_JUMP:          return new FrogJump();
        case ID_LUNGE:              return new Lunge();
        case ID_BICEP_CURL:         return new BicepCurl();
        case ID_CABLE_CURL:         return new CableCurl();
        case ID_BARBELL_CURL:       return new BarbellCurl();
        case ID_DIAMOND_PUSHUP:     return new DiamondPushup();
        case ID_BANDED_CRUNCH:      return new BandedCrunch();
        case ID_ABCOASTER_CRUNCH:   return new AbcoasterCrunch();
        case ID_BICYCLE_CRUNCH:     return new BicycleCrunch();
        case ID_HANGING_LEG_RAISE:  return new HangingLegRaise();
        case ID_CYCLING:            return new Cycling();
        case ID_ELLIPTICAL_TRAINER: return new EllipticalTrainer();
        case ID_ROWING_MACHINE:     return new RowingMachine();
        case ID_RUNNING:            return new Running();
        default:                    return nullptr;
    }
}

vector<pair<string, vector<unsigned int>>> planners;

bool isCardioExercise(unsigned int id) {
    return id == ID_CYCLING ||
           id == ID_ELLIPTICAL_TRAINER ||
           id == ID_ROWING_MACHINE ||
           id == ID_RUNNING;
}

bool isStrengthExercise(unsigned int id) {
    return id >= 101u && id <= 404u;
}

void showAllPlans() {
    if (planners.empty()) {
        cout << "No plans yet.\n";
        return;
    }
    cout << "\nYour plans:\n";
    for (size_t i = 0; i < planners.size(); i++) {
        string name = planners[i].first;
        if (name.empty()) name = "(Unnamed plan)";
        cout << i + 1 << ") " << name << " ("
             << planners[i].second.size() << " exercises)\n";
    }
    cout << "\n";
}

void showOnePlan(size_t index) {
    if (index >= planners.size()) {
        cout << "Wrong plan number!\n";
        return;
    }

    auto& plan = planners[index];
    cout << "\nWorkout Plan: " << plan.first << "\n\n";

    if (plan.second.empty()) {
        cout << "   (no exercises)\n";
        return;
    }

    for (unsigned int id : plan.second) {
        Exercise* ex = createExerciseByID(id);
        if (ex) {
            cout << "  - " << ex->getName() << "\n";
            delete ex;
        }
    }
    cout << "\n";
}

bool savePlanToFile(const string& name, const vector<unsigned int>& exercises, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return false;

    file << name;
    for (unsigned int id : exercises) {
        file << "," << id;
    }
    file << "\n";
    return true;
}

pair<string, vector<unsigned int>> loadPlanFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return {"", {}};
    }

    string line;
    if (!getline(file, line)) {
        return {"", {}};
    }

    stringstream ss(line);
    string token;
    if (!getline(ss, token, ',')) {
        return {"", {}};
    }

    string planName = token;
    vector<unsigned int> ids;

    while (getline(ss, token, ',')) {
        if (token.empty()) continue;
        try {
            unsigned int id = stoul(token);
            ids.push_back(id);
        } catch (...) {}
    }

    return {planName, ids};
}

string toLower(string s) {
    for (char &c : s) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return s;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Workout Planner ===\n";
        cout << "1. Create new plan\n";
        cout << "2. View all plans\n";
        cout << "3. View one plan\n";
        cout << "4. Add exercise to plan\n";
        cout << "5. Delete plan\n";
        cout << "6. Save plan to file\n";
        cout << "7. Load plan from file\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string name;
            bool validName = false;
            while (!validName) {
                cout << "Plan name: ";
                cin.ignore();
                getline(cin, name);

                size_t start = name.find_first_not_of(" \t");
                if (start == string::npos) {
                    name.clear();
                } else {
                    size_t end = name.find_last_not_of(" \t");
                    name = name.substr(start, end - start + 1);
                }

                if (name.empty()) {
                    cout << "Error: Plan name cannot be empty.\n";
                } else {
                    validName = true;
                }
            }

            string typeInput;
            cout << "Type of workout (strength / cardio): ";
            getline(cin, typeInput);
            string type = toLower(typeInput);

            vector<unsigned int> exercises;

            if (type == "strength" || type == "str" || type == "s") {
                cout << "Strength plan - default exercises added\n";
                exercises.push_back(ID_DUMBBELL_ROW);
                exercises.push_back(ID_BENCH_PRESS);
                exercises.push_back(ID_SQUAT);
                exercises.push_back(ID_BICEP_CURL);
                exercises.push_back(ID_BANDED_CRUNCH);
            }
            else if (type == "cardio" || type == "c") {
                cout << "Cardio plan - default exercises added\n";
                exercises.push_back(ID_CYCLING);
                exercises.push_back(ID_ELLIPTICAL_TRAINER);
                exercises.push_back(ID_RUNNING);
            }
            else {
                cout << "Unknown type - creating empty plan\n";
            }

            planners.push_back({name, exercises});
            cout << "Plan \"" << name << "\" created!\n";
        }
        else if (choice == 2) {
            showAllPlans();
        }
        else if (choice == 3) {
            showAllPlans();
            if (planners.empty()) continue;
            size_t num;
            cout << "Which plan (number)? ";
            cin >> num;
            showOnePlan(num - 1);
        }
        else if (choice == 4) {
            showAllPlans();
            if (planners.empty()) continue;

            size_t planNum;
            cout << "Add to which plan? ";
            cin >> planNum;
            if (planNum < 1 || planNum > planners.size()) {
                cout << "Wrong number!\n";
                continue;
            }

            string planType = toLower(planners[planNum - 1].first);
            bool isCardio = (planType.find("cardio") != string::npos);

            unsigned int exID;
            cout << "Enter exercise ID: ";
            cin >> exID;

            bool allowed = false;

            if (isCardio) {
                if (isCardioExercise(exID)) {
                    allowed = true;
                } else {
                    cout << "Error: Cardio plans can only include Cycling (21), Elliptical Trainer (22), Rowing Machine (23), Running (24).\n";
                }
            } else {
                if (isStrengthExercise(exID)) {
                    allowed = true;
                } else {
                    cout << "Error: Strength plans cannot include cardio exercises.\n";
                }
            }

            if (allowed) {
                planners[planNum - 1].second.push_back(exID);
                cout << "Exercise added!\n";
            }
        }
        else if (choice == 5) {
            showAllPlans();
            if (planners.empty()) continue;

            size_t num;
            cout << "Delete which plan? ";
            cin >> num;
            if (num < 1 || num > planners.size()) {
                cout << "Wrong number!\n";
                continue;
            }

            planners.erase(planners.begin() + (num - 1));
            cout << "Plan deleted.\n";
        }
        else if (choice == 6) {
            showAllPlans();
            if (planners.empty()) continue;

            size_t num;
            cout << "Save which plan? ";
            cin >> num;
            if (num < 1 || num > planners.size()) {
                cout << "Wrong number!\n";
                continue;
            }

            string fname;
            cout << "Filename (example: strength.txt): ";
            cin >> fname;

            auto& p = planners[num - 1];
            if (savePlanToFile(p.first, p.second, fname)) {
                cout << "Saved!\n";
            } else {
                cout << "Cannot save.\n";
            }
        }
        else if (choice == 7) {
            string fname;
            cout << "Filename to load: ";
            cin >> fname;

            auto loaded = loadPlanFromFile(fname);
            if (loaded.first.empty()) {
                cout << "Cannot load or file empty.\n";
            } else {
                planners.push_back(loaded);
                cout << "Plan loaded: " << loaded.first << "\n";
            }
        }
        else {
            cout << "Wrong choice.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
#include "loginUI.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

string s;
string pk;
string UserSystem::getPassword()
{
    string password = "";
    char ch;

    while((ch = _getch()) != 13)
    {
        if(ch == 8)
        {
            if(password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password += ch;
            cout << "*";
        }
    }

    cout << endl;
    return password;
}

bool UserSystem::usernameExists(string username)
{
    ifstream file("users.txt");

    if (!file.is_open())
        throw FileException();

    int id;
    string u, p;
    bool q;

    while (file >> id >> u >> p >> q)
    {
        if(u == username)
            return true;
    }
    return false;
}

void UserSystem::header()
{
    cout << "=======================================================\n";
    cout << "   AAAA   LL      PPPPPP  HH   HH EEEEEEE NN   NN\n";
    cout << "  AA  AA  LL      PP   PP HH   HH EE      NNN  NN\n";
    cout << " AA    AA LL      PP   PP HH   HH EE      NN N NN\n";
    cout << " AAAAAAAA LL      PPPPPP  HHHHHHH EEEEE   NN  NNN\n";
    cout << " AA    AA LL      PP      HH   HH EE      NN   NN\n";
    cout << " AA    AA LLLLLLL PP      HH   HH EEEEEEE NN   NN\n";
    cout << "======================================================\n";
}

void UserSystem::registerUser()
{
    string username, password;

    cout << "\n------------- REGISTER --------------\n";

    cout << "Set Username   : ";
    cin >> username;

    try
    {
        if (usernameExists(username))
            throw UserExistsException();
    }
    catch (const UserExistsException& e)
    {
        cout << "\n" << e.what() << "\n";
        return;
    }
    catch (const FileException& e)
    {
        cout << "\n" << e.what() << "\n";
        return;
    }

    cout << "Set Password   : ";
    password = getPassword();

    try
    {
        userlist baka;
        baka.loadFromFile("users.txt");
        baka.addUser(user(username, password));
        baka.saveToFile("users.txt");
    }
    catch (...)
    {
        throw FileException();
    }

    cout << "\nRegistration Successful!\n";
}

void UserSystem::loginUser()
{
    string username, password;

    cout << "\n--------------- LOGIN ---------------\n";

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    password = getPassword();

    try
    {
        userlist baka;
        baka.loadFromFile("users.txt");

        if (baka.login(username, password))
        {
            cout << "\nLogin Successful! Redirecting to dashboard...\n";

            ifstream file("users.txt");
            if (!file.is_open())
                throw FileException();

            int id;
            string u, p;
            bool q;
            currentUserID = -1;

            while (file >> id >> u >> p >> q)
            {
                if (u == username)
                {
                    currentUserID = id;
                    break;
                }
            }
            file.close();

            _getch();
            dashboard();
        }
        else
        {
            throw LoginException();
        }
    }
    catch (const LoginException& e)
    {
        cout << "\n" << e.what() << "\n";
        cout << "Please try again.\n";
        _getch();
    }
    catch (const FileException& e)
    {
        cout << "\n" << e.what() << "\n";
        _getch();
    }
}

void UserSystem::dashboard()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "\nDASHBOARD\n";
        cout << "====================================\n";

        cout << "1. Workout Plan\n";
        cout << "2. Premium Features\n";
        cout << "3. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                try
                {
                    WorkoutUI workout(currentUserID);
                    workout.showWorkoutMenu();
                }
                catch (const FileException& e)
                {
                    cout << "\n" << e.what() << "\n";
                }
                catch (const UserException& e)
                {
                    cout << "\nWorkout error: " << e.what() << "\n";
                }
            }
            break;

            case 2:
            {
                try
                {
                    premiumPlan base(currentUserID);

                    bool hasPremium = base.loadPremiumStatusFromUsersFile("users.txt");

                    if(hasPremium)
                    {
                        cout << "\nPremium already active for this user!\n";
                    }
                    else
                    {
                        int premiumChoice;

                        cout << "\n====================================\n";
                        cout << "       PREMIUM ACCESS SYSTEM        \n";
                        cout << "====================================\n";

                        cout << "Do you want to activate Premium?\n";
                        cout << "1. Yes\n";
                        cout << "2. No\n";
                        cout << "Enter choice: ";
                        cin >> premiumChoice;

                        if(premiumChoice == 1)
                        {
                            int planChoice;

                            cout << "\nSelect Subscription Plan:\n";
                            cout << "1. Monthly Plan\n";
                            cout << "2. Quarterly Plan\n";
                            cout << "3. Yearly Plan\n";
                            cout << "Enter choice: ";
                            cin >> planChoice;

                            base.setPackagePrice(1000);
                            base.applyPromoCodeDeal();
                            base.hasDonePaymentProcess();

                            if(planChoice == 1)
                            {
                                monthlyPlan m(currentUserID);
                                m.setIsPaid(true);
                                m.activateMonthlyPlan();
                            }
                            else if(planChoice == 2)
                            {
                                quarterlyPlan q(currentUserID);
                                q.setIsPaid(true);
                                q.activateQuarterlyPlan();
                            }
                            else if(planChoice == 3)
                            {
                                yearlyPlan y(currentUserID);
                                y.setIsPaid(true);
                                y.activateYearlyPlan();
                            }
                            else
                            {
                                cout << "Invalid plan choice!\n";
                                break;
                            }

                            cout << "\nPremium Activated Successfully!\n";
                        }
                        else
                        {
                            cout << "\nContinuing with Free Plan...\n";
                            break;
                        }
                    }

                    int featureChoice;

                    do
                    {
                        cout << "\n=========== PREMIUM FEATURES ==========\n";
                        cout << "1. Diet Chart\n";
                        cout << "2. Calorie Intake Tracker\n";
                        cout << "3. Calorie Burn Tracker\n";
                        cout << "4. Net Calories\n";
                        cout << "5. Sigma Power Index\n";
                        cout << "6. Motivation Quote\n";
                        cout << "7. Exit Premium\n";

                        cout << "\nEnter choice: ";
                        cin >> featureChoice;

                        try
                        {
                            switch(featureChoice)
                            {
                                case 1: base.dietChart();                        break;
                                case 2: base.daily_calorie_intake_tracker();     break;
                                case 3: base.daily_calorie_burner_tracker();     break;
                                case 4: base.net_calorie_per_day_tracker();      break;
                                case 5: base.sigma_power_index();                break;
                                case 6: base.famousRandQuotes();                 break;
                                case 7: cout << "Exiting Premium...\n";          break;
                                default: cout << "Invalid choice\n";
                            }
                        }
                        catch (const UserException& e)
                        {
                            cout << "\nPremium feature error: " << e.what() << "\n";
                        }

                        if(featureChoice != 7)
                        {
                            cout << "\nPress any key...";
                            _getch();
                        }

                    } while(featureChoice != 7);
                }
                catch (const FileException& e)
                {
                    cout << "\n" << e.what() << "\n";
                }
                catch (const UserException& e)
                {
                    cout << "\nPremium error: " << e.what() << "\n";
                }
            }
            break;

            case 3:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice\n";
        }

        if(choice != 3)
        {
            cout << "\nPress any key to continue...";
            _getch();
        }

    } while(choice != 3);
}

void UserSystem::showMainMenu()
{
    int choice;

    while(true)
    {
        system("cls");
        header();

        cout << "\n          WELCOME TO ALPHEN          \n";
        cout << "================================================\n";
        cout << "  1. Register (Create New Account)            \n";
        cout << "  2. Login (Already have an account)          \n";
        cout << "  3. Exit                                     \n";
        cout << "================================================\n";
        cout << "\nEnter your choice (1-3): ";

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nPlease enter a number!\n";
            _getch();
            continue;
        }

        cout << endl;

        switch(choice)
        {
            case 1:
                try
                {
                    registerUser();
                }
                catch (const UserExistsException& e)
                {
                    cout << "\n" << e.what() << "\n";
                }
                catch (const FileException& e)
                {
                    cout << "\n" << e.what() << "\n";
                }
                catch (const UserException& e)
                {
                    cout << "\nRegistration error: " << e.what() << "\n";
                }
                cout << "\nPress any key to return to main menu...";
                _getch();
                break;

            case 2:
                try
                {
                    loginUser();
                }
                catch (const LoginException& e)
                {
                    cout << "\n" << e.what() << "\n";
                    _getch();
                }
                catch (const FileException& e)
                {
                    cout << "\n" << e.what() << "\n";
                    _getch();
                }
                catch (const UserException& e)
                {
                    cout << "\nLogin error: " << e.what() << "\n";
                    _getch();
                }
                break;

            case 3:
                cout << "\nThank you for using Alphen. Goodbye!\n\n";
                return;

            default:
                cout << "\nInvalid choice! Please select 1, 2 or 3.\n";
                _getch();
                break;
        }
    }
}

#include "UserSystem.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

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
    string gmail, user, pass;

    while(file >> gmail >> user >> pass)
    {
        if(user == username)
            return true;
    }

    return false;
}

void UserSystem::header()
{
    cout << "\n====================================\n";
    cout << "   AAAA   LL      PPPPPP  HH   HH EEEEEEE NN   NN\n";
    cout << "  AA  AA  LL      PP   PP HH   HH EE      NNN  NN\n";
    cout << " AA    AA LL      PP   PP HH   HH EE      NN N NN\n";
    cout << " AAAAAAAA LL      PPPPPP  HHHHHHH EEEEE   NN  NNN\n";
    cout << " AA    AA LL      PP      HH   HH EE      NN   NN\n";
    cout << " AA    AA LLLLLLL PP      HH   HH EEEEEEE NN   NN\n";
    cout << "====================================\n";
}

void UserSystem::registerUser()
{
    string gmail, username, password;

    cout << "\n------------- REGISTER --------------\n";

    cout << "Enter Gmail    : ";
    cin >> gmail;

    cout << "Set Username   : ";
    cin >> username;

    if(usernameExists(username))
    {
        cout << "\nUsername already exists!\n";
        return;
    }

    cout << "Set Password   : ";
    password = getPassword();

    ofstream file("users.txt", ios::app);
    file << gmail << " " << username << " " << password << endl;

    cout << "\nRegistration Successful!\n";
}

void UserSystem::loginUser()
{
    string username, password;
    string f_gmail, f_user, f_pass;
    bool found = false;

    cout << "\n--------------- LOGIN ---------------\n";

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    password = getPassword();

    ifstream file("users.txt");

    while(file >> f_gmail >> f_user >> f_pass)
    {
        if(username == f_user && password == f_pass)
        {
            found = true;
            break;
        }
    }

    if(found)
    {
        cout << "\nLogin Successful!\n";
        dashboard();
    }
    else
        cout << "\nInvalid Username or Password!\n";
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
        cout << "2. Diet Plan\n";
        cout << "3. Progress Tracker\n";
        cout << "4. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nWorkout feature coming soon\n";
                break;

            case 2:
                cout << "\nDiet feature coming soon\n";
                break;

            case 3:
                cout << "\nProgress feature coming soon\n";
                break;

            case 4:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice\n";
        }

    } while(choice != 4);
}
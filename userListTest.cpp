#include <bits/stdc++.h>
#include "userlist.h"
using namespace std;


int main()
{
    cout<<"Ojo sama, press 1 for sign up"<<endl<<"press 2 for sign in"<<endl;
    int choice;
    cin>>choice;

    if(choice==1)
    {
        string a,b;
        cout<<"Please give us your new name and password"<<endl;
        cin>>a>>b;

        userlist c;
        c.addUser(user(a,b));

        cout<<"New user created, wanna be a premium user??"<<endl<<"Then press 1 or choose 0 to exit"<<endl;
        
        int choice2;
        cin>>choice2;
        if(choice2==1)
        {
            //Here will be some processing of payments





            //

            cout<<"Congo!! You are a premium user now"<<endl;
            c.changePremium(true);
            c.saveToFile("userlist.txt");
        }
        else
        {
            c.saveToFile("userlist.txt");
        }

    }
    else
    {
        string c,d;
        cout<<"Please enter name and password"<<endl;
        cin>>c>>d;
        userlist b;
        b.loadFromFile("userlist.txt");
        if(b.login(c,d))
        {
            cout<<"You are logged in Ozo sama"<<endl;
            if(b.isPremium())
            {
                cout<<"You have premium access"<<endl;
            }
            else
            {
                cout<<"You don't have premium access"<<endl;
            }
        }
        else
        {
            cout<<"You are a liar, Ozo sama"<<endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

    class user
    {
        private:
            string name;
            string password;
            //date DOB;
        public:
            bool logstatus=false;
            bool hasPremium=false;
            user(string a,string b);
            string getName();
            string getPass();
            bool check(string u,string p);
    };
#ifndef CARDIOFOCUS_H
#define CARDIOFOCUS_H

#include <bits/stdc++.h>
using namespace std;

class CardioFocus {
private:
    string focus;
    string location;

public:
    CardioFocus(string focus = "Endurance", string location = "Indoor");

    string getFocus() const;
    string getLocation() const;

    void setFocus(string f);
    void setLocation(string l);

    friend ostream& operator<<(ostream& os, const CardioFocus& c);
    friend istream& operator>>(istream& is, CardioFocus& c);
};

#endif

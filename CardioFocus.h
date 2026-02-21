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

    void setFocus(string f);
    void setLocation(string l);

    string getFocus() const;
    string getLocation() const;
};

#endif

#ifndef STRENGTHSPLIT_H
#define STRENGTHSPLIT_H

#include <bits/stdc++.h>
using namespace std;

class StrengthSplit {
private:
    string split; // Push / Pull / Legs

public:
    StrengthSplit(string split = "Push");

    string getSplit() const;
    void setSplit(string s);

    bool isPush() const;
    bool isPull() const;
    bool isLegs() const;

    friend ostream& operator<<(ostream& os, const StrengthSplit& s);
    friend istream& operator>>(istream& is, StrengthSplit& s);
};

#endif

#ifndef STRENGTHSPLIT_H
#define STRENGTHSPLIT_H

#include <bits/stdc++.h>
using namespace std;

class StrengthSplit {
private:
    string split;

public:
    StrengthSplit(string split = "Push");

    void setSplit(string s);
    string getSplit() const;

    bool isPush() const;
    bool isPull() const;
    bool isLegs() const;
};

#endif

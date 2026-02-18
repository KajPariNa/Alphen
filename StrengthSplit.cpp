#include "StrengthSplit.h"

StrengthSplit::StrengthSplit(string split) : split(split) {}

string StrengthSplit::getSplit() const { return split; }
void StrengthSplit::setSplit(string s) { split = s; }

bool StrengthSplit::isPush() const { return split == "Push"; }
bool StrengthSplit::isPull() const { return split == "Pull"; }
bool StrengthSplit::isLegs() const { return split == "Legs"; }

ostream& operator<<(ostream& os, const StrengthSplit& s) {
    os << s.split;
    return os;
}

istream& operator>>(istream& is, StrengthSplit& s) {
    is >> s.split;
    return is;
}

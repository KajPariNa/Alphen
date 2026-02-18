#include "StrengthSplit.h"

StrengthSplit::StrengthSplit(string split) : split(split) {}
void StrengthSplit::setSplit(string s) { split = s; }
string StrengthSplit::getSplit() const { return split; }
bool StrengthSplit::isPush() const { return split == "Push"; }
bool StrengthSplit::isPull() const { return split == "Pull"; }
bool StrengthSplit::isLegs() const { return split == "Legs"; }

#include "CardioFocus.h"

CardioFocus::CardioFocus(string focus, string location) : focus(focus), location(location) {}

string CardioFocus::getFocus() const { return focus; }
string CardioFocus::getLocation() const { return location; }

void CardioFocus::setFocus(string f) { focus = f; }
void CardioFocus::setLocation(string l) { location = l; }

ostream& operator<<(ostream& os, const CardioFocus& c) {
    os << c.focus << " " << c.location;
    return os;
}

istream& operator>>(istream& is, CardioFocus& c) {
    is >> c.focus >> c.location;
    return is;
}

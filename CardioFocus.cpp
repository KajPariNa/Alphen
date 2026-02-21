#include "CardioFocus.h"

CardioFocus::CardioFocus(string focus, string location) : focus(focus), location(location) {}
void CardioFocus::setFocus(string f) { focus = f; }
void CardioFocus::setLocation(string l) { location = l; }
string CardioFocus::getFocus() const { return focus; }
string CardioFocus::getLocation() const { return location; }

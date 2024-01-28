#include "Option.h"

Option::Option(double expiry) : _expiry(expiry) {}

double Option::getExpiry() const 
{
    return _expiry;
}
double Option::payoffPath(std::vector<double> val) const {
    return payoff(val.back());
}
bool Option::isAsianOption() const {
    return false;
}
bool Option::isAmericanOption() const {
    return false; 
}

Option::~Option() {}
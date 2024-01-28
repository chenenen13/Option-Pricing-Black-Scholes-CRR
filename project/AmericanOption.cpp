#include "AmericanOption.h"

AmericanOption::AmericanOption(double expiry) : Option(expiry) {}

bool AmericanOption::isAmericanOption() const {
    return true;  
}

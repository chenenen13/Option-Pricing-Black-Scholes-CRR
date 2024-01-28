#include "AmericanCallOption.h"
#include <algorithm> 

AmericanCallOption::AmericanCallOption(double expiry, double strikePrice)
    : AmericanOption(expiry), _strikePrice(strikePrice) {}

double AmericanCallOption::payoff(double spotPrice) const {
    return std::max(spotPrice - _strikePrice, 0.0);
}


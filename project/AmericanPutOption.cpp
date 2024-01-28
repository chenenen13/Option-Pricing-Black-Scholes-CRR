#include "AmericanPutOption.h"
#include <algorithm> 

AmericanPutOption::AmericanPutOption(double expiry, double strikePrice)
    : AmericanOption(expiry), _strikePrice(strikePrice) {}

double AmericanPutOption::payoff(double spotPrice) const {
    return std::max(_strikePrice - spotPrice, 0.0); 
}

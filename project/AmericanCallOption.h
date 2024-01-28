#pragma once
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption {
private:
    double _strikePrice; 

public:
    AmericanCallOption(double expiry, double strikePrice);
    virtual double payoff(double spotPrice) const override;
};

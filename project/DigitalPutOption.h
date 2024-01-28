#pragma once 

#include "DigitalOption.h"

class DigitalPutOption : public DigitalOption
{
public:
    DigitalPutOption(double expiry, double strike);

    double payoff(double spotPrice) const override;
    DigitalOption::OptionType GetOptionType() const override;
};


#pragma once 
#include "VanillaOption.h"

class PutOption : public VanillaOption 
{
public:
    PutOption(double expiry, double strike);

    double payoff(double spotPrice) const override;
    VanillaOption::OptionType GetOptionType() const override;
};


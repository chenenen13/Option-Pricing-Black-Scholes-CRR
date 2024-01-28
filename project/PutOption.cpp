#include "PutOption.h"

PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

double PutOption::payoff(double spotPrice) const 
{
    return (spotPrice <= getStrike()) ? (getStrike() - spotPrice) : 0.0;
}

VanillaOption::OptionType PutOption::GetOptionType() const 
{
    return VanillaOption::OptionType::Put;
}

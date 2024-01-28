#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalPutOption::payoff(double spotPrice) const
{
    return (spotPrice <= getStrike()) ? (1.0) : 0.0;
}

DigitalOption::OptionType DigitalPutOption::GetOptionType() const
{
    return DigitalOption::OptionType::Put;
}

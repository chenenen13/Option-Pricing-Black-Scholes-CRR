#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalCallOption::payoff(double spotPrice) const {
    return (spotPrice >= getStrike()) ? (1.0) : 0.0;
}

DigitalOption::OptionType DigitalCallOption::GetOptionType() const
{
    return DigitalOption::OptionType::Call;
}

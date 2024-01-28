#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

double CallOption::payoff(double spotPrice) const {
    return (spotPrice >= getStrike()) ? (spotPrice - getStrike()) : 0.0;
}

VanillaOption::OptionType CallOption::GetOptionType() const 
{
    return VanillaOption::OptionType::Call;
}

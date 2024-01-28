#include "VanillaOption.h"

VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) 
{
    ValidateArguments();
}

VanillaOption::OptionType VanillaOption::GetOptionType() const {
    // To be implemented in derived classes (CallOption and PutOption)
    return OptionType::Call; 
}

void VanillaOption::ValidateArguments() const 
{
    if (getExpiry() < 0 || _strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative.");
    }
}

double VanillaOption::getStrike() const 
{
    return _strike;
}


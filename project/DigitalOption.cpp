#include "DigitalOption.h"
#include <stdexcept>  // Include the <stdexcept> header


DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {
    ValidateArguments_Digital();
}

DigitalOption::OptionType DigitalOption::GetOptionType() const {
    // To be implemented in derived classes (CallOption and PutOption)
    return OptionType::Call;  // Default implementation, you can override it.
}

void DigitalOption::ValidateArguments_Digital() const
{
    if (getExpiry() < 0 || _strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative.");
    }
}

double DigitalOption::getStrike() const
{
    return _strike;
}


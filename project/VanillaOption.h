#pragma once 
#include "Option.h"

class VanillaOption : public Option 
{
public:
    VanillaOption(double expiry, double strike);
    virtual OptionType GetOptionType() const;
    double getStrike() const;

private:
    double _strike;
    void ValidateArguments() const;
};
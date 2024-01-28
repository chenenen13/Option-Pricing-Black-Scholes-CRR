#pragma once 
#include "Option.h"

class DigitalOption : public Option
{
public:
    enum OptionType { Call, Put };
    DigitalOption(double expiry, double strike);
    virtual OptionType GetOptionType() const;
    double getStrike() const;

private:
    double _strike;
    void ValidateArguments_Digital() const;
};

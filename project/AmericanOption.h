#pragma once
#include "Option.h"

class AmericanOption : public Option {
public:
    AmericanOption(double expiry);  
    virtual bool isAmericanOption() const override;  
};

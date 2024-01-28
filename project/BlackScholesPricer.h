#pragma once 
#include "VanillaOption.h"
#include "DigitalOption.h"

class BlackScholesPricer {
private:
  VanillaOption* _vanillaOption;
  DigitalOption* _digitalOption;
  double N(double x) const;

  double _assetPrice;
  double _interestRate;
  double _volatility;

public:
  BlackScholesPricer(Option* option, double assetPrice, double interestRate,
                     double volatility);

  double operator()() const;
  double delta() const;
};


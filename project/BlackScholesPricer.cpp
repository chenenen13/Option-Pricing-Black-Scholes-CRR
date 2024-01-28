#include "BlackScholesPricer.h"
#include <cmath>

BlackScholesPricer::BlackScholesPricer(Option* option, double assetPrice, double interestRate, double volatility)
    : _assetPrice(assetPrice),
      _interestRate(interestRate),
      _volatility(volatility)
{
    if (dynamic_cast<VanillaOption*>(option)) 
    {
        _vanillaOption = dynamic_cast<VanillaOption*>(option);
        // Le cast classique (static_cast ou reinterpret_cast) peut effectuer une conversion de type sans effectuer de vérification de type. 
        // Le dynamic_cast, en revanche, effectue une vérification de type lors de la conversion de pointeur. 
        // Si la conversion est possible, le dynamic_cast renvoie un pointeur valide du type demandé. Sinon, il renvoie nullptr.
        _digitalOption = nullptr;
    }
    else if (dynamic_cast<DigitalOption*>(option)) 
    {
        _vanillaOption = nullptr;
        _digitalOption = dynamic_cast<DigitalOption*>(option);
    }
}

double BlackScholesPricer::operator()() const 
{
    double T = _vanillaOption ? _vanillaOption->getExpiry() : _digitalOption->getExpiry();
    double K = _vanillaOption ? _vanillaOption->getStrike() : _digitalOption->getStrike();
    double r = _interestRate;
    double sigma = _volatility;

    double d1 = (log(_assetPrice / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double d3 = (log(_assetPrice / K) + (r - 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double callPrice = _assetPrice * N(d1) - K * exp(-r * T) * N(d2);
    double putPrice = K * exp(-r * T) * N(-d2) - _assetPrice * N(-d1);

    if (_vanillaOption && _vanillaOption->GetOptionType() == VanillaOption::OptionType::Call)
        return callPrice;
    else if (_vanillaOption && _vanillaOption->GetOptionType() == VanillaOption::OptionType::Put)
        return putPrice;
    else if (_digitalOption && _digitalOption->GetOptionType() == DigitalOption::OptionType::Call)
        return exp(-r * T) * N(d3);
    else if (_digitalOption && _digitalOption->GetOptionType() == DigitalOption::OptionType::Put)
        return exp(-r * T) * N(-d3);
    else
        return 0.0;
}

double BlackScholesPricer::delta() const {
    double T = _vanillaOption ? _vanillaOption->getExpiry() : _digitalOption->getExpiry();
    double K = _vanillaOption ? _vanillaOption->getStrike() : _digitalOption->getStrike();
    double r = _interestRate;
    double sigma = _volatility;

    double d1 = (log(_assetPrice / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    if (_vanillaOption && _vanillaOption->GetOptionType() ==VanillaOption::OptionType::Call)
        return N(d1);
    else if (_vanillaOption && _vanillaOption->GetOptionType() == VanillaOption::OptionType::Put)
        return N(d1) - 1.0;
    else if (_digitalOption && _digitalOption->GetOptionType() ==DigitalOption::OptionType::Call)
        return (N(d1));
    else if (_digitalOption && _digitalOption->GetOptionType() == DigitalOption::OptionType::Put)
        return (N(d1)-1.0);
    else
        return 0.0;
}

double BlackScholesPricer::N(double x) const {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

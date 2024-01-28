#include "AsianCallOption.h"

AsianCallOption::AsianCallOption(std::vector<double> vect, double strike) : _strike(strike), AsianOption(vect) {}

double AsianCallOption::getStrike() const
{
	return _strike;
}

double AsianCallOption::payoff(double meanprice) const {
	return (meanprice >= getStrike()) ? (meanprice - getStrike()) : 0.0;
}


#include "AsianPutOption.h"

AsianPutOption::AsianPutOption(std::vector<double> vect, double strike) : _strike(strike), AsianOption(vect) {}

double AsianPutOption::getStrike() const
{
	return _strike;
}

double AsianPutOption::payoff(double meanprice) const {
	return (meanprice <= getStrike()) ? (getStrike()- meanprice) : 0.0;
}


#pragma once
#include "AsianOption.h"

class AsianCallOption : public AsianOption {
public:
	AsianCallOption(std::vector<double>, double);
	double payoff(double meanprice)const override;
	double getStrike() const;

private :
	double _strike;


};
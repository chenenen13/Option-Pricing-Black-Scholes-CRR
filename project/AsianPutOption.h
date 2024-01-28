#pragma once
#include "AsianOption.h"

class AsianPutOption : public AsianOption {
private:
	double _strike;

public:
	AsianPutOption(std::vector<double>, double);
	double payoff(double meanprice)const override;
	double getStrike() const;
	
};
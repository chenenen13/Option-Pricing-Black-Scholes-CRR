#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option {
public:
	AsianOption(std::vector<double>);
	std::vector<double> getTimeSteps()const;
	double payoffPath(std::vector<double>)const override;
	bool isAsianOption()const override;
private : 
	std::vector<double> time;



};
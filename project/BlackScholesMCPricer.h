#pragma once
#include "Option.h"
#include "AsianOption.h"
#include "AsianCallOption.h"
#include"AsianPutOption.h"
#include "VanillaOption.h"
#include "MT.h"
#include "DigitalOption.h"

class BlackScholesMCPricer {
private:
	Option* option;
	double initialprice;
	double interest;
	double volatility;
	double NbPaths = 0;
	double crttestimation;
	double sum=0;
	double sumsqr=0;

	AsianOption* asia;
	DigitalOption* digital;
	VanillaOption* vanille;
public:
	BlackScholesMCPricer(Option* , double initial_price, double interest_rate, double volatility);
	double getNbPaths();
	void generate(int nb_paths);
	double operator()() const;
	std::vector<double> confidenceInterval();
};
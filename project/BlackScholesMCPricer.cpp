#include "BlackScholesMCPricer.h"
#include <iostream>
#include <numeric>

BlackScholesMCPricer::BlackScholesMCPricer(Option* _option, double initial_price, double interest_rate, double _volatility) : option(_option),initialprice(initial_price),interest(interest_rate),volatility(_volatility),crttestimation(initial_price){
	asia = nullptr;
	vanille = nullptr;
	digital = nullptr;
	
	if (dynamic_cast<AsianOption*>(option))
	{
		asia = dynamic_cast<AsianOption*>(option);

	}
	else if (dynamic_cast<VanillaOption*>(option))
	{
		vanille = dynamic_cast<VanillaOption*>(option);
		
	}else {
		digital = dynamic_cast<DigitalOption*>(option);
	}
}

double BlackScholesMCPricer::getNbPaths() {
	return NbPaths;
}

void BlackScholesMCPricer::generate(int nb) {
	if (dynamic_cast<AsianOption*>(asia)) {
		std::vector<double> time = asia->getTimeSteps();
		double est = 0;
		double sumest = 0;
		for (int it = 0; it < nb; it++) {
			std::vector<double> rt;
			double St = initialprice * exp((interest - (volatility * volatility) / 2) * time[0] + volatility * sqrt(time[0])*MT::rand_norm());
			rt.push_back(St);
			for (int i = 1; i < time.size(); i++) {
				St = St * exp((interest - (volatility * volatility) / 2) * (time[i] - time[i - 1]) + volatility * sqrt(time[i] - time[i - 1]) * MT::rand_norm());
				rt.push_back(St);
			}
			est = asia->payoffPath(rt)* exp(-interest * std::accumulate(time.begin(), time.end(), 0));
			sumest += est;
			sumsqr += (est * est);
			
		}
		sum += sumest;
		NbPaths += nb;
	}
	else if (dynamic_cast<VanillaOption*>(option)){
		
		double time = vanille->getExpiry();
		double est = 0;

		for (int it = 0; it < nb; it++) {
			double St = 0;
			St = initialprice * exp((interest - (volatility * volatility) / 2) * time + volatility * sqrt(time) * MT::rand_norm());
			est = vanille->payoff(St);
			est = exp(-interest * time) * est;
			sum = sum + est;
			sumsqr = sumsqr + (est * est);
		}
		NbPaths += nb;
		
	}
	else {
		
		double time = digital->getExpiry();
		double est=0;

		for (int it = 0; it < nb; it++) {
			double St = 0;
			St = initialprice * exp((interest - (volatility * volatility) / 2) * time + volatility * sqrt(time) * MT::rand_norm());
			est= digital->payoff(St);
			est = exp(-interest *time) * est;
			sum = sum + est;
			sumsqr = sumsqr + (est * est);
		}
		NbPaths += nb;
	}
	
}

double BlackScholesMCPricer::operator()() const{
	return sum/NbPaths;
}

std::vector <double > BlackScholesMCPricer::confidenceInterval() {
	double mean = sum / NbPaths;
	double var = (sumsqr / NbPaths) - (mean * mean);
	double phiquartile = 1.96;  //je fait l'estiamation que cela suis une loi normal car la partie aléatoire en suis une
	std::vector<double> intervall;
	intervall.push_back(mean - phiquartile * sqrt(var/NbPaths));
	intervall.push_back(mean + phiquartile * sqrt(var/NbPaths));
	
	return intervall;
}
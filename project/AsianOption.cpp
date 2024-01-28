#include "AsianOption.h"

AsianOption::AsianOption(std::vector<double> tim) : time(tim) , Option(0)   {}

std::vector<double> AsianOption::getTimeSteps()const {
	return time;
}

double AsianOption::payoffPath(std::vector<double> vect) const {
	double sum = 0;
	for (int i = 0; i < vect.size(); i++) {
		sum += vect[i];
	}
	sum= sum / vect.size();
	if (sum == 0) {
		
	}
	return payoff(sum);
}
bool AsianOption::isAsianOption() const {
	return true;
}

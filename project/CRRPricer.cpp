#include "CRRPricer.h"

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) {
	if (option->isAsianOption() == true) {
		throw std::invalid_argument("this is an Asian Option");
	}
	_option=option;
	_depth=depth;
	_asset_price=asset_price;
	_up=up;
	_down=down;
	_interest_rate=interest_rate;
}
	

BinaryTree<double> Tree;
BinaryTree<bool> exerciseTree;

void CRRPricer::tree_structure() const 
{
    Tree.setNode(0, 0, _asset_price);
    exerciseTree.setDepth(_depth);  
    for (int i = 1; i <= _depth; i++) {
        for (int j = 0; j <= i; j++) {
            double spotPrice = _asset_price * pow(1 + _up, j) * pow(1 + _down, i - j);
            Tree.setNode(i, j, spotPrice);

            if (_option->isAmericanOption()) {
                exerciseTree.setNode(i, j, false);
            }
        }
    }
    if (_option->isAmericanOption()) {
        for (int j = 0; j <= _depth; j++) {
            exerciseTree.setNode(_depth, j, true);
        }
    }
}

void CRRPricer::compute() const {
	Tree.setDepth(_depth);
    tree_structure();
    exerciseTree.setDepth(_depth); 

    for (int last_position = 0; last_position <= _depth; last_position++) {
        double value = _option->payoff(Tree.getNode(_depth, last_position));
        Tree.setNode(_depth, last_position, value);
        exerciseTree.setNode(_depth, last_position, true); 
    }

    for (int level = _depth - 1; level >= 0; level--) {
        for (int position = 0; position <= level; position++) {
            double q = (_interest_rate - _down) / (_up - _down);
            double first_value_numerator = (q * Tree.getNode(level + 1, position + 1));
            double second_value_numerator = ((1 - q) * Tree.getNode(level + 1, position));
            double numerator = first_value_numerator + second_value_numerator;
            double denominator = 1 + _interest_rate;
            double value = numerator / denominator;

            if (_option->isAmericanOption()) {
                double intrinsic_value = _option->payoff(Tree.getNode(level, position));
                if (intrinsic_value > value) {
                    value = intrinsic_value;  
                    exerciseTree.setNode(level, position, true);  
                } else {
                    exerciseTree.setNode(level, position, false);  
                }
            } else {
                exerciseTree.setNode(level, position, false);  
            }
            Tree.setNode(level, position, value);
        }
    }
}

double CRRPricer::get(int level, int position) const {
	{
		return (Tree.getNode(level, position));
	}
}
double CRRPricer::operator()(bool closed_form) const {
	double valeur = 0.0;
	double q = (_interest_rate - _down) / (_up - _down);
	if (closed_form == true) {
		Tree.setDepth(_depth);
		tree_structure();
		double sum = 0.0;
		for (int i = 0; i <= _depth; i++) {
			if (_option->payoff(Tree.getNode(_depth, i)) == 0) {
				sum += 0.0;
			}
			else {
				double numerator = tgamma(_depth + 1);
				double denominator = tgamma(i + 1) * tgamma(_depth - i + 1);
				double binomial_coefficient = numerator / denominator;
				double term = binomial_coefficient * pow(q, i) * pow(1 - q, _depth - i) * _option->payoff(Tree.getNode(_depth, i));
				sum += term;
			}
		}
		double discount_factor = 1 / pow(1 + _interest_rate, _depth);
		double valeur = discount_factor * sum;
		return valeur;
	}
	else {
		compute();
		valeur = Tree.getNode(0, 0);
	}
	return valeur;
}

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility) {
    double h = option->getExpiry() / depth;
    _up = exp((r + volatility*volatility / 2) * h + volatility * sqrt(h)) - 1;
    _down = exp((r + volatility*volatility / 2) * h - volatility * sqrt(h)) - 1;
    _interest_rate = exp(r * h) - 1;
    _option = option;
    _depth = depth;
    _asset_price = asset_price;
}

bool CRRPricer::getExercise(int level, int position) const {
    return exerciseTree.getNode(level, position);
}

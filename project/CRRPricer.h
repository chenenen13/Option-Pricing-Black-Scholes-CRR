#pragma once 
#include "BinaryTree.h"
#include <iostream>
#include <cmath>
#include "Option.h"
#include "DigitalOption.h"

class CRRPricer :public BinaryTree<double> 
{
private:
	Option* _option;
	int _depth;
	double _asset_price;
	double _up;
	double _down;
	double _interest_rate;

public:

	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	double operator()(bool base = false) const;
	void compute() const;
	void tree_structure() const;
	double get(int, int) const;
	bool getExercise(int level, int position) const;

	CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);
};
#pragma once
#include<vector>

class Option 
{
private:
    double _expiry;

public:
    enum OptionType { Call, Put };

    Option(double expiry);
    virtual ~Option(); // Ajouter le destructeur virtuel
    double getExpiry() const;
    virtual double payoff(double spotPrice) const = 0;
    virtual double payoffPath(std::vector<double>) const;
    virtual bool isAsianOption() const;
    virtual bool isAmericanOption() const;
};
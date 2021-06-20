#pragma once

#include <iostream>
#include <string>

class calculate
{
public:
	double current1p(double prasch, double Un, double cosfi);

	double current3p(double prasch, double sq3, double Un, double cosfi);

	double deltau(int typeCabel, double prasch, double L, double poperechS);
};


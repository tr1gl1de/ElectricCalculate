#include "calculate.h"


double calculate::current1p(double prasch, double Un, double cosfi)
{
	double result = 0.0;
	result = prasch / (Un * cosfi);
	return result;
}

double calculate::current3p(double prasch, double sq3, double Un, double cosfi)
{
	double result = 0.0;
	result = prasch / (sq3 * Un * cosfi);
	return result;
}

double calculate::deltau(int typeCabel, double prasch, double L, double poperechS)
{
	double kCabel = 0;

	if (typeCabel == 1) // если входное значение 1 то тип кабеля алюминий
	{
		kCabel = 50.0;
	}
	else
	{
		kCabel = 83.0;
	}
	double result = 0.0;
	result = (prasch * L) / (kCabel * poperechS);
	return result;
}
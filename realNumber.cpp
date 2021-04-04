/******************************************************************************
*                                                                             *
*   Program : Operations on rational numbers                                  *
*                                                                             *
*   Date : 20 / 03 / 2021                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (488054)                                  *
*                                                                             *
*                                                                             *
******************************************************************************/

#include "realNumber.h"

realNumber::realNumber() : numerator{ 1 }, denominator{ 1 }
{
	greatest_common_divisor();
}

realNumber::realNumber(int num, int den) : numerator{ num }, denominator{ den }
{
	greatest_common_divisor();
}

realNumber::realNumber(int num) : numerator{ num }, denominator{ 1 }
{
	greatest_common_divisor();
}

realNumber::realNumber(string numberRepresantation)
{
	size_t tmp_pos = numberRepresantation.find('/');

	auto tmp_num = numberRepresantation.substr(0, tmp_pos);
	auto tmp_den = numberRepresantation.substr(tmp_pos+1, numberRepresantation.length());

	auto num = stoi(tmp_num);
	auto den = stoi(tmp_den);

	set_num(num);
	set_den(den);

	greatest_common_divisor();
}

void realNumber::set_num(int num)
{
	numerator = num;
	greatest_common_divisor(); //added after fix 27-03
}

void realNumber::set_den(int den)
{
	denominator = den;
	greatest_common_divisor(); //added after fix 27-03
}

int realNumber::get_num()
{
	return numerator;
}

int realNumber::get_den()
{
	return denominator;
}

string realNumber::number_to_str()
{
	return to_string(numerator) + "/" + to_string(denominator);
}

double realNumber::number_to_double()
{
	return numerator / denominator;
}

bool realNumber::is_positive()
{
	if ((numerator / denominator) >= 0)
		return true;
	else
		return false;
}

bool realNumber::is_negative()
{
	if ((numerator / denominator) <= 0)
		return true;
	else
		return false;
}

bool realNumber::is_inf()
{
	if (numerator == 0 && denominator == 0)
		return true;
	else
		return false;
}

bool realNumber::is_nan()
{
	if (numerator != 0 && denominator == 0)
		return true;
	else
		return false;
}

int realNumber::greatest_common_divisor()
{
	auto tmp_num = numerator;
	auto tmp_den = denominator;

	while (tmp_den != 0)
	{
		auto tmp_buff = tmp_den;
		tmp_den = tmp_num % tmp_den;
		tmp_num = tmp_buff;
	}

	if (numerator != 0 && denominator != 0)
	{
		numerator = numerator / tmp_num;
		denominator = denominator / tmp_num;
	}

	if (denominator < 0)
	{
		denominator = -(denominator);
		numerator = -(numerator);
	}

	return tmp_num;
}
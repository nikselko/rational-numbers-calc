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

#include "rationalCalculator.h"

rationalCalculator::rationalCalculator() : res_amount { 0 }
{
	
}

realNumber rationalCalculator::calculate(string expression)
{
	string exponent;
	auto first_num = expression.substr(0, expression.find(' '));

	size_t tmp_pos = first_num.find('/');
	auto tmp_num = first_num.substr(0, tmp_pos);
	auto tmp_den = first_num.substr(tmp_pos + 1, first_num.length());

	r_num_first.set_num(stoi(tmp_num));
	r_num_first.set_den(stoi(tmp_den));

	char chr_operator = expression[expression.find_last_of(' ') - 1];

	if (chr_operator == '^' )
		exponent = expression.substr(expression.find_last_of(' ') + 1, expression.length());
	else
	{
		auto second_num = expression.substr(expression.find_last_of(' ') + 1, expression.length());
			
		tmp_pos = second_num.find('/');
		tmp_num = second_num.substr(0, tmp_pos);
		tmp_den = second_num.substr(tmp_pos + 1, second_num.length());

		r_num_second.set_num(stoi(tmp_num));
		r_num_second.set_den(stoi(tmp_den));
	}

	switch (chr_operator)
	{
	case '+':
		add_fractions(r_num_first, r_num_second);
		break;

	case '-':
		subtract_fractions(r_num_first, r_num_second);
		break;

	case '*':
		multiply_fractions(r_num_first, r_num_second);
		break;

	case '/':
		divide_fractions(r_num_first, r_num_second);
		break;

	case '^':
		pow_fraction(r_num_first, stoi(exponent));
		break;
	}

	//num_res[res_amount].greatest_common_divisor(); removed after fix 27-03

	return num_res[res_amount];
}



void rationalCalculator::add_fractions(realNumber f_num_first, realNumber f_num_second)
{
	res_amount++;

	if (f_num_first.get_den() == 0 || f_num_second.get_den() == 0)
	{
		num_res[res_amount].set_den(0);

		if (f_num_first.get_num() == 0 || f_num_second.get_num() == 0)
			num_res[res_amount].set_num(0);
		else
			num_res[res_amount].set_num(1);
	}
	else
	{
		num_res[res_amount].set_num(f_num_first.get_num() * f_num_second.get_den() + f_num_second.get_num() * f_num_first.get_den());

		num_res[res_amount].set_den(f_num_first.get_den() * f_num_second.get_den());
	}
}
	

void rationalCalculator::subtract_fractions(realNumber f_num_first, realNumber f_num_second)
{
	res_amount++;

	if (f_num_first.get_den() == 0 || f_num_second.get_den() == 0)
	{
		num_res[res_amount].set_den(0);

		if (f_num_first.get_num() == 0 || f_num_second.get_num() == 0)
			num_res[res_amount].set_num(0);
		else
			num_res[res_amount].set_num(1);

	}
	else
	{
		num_res[res_amount].set_num(f_num_first.get_num() * f_num_second.get_den() - f_num_second.get_num() * f_num_first.get_den());

		num_res[res_amount].set_den(f_num_first.get_den() * f_num_second.get_den());
	}
}

void rationalCalculator::multiply_fractions(realNumber f_num_first, realNumber f_num_second)
{
	res_amount++;

	if (f_num_first.get_den() == 0 || f_num_second.get_den() == 0)
	{
		num_res[res_amount].set_den(0);

		if (f_num_first.get_num() == 0 || f_num_second.get_num() == 0)
			num_res[res_amount].set_num(0);
		else
			num_res[res_amount].set_num(1);
	}
	else
	{
		num_res[res_amount].set_num(f_num_first.get_num() * f_num_second.get_num());

		num_res[res_amount].set_den(f_num_first.get_den() * f_num_second.get_den());
	}
}

void rationalCalculator::divide_fractions(realNumber f_num_first, realNumber f_num_second)
{
	res_amount++;

	if (f_num_first.get_den() == 0 || f_num_second.get_den() == 0)
	{
		num_res[res_amount].set_den(0);

		if (f_num_first.get_num() == 0 || f_num_second.get_num() == 0)
			num_res[res_amount].set_num(0);
		else
			num_res[res_amount].set_num(1);
	}
	else
	{
		num_res[res_amount].set_num(f_num_first.get_num() * f_num_second.get_den());

		num_res[res_amount].set_den(f_num_first.get_den() * f_num_second.get_num());
	}
}

void rationalCalculator::pow_fraction(realNumber f_num_first, int exp)
{
	res_amount++;

	if (exp == 0)
	{
		num_res[res_amount].set_num(1);
		num_res[res_amount].set_den(1);
	}
	else
	{
		auto num = f_num_first.get_num();
		auto den = f_num_first.get_den();

		auto tmp_n = num;
		auto tmp_d = den;

		for (int i = 1; i < exp; i++)
		{
			num *= tmp_n;
			den *= tmp_d;
		}

		num_res[res_amount].set_num(num);
		num_res[res_amount].set_den(den);
	}
}


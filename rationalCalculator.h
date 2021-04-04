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

#pragma once

#define MAX_CALCULATIONS_AMOUNT 99

#include "realNumber.h"

class rationalCalculator
{
public:
	rationalCalculator();

	realNumber calculate(string expression);
	bool process(string file_name);

private:
	int res_amount;

	realNumber r_num_first;
	realNumber r_num_second;
	realNumber num_res[MAX_CALCULATIONS_AMOUNT];

	void add_fractions(realNumber f_num_first, realNumber f_num_second);

	void subtract_fractions(realNumber f_num_first, realNumber f_num_second);

	void multiply_fractions(realNumber f_num_first, realNumber f_num_second);

	void divide_fractions(realNumber f_num_first, realNumber f_num_second);

	void pow_fraction(realNumber f_num_first, int exp);
};


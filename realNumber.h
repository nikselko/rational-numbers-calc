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

#include "includes.h"

class realNumber
{
public:
	realNumber();

	realNumber(int num, int den);

	realNumber(int num);

	realNumber(string numberRepresantation);

	void set_num(int num);
	void set_den(int den);

	int get_num();
	int get_den();

	string number_to_str();

	double number_to_double();

	bool is_positive();
	bool is_negative();

	bool is_inf();
	bool is_nan();

private: 
	int numerator, denominator;
	
	int greatest_common_divisor(); //made private after fix 27-03
};


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

bool rationalCalculator::process(string file_name) //moved to another file after fix 27-03
{
	string expression{};

	if (ifstream input{ file_name })
	{
		if (ofstream output{ "results.txt" })
		{
			cout << endl;
			while (getline(input, expression))
			{
				calculate(expression);
				output << expression << " = " << num_res[res_amount].get_num() << '/' << num_res[res_amount].get_den();
				cout << expression << " = " << num_res[res_amount].get_num() << '/' << num_res[res_amount].get_den();

				if (num_res[res_amount].get_den() == 0)
				{
					if (num_res[res_amount].get_num() == 0)
					{
						output << " (NaN)";
						cout << " (NaN)";
					}
					else
					{
						output << " (+Inf)";
						cout << " (+Inf)";
					}
				}
				output << endl;
				cout << endl;
			}
		}
		return true;
	}
	else
	{
		if (file_name.find('/'))
		{
			expression = file_name;

			if (ofstream output{ "results.txt" })
			{
				cout << endl;
				calculate(expression);
				output << expression << " = " << num_res[res_amount].get_num() << '/' << num_res[res_amount].get_den();
				cout << expression << " = " << num_res[res_amount].get_num() << '/' << num_res[res_amount].get_den();

				if (num_res[res_amount].get_den() == 0)
				{
					if (num_res[res_amount].get_num() == 0)
					{
						output << " (NaN)";
						cout << " (NaN)";
					}
					else
					{
						output << " (+Inf)";
						cout << " (+Inf)";
					}
				}
				output << endl;
				cout << endl;

				return true;
			}
			else
				return false;
		}
		return false;
	}
}
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

int main()
{
    int menu_choise;
   
    rationalCalculator Calc;

    while (true)
    {
        system("cls");
        cout << "-Rational Calculator-" << endl;
        cout << "How would you like to enter expression?"
            << endl << "-User (1)"
            << endl << "-File (2)"
            << endl << "-Exit (0)"
            << endl << "-> ";
        cin >> menu_choise;
        cin.ignore();

        if (menu_choise >= 0 && menu_choise <= 2)
        {
            string tmp_user_input, tmp_file_name;

            switch (menu_choise)
            {
            case 1:
                system("cls");
                cout << endl << "Enter custom expression (a/b + c/d)\n-> ";
                getline(cin, tmp_user_input);

                if (Calc.process(tmp_user_input))
                    cout << endl << "Succes, results saved to results.txt!" << endl;
                else
                    cout << endl << "Something went wrong! (maybe file name)" << endl;

                system("pause");
                break;

            case 2:
                system("cls");
                cout << "Enter file name-> ";
                cin >> tmp_file_name;

                if (Calc.process(tmp_file_name))
                    cout << endl << "Succes, results saved to results.txt!" << endl;
                else
                    cout << endl << "Something went wrong! (maybe file name)" << endl;

                system("pause");
                break;

            case 0:
                return 1;
                system("cls");
                break;
            }
        }
        else
        {
            system("cls");
            cout << endl << "Something went wrong!, wrong menu input!" << endl;
            system("pause");
        }
    }
}

//write include statements
#include <iostream>
#include "decisions.h"

using std::cin;
using std::cout;

int main()
{
    int option;
    int grade;

    cout << "MAIN MENU" << std::endl;
    cout << "1-Letter grade using if" << std::endl;
    cout << "2-Letter grade using switch" << std::endl;
    cout << "3-Exit" << std::endl;

    cout << "Enter an option: ";
    cin >> option;

    switch (option)
    {
        case 1:
            cout << "Enter a grade between 0 and 100: ";
            cin >> grade;
            if (grade >= 0 && grade <= 100)
            {
                cout << "Letter grade using if: " << get_letter_grade_using_if(grade) << std::endl;
            }
            else
            {
                cout << "Invalid grade entered." << std::endl;
            }
            break;
        case 2:
            cout << "Enter a grade between 0 and 100: ";
            cin >> grade;
            if (grade >= 0 && grade <= 100)
            {
                cout << "Letter grade using switch: " << get_letter_grade_using_switch(grade) << std::endl;
            }
            else
            {
                cout << "Invalid grade entered." << std::endl;
            }
            break;
        case 3:
            cout << "Exiting program." << std::endl;
            break;
        default:
            cout << "Invalid option entered." << std::endl;
            break;
    }

    return 0;
}

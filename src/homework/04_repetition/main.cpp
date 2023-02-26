//write include statements

//write using statements


/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/

#include <iostream>
#include "dna.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int choice = 0;
    
    do
    {
        cout << "1-Factorial\n";
        cout << "2-Greatest Common Divisor\n";
        cout << "3-Exit\n";
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                cout << "Factorial of " << num << " is " << factorial(num) << endl;
                break;
            }
            case 2:
            {
                int num1, num2;
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Greatest common divisor of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
                break;
            }
            case 3:
            {
                char confirm;
                cout << "Are you sure you want to exit? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                {
                    cout << "Exiting program...\n";
                    return 0;
                }
                break;
            }
            default:
            {
                cout << "Invalid choice. Please choose again.\n";
                break;
            }
        }
    } while (choice != 3);
    
    return 0;
}

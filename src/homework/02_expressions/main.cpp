//write include statements


//write namespace using statement for cout


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	

	return 0;
}

#include <iostream>
#include "hwexpressions.h"

using namespace std;

int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;
    
    cout << "Enter meal amount: ";
    cin >> meal_amount;
    
    tax_amount = get_sales_tax_amount(meal_amount);
    
    cout << "Enter tip rate (in %): ";
    cin >> tip_rate;
    tip_rate /= 100;
    
    tip_amount = get_tip_amount(meal_amount, tip_rate);
    
    total = meal_amount + tip_amount + tax_amount;
    
    cout << "Meal Amount: " << meal_amount << endl;
    cout << "Sales Tax: " << tax_amount << endl;
    cout << "Tip Amount: " << tip_amount << endl;
    cout << "Total: " << total << endl;
    
    return 0;
}

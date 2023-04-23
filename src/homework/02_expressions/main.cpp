#include <iostream>
#include "hwexpressions.h"

int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    std::cout << "Enter meal amount: ";
    std::cin >> meal_amount;

    tax_amount = get_sales_tax_amount(meal_amount);

    std::cout << "Enter tip rate as a decimal: ";
    std::cin >> tip_rate;

    tip_amount = get_tip_amount(meal_amount, tip_rate);
    total = meal_amount + tax_amount + tip_amount;

    std::cout << "Meal Amount: " << meal_amount << std::endl;
    std::cout << "Sales Tax: " << tax_amount << std::endl;
    std::cout << "Tip Amount: " << tip_amount << std::endl;
    std::cout << "Total: " << total << std::endl;

    return 0;
}

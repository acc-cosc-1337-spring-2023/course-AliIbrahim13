#include <iostream>
#include "data_types.h"

int main()
{
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;

  int result = multiply_numbers(num);
  std::cout << "Result: " << result << std::endl;

  int num1 = 4;
  result = multiply_numbers(num1);
  std::cout << "Result: " << result << std::endl;

  return 0;
}

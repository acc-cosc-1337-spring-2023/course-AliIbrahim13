//write include statements


//write namespace using statement for cout

#include <iostream>

int main()
{
	std::cout << "Hello, World!" <<
	std::end;

	return 0;
}

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
#include <iostream>
int multiply_numbers(int x)
{
	return x*5;
}
int main()
{
	int num;
	std::cout <<"Enter a number:";
	std::cin >> num;

	int result = multiply_numbers(num);
	std::cout << "Result:" << result <<

	int num1 = 4;
	result = multiply_numbers(num1);
	std::cout << "Result:" << result <<
std::end;

	return 0;
}

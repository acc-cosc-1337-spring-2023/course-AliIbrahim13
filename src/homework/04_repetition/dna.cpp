//add include statements

//add function(s) code here
// Function definition for factorial
int factorial(int num)
{
    int result = 1;
    
    while (num > 0)
    {
        result *= num;
        num--;
    }
    
    return result;
}

// Function definition for greatest common divisor
int gcd(int num1, int num2)
{
    while (num1 != num2)
    {
        if (num1 > num2)
        {
            num1 -= num2;
        }
        else
        {
            num2 -= num1;
        }
    }

    return num1;
}

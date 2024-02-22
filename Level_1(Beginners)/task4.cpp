/*
Write a program that contains functions for basic arithmetic operations (add, subtract, multiply, divide). Each function should accept two parameters and return the result of the operation. Test these functions by invoking them from the main function. This task introduces the concept of functions, parameter passing, and return types.
*/

#include <iostream>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double devide(double a, double b);

int main()
{
	double a;
	double b;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
		
	double k = add(a, b);
	std::cout << "The result of adding a to b is: " << k << std::endl;
	k = subtract(a, b);
	std::cout << "The result of subtracting a to b is: " << k << std::endl;
	k = multiply(a, b);
	std::cout << "The result of multiplication a with b is: " << k << std::endl;
	k = devide(a, b);
	std::cout << "The result of devision a to b is: " << k << std::endl;
		return 0;
}

double add(double a, double b)
{
		return a + b;
}

double subtract(double a, double b)
{
		return a - b;
}

double multiply(double a, double b)
{
		return a * b;
}

double devide(double a, double b)
{
		return  a / b;
}

/*
Create a base class Shape with a method to calculate the area and derive two classes from it: Circle and Rectangle. Implement the area calculation method for each derived class. This task introduces the concept of inheritance and polymorphism.
*/
#include <iostream>

class Shape 
{
	public:
		double CalculateArea()
		{
				return 0;
		}
};

class Circle : public Shape
{
	private:
			double radius;
	public:
			Circle(double rad) : radius(rad) {}

			void set_radius(double value)
			{
					radius = value;
			}
			double get_radius()
			{
					return radius;
			}
			double CalculateArea()
			{
					return 3.14 * radius * radius;
			}
};

class Rectangle : public Shape
{
	private:
			double a;
			double b;
	public:
			Rectangle(double aa, double bb) : a(aa), b(bb) {}
			void set_a(double val)
			{
					a = val;
			}
			void set_b(double val)
			{
					b = val;
			}
			double get_a()
			{
				return a;
			}
			double get_b() 
			{
				return b;
			}
			double CalculateArea() 
			{
					return a * b;
			}



};

int main()
{
	int a;
	int b;
	int c;
	std::cout << "Input sides of the rectangle." << std::endl;
	std::cout << "A is: ";
	std::cin >> a;
	std::cout << "B is: ";
	std::cin >> b;
	Rectangle ob(a,b);
	std::cout << "Area of the rectangle is: "<< ob.CalculateArea() << std::endl;

	std::cout << "Input radius of the circle." << std::endl;
	std::cout << "Radius is: ";
	std::cin >> c;
	Circle cir(c);
	std::cout << "Area of the circle is: "<< cir.CalculateArea() << std::endl;

	

	return 0;
}

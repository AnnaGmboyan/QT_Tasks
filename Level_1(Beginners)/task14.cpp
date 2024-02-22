/*
Modify the Shape class to make the area calculation method virtual. Create a function that takes a pointer to a Shape and prints its area, demonstrating polymorphic behavior. This task explores dynamic polymorphism and the use of virtual functions.
*/
#include <iostream>

class Shape 
{
	public:
	virtual double CalculateArea()
		{
				return 0;
		}
};

class Circle : public Shape
{
	private:
			double radius;
	public:
			Circle() : radius(0) { } 
			Circle(double rad) : radius(rad) {}

			void set_radius(double value)
			{
					radius = value;
			}
			double get_radius()
			{
					return radius;
			}
			double CalculateArea () override
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
			Rectangle() : a(0), b(0) {}
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
			double CalculateArea () override
			{
					return a * b;
			}
};

void Calculate_area(Shape* ptr)
{
	std::cout << ptr -> CalculateArea() << std::endl;
}

int main()
{
	double val;
	Rectangle ob;
	std::cout << "Input sides of the rectangle." << std::endl;
	
	std::cout << "A is: ";
	std::cin >> val;
	ob.set_a(val);
	
	std::cout << "B is: ";
	std::cin >> val;
	ob.set_b(val);

	std::cout << "Area of the rectangle is: ";
	Calculate_area(&ob);

	Circle cir;
	std::cout << "Input radius of the circle." << std::endl;
	std::cout << "Radius is: ";
	std::cin >> val;
	cir.set_radius(val);
	
	std::cout << "Area of the circle is: ";
	Calculate_area(&cir);
	
	std::cout << "A side of the rectangle is: " << ob.get_a() << std::endl;
	std::cout << "B side of the rectangle is: " << ob.get_b() << std::endl;
	std::cout << "Radius of the circle is: " << cir.get_radius() << std::endl;
	

	return 0;
}

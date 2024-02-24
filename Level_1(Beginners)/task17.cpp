#include <iostream>
#include <stdexcept>

class Shape
{
	public:
		double CalculateArea()
		{
			throw std::logic_error("Logic error, cannot calculate area as Shape doesn't have dimensions.");
		}
};
class Rectangle : public Shape
{
		private:
			double a;
			double b;
		public:
			Rectangle(double sidea, double sideb) : a(sidea), b(sideb) 
			{
				if(a <= 0 || b <= 0)
				{       
					throw std::invalid_argument("Sides of the rectangle must be positive.");
				}
			}
			double CalculateArea() 
			{
					return a * b;
			}			
};
class Circle : public Shape
{
		private:
			double radius;
		public:
			Circle(double rad) : radius(rad) 
			{
				if(radius <= 0)
				{
						throw std::invalid_argument("Radiusof circle must be positive.");
				}
			}
			double	CalculateArea()
			{
					return 3.14 * radius * radius;
			}
};

int main()
{
	double a;
	double b;
	double r;
	std::cout << "Enter sides of the rectangle: " << std::endl;
	std::cout << "Side a: ";
	std::cin >> a;
	std::cout << "Side b: ";
	std::cin >> b;

	try {
        Rectangle rec(a, b);
        std::cout << "Area of the rectangle is: " << rec.CalculateArea() << std::endl;
    } catch (const std::invalid_argument& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
    } catch (const std::logic_error& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
    }
	
	std::cout << "Enter the radius of circle: ";
	std::cin >> r;
	try {
			Circle cir(r);
			std::cout << "Area of the circle is: " << cir.CalculateArea() << std::endl;
	} catch (std::invalid_argument& err) {
		std::cout << "Error caught: " << err.what() << std::endl;
	} 

	try {
		Shape* obj = new Rectangle(a,b);
		std::cout << obj -> CalculateArea();
    } catch (const std::invalid_argument& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
	} catch (std::logic_error& err) {
		std::cout <<"Error caught: " << err.what() << std::endl;		
	}	



}

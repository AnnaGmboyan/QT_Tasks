#include <iostream>
#include <stdexcept>
template <typename T>
class Shape
{
	public:
		virtual	T CalculateArea()
		{
			throw std::logic_error("Logic error, cannot calculate area as Shape doesn't have dimensions.");
		}
};
template <typename T>
class Rectangle : public Shape<T>
{
		private:
			T a;
			T b;
		public:
			Rectangle(T sidea, T sideb) : a(sidea), b(sideb)
			{
				if(a <= 0 || b <= 0)
				{
					throw std::invalid_argument("Sides of the rectangle must be positive.");
				}
			}
			T CalculateArea () override
			{
					return a * b;
			}
};

template <typename T>
class Circle : public Shape<T>
{
		private:
			T radius;
		public:
			Circle(T rad) : radius(rad)
			{
				if(radius <= 0)
				{
						throw std::invalid_argument("Radiusof circle must be positive.");
				}
			}
			T	CalculateArea() override
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
        Rectangle<double> rec(a, b);
        std::cout << "Area of the rectangle is: " << rec.CalculateArea() << std::endl;
    } catch (const std::invalid_argument& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
    } catch (const std::logic_error& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
    }

	std::cout << "Enter the radius of circle: ";
	std::cin >> r;
	try {
			Circle<double> cir(r);
			std::cout << "Area of the circle is: " << cir.CalculateArea() << std::endl;
	} catch (std::invalid_argument& err) {
		std::cout << "Error caught: " << err.what() << std::endl;
	}

	try {
		Shape<double>* obj = new Rectangle<double> (a,b);
		std::cout << "Rectangle object by Shape pointer." << std::endl;
		std::cout <<"The area of rectangle is: " << obj -> CalculateArea() << std::endl;
    } catch (const std::invalid_argument& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
	} catch (std::logic_error& err) {
		std::cout <<"Error caught: " << err.what() << std::endl;
	}

	try {
		Shape<double>* obj = new Circle<double> (r);
		std::cout << "Circle object by Shape pointer." << std::endl;
		std::cout <<"The area of circle is: " << obj -> CalculateArea() << std::endl;
    } catch (const std::invalid_argument& err) {
        std::cout << "Error caught: " << err.what() << std::endl;
	} catch (std::logic_error& err) {
		std::cout <<"Error caught: " << err.what() << std::endl;
	}

return 0;

}

#include<iostream>

int main()
{
	double a1, b1, c1, a2, b2, c2;
	std::cout << "a1 = "; std::cin >> a1;
	std::cout << "b1 = "; std::cin >> b1;
	std::cout << "c1 = "; std::cin >> c1;
	std::cout << "\n";
	std::cout << "a2 = "; std::cin >> a2;
	std::cout << "b2 = "; std::cin >> b2;
	std::cout << "c2 = "; std::cin >> c2;

	double A, B, C;
	const double epsilon = 0.00001;

	if (a2 != 0 && b2 != 0 && c2 != 0)
	{
		A = a1 / a2;
		B = b1 / b2;
		C = c1 / c2;

		if (std::abs(A - B) < epsilon && std::abs(B - C) < epsilon)
		{
			std::cout << "\nmultiple\n";
			return 0;
		}
        
		if (std::abs(A - B) < epsilon && !(std::abs(B - C) < epsilon))
		{
			std::cout << "\nno result\n";
			return 0;
		}

		double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
		double y = (c1 * a2 - a1 * c2) / (a1 * b2 - a2 * b1);

		std::cout << "\n(" << x << ", " << y << ")\n";
	}
	else
	{
		if (a2 == 0 && (a1 == 0 || b2 == 0))
		{
			std::cout << "\nno result\n";
			return 0;
		}

		if (b2 == 0 && (a2 == 0 || b1 == 0))
		{
			std::cout << "\nno result\n";
			return 0;
		}

		double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
		double y = (c1 * a2 - a1 * c2) / (a1 * b2 - a2 * b1);

		std::cout << "\n(" << x << ", " << y << ")\n";
	}

    return 0;
}
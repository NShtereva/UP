#include <iostream>
#include <cmath>

int main()
{
	const double PI = 3.1415926535;
	double a, b, c, d, x, y = 0;
	std::cout << "a = "; std::cin >> a;
	std::cout << "b = "; std::cin >> b;
	std::cout << "c = "; std::cin >> c;
	std::cout << "d = "; std::cin >> d;

	if (a == 0)
	{
		if (b == 0)
		{
			std::cout << "\nIncorrect input!\n";
			return 0;
		}

		x = (2 * (-c) / (b * tan(d * PI / 180)));
	}
	else
	{
		if (b == 0)
		{
			x = -c / a;
		}
		else
		{
			double p = -c / (a + b * tan(d * PI / 180)), q = (-c * tan(d * PI / 180)) / (a + b * tan(d * PI / 180));
			x = p * q / (2 * p - q);
		}
	}

	std::cout << "\n(" << x << ", " << y << ")\n";
    return 0;
}
#include <iostream>

int main()
{
	unsigned int num, divisor;
	std::cin >> num >> divisor;

	if (num & 1)
	{
		std::cout << "\nfalse\n";
        return 0;
	}

	if (num & (divisor - 1))
		std::cout << "\nfalse\n";
	else
		std::cout << "\ntrue\n";
	
    return 0;
}
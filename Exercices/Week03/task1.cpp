#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c != 0)
            {
                std::cout << "\nThere are no real roots!\n";
            }
            else
            {
                std::cout << "\nEach x is a solution!\n";
            }
        }
        else
        {
            std::cout << "\none root: " << double(-c / b) << std::endl;
        }

    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D > 0)
        {
            std::cout << "\ntwo roots: " << double((-b - sqrt(D)) / 2 * a) << ", " << double((-b + sqrt(D)) / 2 * a) << std::endl;
        }
        else if (D == 0)
        {
            std::cout << "\none double root: " << double(-b / 2 * a) << std::endl;
        }
        else
        {
            std::cout << "\nThere are no real roots!\n";
        }

    }

    return 0;
}

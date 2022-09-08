#include<iostream>

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cout << "x1 = "; std::cin >> x1;
    std::cout << "y1 = "; std::cin >> y1;
    std::cout << "x2 = "; std::cin >> x2;
    std::cout << "y2 = "; std::cin >> y2;
    std::cout << "x3 = "; std::cin >> x3;
    std::cout << "y3 = "; std::cin >> y3;

    if ((x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1) == 0)
    {
        std::cout << "\nThe three points lie on one line!\n";
    }
    else
    {
        std::cout << "\nThe three points do not lie on one line!\n";
    }

    return 0;
}

/*
    |x1 y1 1|
    |x2 y2 1| = 0
    |x3 y3 1|
*/

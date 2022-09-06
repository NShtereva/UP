#include <iostream>

void swapDouble(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a, b;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    swapDouble(a, b);

    std::cout << "\nNew a = " << a << "\n";
    std::cout << "New b = " << b << "\n";
    return 0;
}

#include <iostream>

/*
int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        return gcd(a - b, b);
    }
    return gcd(a, b - a);
}
*/

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == b)
        {
            return a;
        }
        else if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
}

int main()
{
    int a, b;
    do
    {
        std::cout << "a = ";
        std::cin >> a;
    } while (a < 1);

    do
    {
        std::cout << "b = ";
        std::cin >> b;
    } while (b < 1);

    std::cout << "\n" << gcd(a, b) << "\n";
    return 0;
}

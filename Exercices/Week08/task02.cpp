#include <iostream>

/*
int gcd (int a, int b)
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

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
*/

int lcm(int a, int b)
{
    for (int i = 2; i <= a * b; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            return i;
        }
    }

    return 1;
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

    std::cout << "\n" << lcm(a, b) << "\n";
    return 0;
}

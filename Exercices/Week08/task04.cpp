#include <iostream>
#include <cmath>

int fast_pow(int a, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            result = result * a;
        }
        a = a * a;
        n = n / 2;
    }
        
    return result;
}

int main()
{
    int a, n;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "n = ";
    std::cin >> n;

    std::cout << "\n" << fast_pow(a, n) << "\n";
    return 0;
}

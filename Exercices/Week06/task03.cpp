#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    int a = 1, b = 0, c;
    
    if (n == 0)
    {
        c = 0;
    }
    else if (n == 1)
    {
        c = 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
    }

    std::cout << "fib(" << n << ") = " << c << std::endl;
    return 0;
}
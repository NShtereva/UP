#include <iostream>

int main()
{
    int n, fact = 1;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    if (n != 0 && n != 1)
    {
        for (int i = 2; i <= n; i++)
        {
            fact = fact * i;
        }
    }

    std::cout << n << "! = " << fact << std::endl;
    return 0;
}

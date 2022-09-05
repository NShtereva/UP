#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 1 || (n % 2 == 0));

    std::cout << std::endl;

    int k = (2 * n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int temp = 0; temp < k; temp++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n\n";
        k--;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < (2 * n - 1) / 2; j++)
        {
            std::cout << " ";
        }
        std::cout << "*\n\n";
    }
    return 0;
}

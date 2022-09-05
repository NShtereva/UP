#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            std::cout << i << " * " << j << " = " << i * j << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

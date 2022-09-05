#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 1);

    std::cout << std::endl;

    int temp = 1;
    for (int i = (n - 1); i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = temp; j <= (n * n - n * i); j++)
            {
                std::cout << j << " ";
            }
        }
        else
        {
            for (int j = (n * n - n * i); j >= temp; j--)
            {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
        temp = temp + n;
    }
    
    return 0;
}

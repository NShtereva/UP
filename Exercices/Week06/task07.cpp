#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    int minDigit = n % 10;

    while (n != 0)
    {
        int temp = n % 10;

        if (temp < minDigit)
            minDigit = temp;
        
        n = n / 10;
    }

    std::cout << "minDigit = " << minDigit << std::endl;
    return 0;
}

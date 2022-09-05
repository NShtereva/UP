#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 10);

    while (n != 0)
    {
        int currDigit = n % 10;
        int preDigit = (n / 10) % 10;

        if (currDigit == 0 && preDigit == 0)
        {
            std::cout << "true" << std::endl;
            return 0;
        }

        n = n / 10;
    }

    std::cout << "false" << std::endl;
    return 0;
}

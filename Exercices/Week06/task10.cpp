#include <iostream>

int main()
{
    double n, sum = 0, num;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    std::cout << "\nEnter numbers:\n";
    while (sum <= n)
    {
        std::cin >> num;
        sum = sum + num;
    }

    std::cout << "\nsum = " << sum << std::endl;
    return 0;
}

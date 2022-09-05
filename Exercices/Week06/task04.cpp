#include <iostream>

int main()
{
    int x, sum = 0;
    do
    {
        std::cout << "x = ";
        std::cin >> x;
    } while (x < 0);

    while (x != 0)
    {
        int temp = x % 10;
        x = x / 10;
        sum = sum + temp;
    }

    std::cout << "sum = " << sum << std::endl;
    return 0;
}

#include <iostream>

int main()
{
    int n, newN = 0;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    int reverseN = 0;
    while (n != 0)
    {
        int temp = n % 10;
        n = n / 10;
        reverseN = reverseN * 10 + temp;
    }

    while (reverseN != 0)
    {
        int temp = reverseN % 10;
        if (temp % 2 == 0)
        {
            newN = newN * 10 + temp;
        }
        reverseN = reverseN / 10;
    }

    std::cout << "New number = " << newN << std::endl;
    return 0;
}

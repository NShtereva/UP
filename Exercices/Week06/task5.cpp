#include <iostream>

int main()
{
    int n, reverseN = 0;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);

    while (n != 0)
    {
        int temp = n % 10;
        n = n / 10;
        reverseN = reverseN * 10 + temp;
    }

    std::cout << "Reverse number = " << reverseN << std::endl;
    return 0;
}

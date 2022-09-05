#include <iostream>

int main()
{
    int n;
    bool flag = true;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 10);

    while (n != 0)
    {
        int currDigit = n % 10;
        int preDigit = (n / 10) % 10;
        
        if (currDigit < preDigit)
            flag = false;

        n = n / 10;
    }

    std::cout << std::boolalpha << flag << std::endl;
    return 0;
}

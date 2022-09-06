#include <iostream>

bool isPrime(const int& num)
{
    if(num < 2)
        return false;

    if(num % 2 == 0 && num != 2)
        return false;

    for(int i = 3; i < num; i += 2)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int num;
    do
    {
        std::cout << "Enter number: ";
        std::cin >> num;
    } while (num < 0);

    std::cout << std::boolalpha << isPrime(num) << std::endl;
    return 0;
}

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

int numberOfDivisors(const int& num)
{
    int counter = 0;

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            counter++;
    }

    return counter;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    if(a > b) 
    {
        std::cout << "\nInvalid input!" << std::endl;
        return 1;
    }

    int counter = 0;
    for(int i = a; i <= b; i++)
    {
        if(isPrime(numberOfDivisors(i)))
            counter++;
    }

    std::cout << std::endl;
    std::cout << counter << std::endl;
    return 0;
}

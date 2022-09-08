#include <iostream>

int sum(int n)
{
    if(n < 10) 
    {
        return n;
    }
    return (n % 10) + sum(n / 10); 
}

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n <= 0);
    
    std::cout << "\nsum = " << sum(n) << std::endl;
    return 0;
}

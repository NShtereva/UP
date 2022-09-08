#include <iostream>

int reverseHelper(int n, int result)
{
    if (n <= 0)
    {
        return result;
    }
    return reverseHelper(n / 10, result * 10 + n % 10); 
}

int reverse(int n)
{
    return reverseHelper(n, 0);
}

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);
    
    std::cout << "\nreverse n: " << reverse(n) << std::endl;
    return 0;
}

#include <iostream>

int fact(int n)
{
    if(n < 2) 
    {
        return 1;
    }
    return n * fact(n - 1); 
}

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 0);
    
    std::cout << "\nn! = " << fact(n) << std::endl;
    return 0;
}

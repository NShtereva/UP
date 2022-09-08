#include <iostream>

int fib(int n)
{
    if(n == 1 || n == 2) 
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2); 
}

int fibIterHelper(int a, int b, int currN, int n)
{
    if(currN == n) 
    {
        return b;
    }
    return fibIterHelper(b, a + b, currN + 1, n);
}

int fibIter(int n)
{
    return fibIterHelper(0, 1, 1, n);
}

int main()
{
    int n;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n <= 0);
    
    std::cout << "\nfib(n) = " << fib(n) << std::endl;
    std::cout << "fib(n) = " << fibIter(n) << std::endl;
    return 0;
}

#include <iostream>

int main()
{
    const unsigned MAX_SIZE = 50;
    int N, fib[MAX_SIZE];
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N < 1 || N > MAX_SIZE);

    int a = 1, b = 0;
    fib[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        fib[i] = a + b;
        a = b;
        b = fib[i];
    }

    std::cout << std::endl;
    
    for (int i = 1; i <= N; i++)
    {
        std::cout << "fib(" << i << ") = " << fib[i] << std::endl;
    }
    return 0;
}

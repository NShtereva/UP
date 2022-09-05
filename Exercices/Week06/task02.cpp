#include <iostream>

int main()
{
    int N, result = 1;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N < 1);

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            result = result * i;
        }
    }

    std::cout << "result = " << result << std::endl;
    return 0;
}

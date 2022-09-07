#include <iostream>

int main()
{
    const size_t MAX_SIZE = 20;
    int n, arr[MAX_SIZE][MAX_SIZE];

    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n <= 0 || n > MAX_SIZE);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            arr[i][j] += std::max(arr[i - 1][j], arr[i - 1][j + 1]);
        }
    }

    std::cout << "\nsum = " << arr[n - 1][0];
    return 0;
}

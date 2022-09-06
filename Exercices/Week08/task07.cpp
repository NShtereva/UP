#include <iostream>

int main()
{
    const unsigned MAX_SIZE = 50;
    int n, arr[MAX_SIZE];
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    std::cout << "\nEnter an array:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    std::cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}

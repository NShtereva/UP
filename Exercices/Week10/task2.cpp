#include <iostream>

const size_t MAX_SIZE = 20;

void printInASpiral(int arr[], const size_t N)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    int p = 0, q = N - 1, index = 0;
    while(index < N * N)
    {
        for(int i = p; i <= q; i++)
        {
            matrix[i][p] = arr[index];
            index++;
        }

        for(int i = p + 1; i <= q; i++)
        {
            matrix[q][i] = arr[index];
            index++;
        }

        for(int i = q - 1; i >= p; i--)
        {
            matrix[i][q] = arr[index];
            index++;
        }

        for(int i = q - 1; i >= p + 1; i--)
        {
            matrix[p][i] = arr[index];
            index++;
        }
        p++; q--;
    }

    std::cout << std::endl;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    size_t N;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0 || N > MAX_SIZE);

    int arr[MAX_SIZE * MAX_SIZE];

    for(int i = 0; i < N * N; i++)
    {
        arr[i] = i + 1;
    }

    printInASpiral(arr, N);
    return 0;
}

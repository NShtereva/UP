#include <iostream>

const size_t MAX_SIZE = 20;

int rearSize()
{
    int size;

    do
    {
        std::cin >> size;
    } while (size <= 0 || size > MAX_SIZE);

    return size;
}

void readMatrix(int matrix[][MAX_SIZE], const size_t n, const size_t m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], const size_t n, const size_t m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE] = {0};

    int n, p, m;

    n = rearSize();
    p = rearSize();
    m = rearSize();

    std::cout << "\nA:\n";
    readMatrix(A, n, p);

    std::cout << "\nB:\n";
    readMatrix(B, p, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    std::cout << "\nC:\n";
    printMatrix(C, n, m);
    return 0;
}
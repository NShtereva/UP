#include <iostream>

int** generate(int** matrix, const int& N, const int& M, int& newN, int* numberOfElemiInCols, const int& K)
{
    int** newMatrix = new(std::nothrow) int*[N];
    if (!newMatrix)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < N; i++)
    {
        newMatrix[i] = new(std::nothrow) int[M];
        if (!newMatrix[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return nullptr;
        }
    }

    int p = 0;
    for (int i = 0; i < N; i++)
    {
        int c = 0;
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] % K == 0)
            {
                newMatrix[newN][c] = matrix[i][j];
                c++;
            }
        }
        newN++;
        numberOfElemiInCols[p] = c;
        p++;
    }

    return newMatrix;
}

int main()
{
    int N, M;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0);

    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M <= 0);

    int** matrix = new(std::nothrow) int*[N];
    if (!matrix)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        matrix[i] = new(std::nothrow) int[M];
        if (!matrix[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int K;
    do
    {
        std::cout << "\nK = ";
        std::cin >> K;
    } while (K <= 0);

    int* numberOfElemInCols = new(std::nothrow) int[N];
    if (!numberOfElemInCols)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        for (int i = 0; i < N; i++)
        {
            delete[] matrix[i];
        } delete[] matrix;
        matrix = nullptr;

        return 1;
    }

    int newN = 0;
    int** newMatrix = generate(matrix, N, M, newN, numberOfElemInCols, K);
    if (!newMatrix)
    {
        delete[] numberOfElemInCols;
        numberOfElemInCols = nullptr;

        for (int i = 0; i < N; i++)
        {
            delete[] matrix[i];
        } delete[] matrix;
        matrix = nullptr;

        return 1;
    }

    std::cout << std::endl;

    int p = 0;
    for (int i = 0; i < newN; i++)
    {
        for (int j = 0; j < numberOfElemInCols[p]; j++)
        {
            std::cout << newMatrix[i][j] << " ";
        }

        if (numberOfElemInCols[p] != 0)
        {
            std::cout << std::endl;
        }
        p++;
    }

    delete[] numberOfElemInCols;
    numberOfElemInCols = nullptr;

    for (int i = 0; i < N; i++)
    {
        delete[] newMatrix[i];
    } delete[] newMatrix;
    newMatrix = nullptr;

    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    } delete[] matrix;
    matrix = nullptr;
    return 0;
}

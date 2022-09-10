#include <iostream>

int readNumber()
{
    int number;
    
    do 
    {
        std::cin >> number;

        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();

            std::cin >> number;
        }
    } while (number <= 0);

    return number;
}

void readMatrix(int** matrix, const int& N, const int& M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = readNumber();
        }
    }
}

int numberOfDigitsInBinaryNotation(int number)
{
    int counter = 0;
    while (number != 0)
    {
        number = number / 2;
        counter++;
    }
    return counter;
}

int numberOfOnes(const int& number)
{
    int counter = 0;

    int n = numberOfDigitsInBinaryNotation(number), i = 0;

    while (i < n)
    {
        int temp = number & (1 << i);
        counter = (temp != 0) ? counter + 1 : counter;
        i++;
    }

    return counter;
}

void printMatrix(int** matrix, const int& N, const int& M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void copyRow(int* arr1, const int* arr2, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr2[i];
    }
}

void copyColumn(int** matrix, const int& N, const int& columnIndex)
{
    for (int i = 0; i < N; i++)
    {
        matrix[i][columnIndex] = matrix[i][columnIndex + 1];
    }
}

void deleteMatrix(int** matrix, const int& N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }  delete[] matrix;
    matrix = nullptr;
}

int main()
{
    // 1)
    int N, M;

    std::cout << "Enter N:" << std::endl;
    N = readNumber();

    std::cout << "Enter M:" << std::endl;
    M = readNumber();

    int** matrix = new(std::nothrow) int*[N];
    if (!matrix)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        matrix[i] = new(std::nothrow) int[M];
        if (!matrix[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    std::cout << "\nEnter matrix:" << std::endl;
    readMatrix(matrix, N, M);

    // 2)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp = numberOfOnes(matrix[i][j]);

            if (temp % 2 != 0)
                matrix[i][j] = 0;
        }
    }

    std::cout << std::endl;
    printMatrix(matrix, N, M);

    // 3)
    int N1 = N;
    bool toRemove = true;

    for (int i = 0; i < N1; i++)
    {
        toRemove = true;

        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] != 0)
                toRemove = false;
        }

        if(toRemove && i != N1 - 1)
        {
            for(int p = i; p < N1 - 1; p++)
            {
                copyRow(matrix[p], matrix[p + 1], M);
            }

            i--; N1--;
        }
        else if(toRemove && i == N1 - 1)
        {
            N1--;
        }
    }

    for (int i = 0; i < M; i++)
    {
        toRemove = true;

        for (int j = 0; j < N1; j++)
        {
            if (matrix[j][i] != 0)
                toRemove = false;
        }

        if(toRemove && i != M - 1)
        {
            for(int p = i; p < M - 1; p++)
            {
                copyColumn(matrix, N1, p);
            }

            i--; M--;
        }
        else if(toRemove && i == M - 1)
        {
            M--;
        }
    }

    // 4)
    std::cout << std::endl;
    printMatrix(matrix, N1, M);

    deleteMatrix(matrix, N);
    return 0;
}

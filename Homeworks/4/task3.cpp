#include <iostream>

int readNumber(int min)
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
    } while (number <= min);

    return number;
}

void readArr(int** arr, const int& N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = readNumber(0);
        }
    }
}

void initializeMatchIndices(int** matchIndices, const int& N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            matchIndices[i][j] = -1;
        }
    }
}

void getMatchIndices(int** arr, int** matchIndices, const int& N)
{
    for (int i = 0; i < N; i++)
    {
        int tempPos = 0;

        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                if ((arr[i][0] == arr[j][0] || arr[i][0] == arr[j][1]) || (arr[i][1] == arr[j][0] || arr[i][1] == arr[j][1]))
                {
                    matchIndices[i][tempPos] = j;
                    tempPos++;
                }
            }
        }
    }
}

void printMatchIndices(int** matchIndices, const int& N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << i << " -> ";
        for (int j = 0; j < N - 1; j++)
        {
            if (matchIndices[i][j] != -1)
            {
                std::cout << matchIndices[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int* getResultIndices(int** matchIndices, const int& N, int& counter)
{
    int* tempResult = new(std::nothrow) int[N];
    if(!tempResult)
    {
        return nullptr;
    }

    int* result = new(std::nothrow) int[N];
    if(!result)
    {
        delete[] tempResult;
        tempResult = nullptr;

        return nullptr;
    }

    for(int i = N - 1; i >= 0; i--)
    {
        int tempCount = 0;
        int j = 0;

        int a = i, b = 0;

        if(matchIndices[i][j] != -1)
        {
            tempResult[tempCount] = a;
            tempCount++;

            while (a >= 0 && b != -1)
            {
                b = matchIndices[a][j];

                if(b != -1)
                {
                    bool isUnique = true;

                    for(int p = 0; p < tempCount && isUnique; p++)
                    {
                        if (b == tempResult[p])
                        {
                            isUnique = false;
                        }
                    }

                    if(isUnique)
                    {
                        tempResult[tempCount] = b; 
                        tempCount++;
                        a = b;
                        j = 0;
                    }
                    else
                    {
                        if(j + 1 <= N - 2)
                        {
                            j++;
                        }
                        else
                        {
                            b = -1;
                        }
                    }
                }
            }
        }

        if(counter < tempCount)
        {
            counter = tempCount;

            for(int p = 0; p < counter; p++)
            {
                result[p] = tempResult[p];
            }
        }
    }

    delete[] tempResult;
    tempResult = nullptr;

    return result;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void arrangementOfNumbers(int** resultArr, const int& size)
{
    int p = 0;
    for (int i = 1; i < size; i++)
    {
        if(resultArr[i - 1][p + 1] != resultArr[i][p] && resultArr[i - 1][p + 1] != resultArr[i][p + 1])
        {
            swap(resultArr[i - 1][p], resultArr[i - 1][p + 1]);
        }
        if(resultArr[i - 1][p + 1] != resultArr[i][p] && resultArr[i - 1][p + 1] == resultArr[i][p + 1])
        {
             swap(resultArr[i][p], resultArr[i][p + 1]);
        }
    }
}

void printResult(int** resultArr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << resultArr[i][j];
            if(j == 0)
            {
                std::cout << "-";
            }
        }
        std::cout << "  ";
    }
}

void deleteArr(int** array, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] array[i];
    } delete[] array;
    array = nullptr;
}

int main()
{
    int N;
    std::cout << "Enter N:" << std::endl;
    N = readNumber(1);

    int** arr = new(std::nothrow) int*[N];
    if(!arr)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = new (std::nothrow) int[2];
        if(!arr[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    readArr(arr, N);

    // matchIndices keeps the indices of the pairs with which 
    // the pair at the corresponding position of the matchIndices has a matching value.
    int** matchIndices = new(std::nothrow) int*[N];
    if(!matchIndices)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        deleteArr(arr, N);
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        matchIndices[i] = new (std::nothrow) int[N - 1];
        if(!matchIndices[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            deleteArr(arr, N);
            return 1;
        }
    }

    initializeMatchIndices(matchIndices, N);

    getMatchIndices(arr, matchIndices, N);

    int counter = 0;

    // resultIndices reserves the indices of the pairs that will part of the result sequence.
    int* resultIndices = getResultIndices(matchIndices, N, counter);
    if(resultIndices == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";

        deleteArr(matchIndices, N);

        deleteArr(arr, N);

        return 1;
    }

    deleteArr(matchIndices, N);

    int** resultArr = new(std::nothrow) int*[counter];
    if(!resultArr)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        deleteArr(arr, N);

        delete[] resultIndices;
        resultIndices = nullptr;

        return 1;
    }

    for (int i = 0; i < counter; i++)
    {
        resultArr[i] = new(std::nothrow) int[2];
        if(!resultArr[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;

            deleteArr(arr, N);

            delete[] resultIndices;
            resultIndices = nullptr;

            return 1;
        }
    }

    for(int i = 0; i < counter; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            resultArr[i][j] = arr[resultIndices[i]][j];
        }
    }

    delete[] resultIndices;
    resultIndices = nullptr;

    deleteArr(arr, N);

    std::cout << "\n";
    arrangementOfNumbers(resultArr, counter);
    printResult(resultArr, counter);

    deleteArr(resultArr, counter);
    return 0;
}

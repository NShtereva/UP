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

void readArray(int array[], const int& size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = readNumber();
    }
}

void initialize(int** array, const int& rows, const int& cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            array[i][j] = -1;
        }
    }
}

int getIndexOfObject(int* array, const int& size, const int& maxV, bool* isTaken)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if (!isTaken[i] && array[i] <= maxV && index == -1)
        {
            index = i;
            isTaken[index] = true;
        }
        else if (!isTaken[i] && array[i] <= maxV && index != -1)
        {
            if (array[i] > array[index])
            {
                isTaken[index] = false;
                isTaken[i] = true;
                index = i;
            }
        }
    }

    return index;
}

void printResult(int** result, const int& K, const int& N)
{
    for(int i = 0; i < K; i++)
    {
        int counter = 0;

        for(int j = 0; j < N; j++)
        {
            if(result[i][j] != -1)
            {
                std::cout << result[i][j] << " ";
                counter++;
            }
        }
        if(counter == 0)
        {
            std::cout << "-1";
        }

        std::cout << std::endl;
    }
}

void deleteArr(int** array, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        delete[] array[i];
    } delete[] array;
    array = nullptr;
}

int main()
{
    int K;
    std::cout << "K = ";
    K = readNumber();

    //volume -> cm^3
    int* V = new(std::nothrow) int[K];
    if(!V)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    readArray(V, K);

    int N;
    std::cout << "N = ";
    N = readNumber();
    
    //weight -> g
    //1 cm^3 = 1 g
    int* W = new(std::nothrow) int[N];
    if(!W)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        
        delete[] V;
        V = nullptr;
        
        return 1;
    }

    readArray(W, N);

    int** result = new(std::nothrow) int*[K];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        
        delete[] V;
        V = nullptr;

        delete[] W;
        W = nullptr;
        
        return 1;
    }

    for(int i = 0; i < K; i++)
    {
        result[i] = new (std::nothrow) int[N];
        if(!result[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;

            delete[] V;
            V = nullptr;

            delete[] W;
            W = nullptr;

            return 1;
        }
    }

    initialize(result, K, N);

    bool* isTaken = new (std::nothrow) bool[N];
    if(!isTaken)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        
        delete[] V;
        V = nullptr;

        delete[] W;
        W = nullptr;

        deleteArr(result, K);
        
        return 1;
    }

    for(int i = 0; i < N; i++)
    {
        isTaken[i] = false;
    }

    for(int i = 0; i < K; i++)
    {
        int tempV = V[i];
        int index = 0, j = 0;
        
        while (tempV > 0 && index != -1)
        {
            index = getIndexOfObject(W, N, tempV, isTaken);

            if (index != -1)
            {
                tempV = tempV - W[index];
                result[i][j] = index + 1;
                j++;
            }
        }
    }

    delete[] isTaken;
    isTaken = nullptr;

    delete[] V;
    V = nullptr;

    delete[] W;
    W = nullptr;

    std::cout << "\n";
    printResult(result, K, N);

    deleteArr(result, K);
    return 0;
}

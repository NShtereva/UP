#include <iostream>

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

int numberOfOnes(const int& number, const bool& inEvenPositions)
{
    int position = inEvenPositions ? 0 : 1;

    int n = numberOfDigitsInBinaryNotation(number);

    int counter = 0;

    while (position < n)
    {
        bool isOne = number & (1 << position);
        counter = isOne ? counter + 1 : counter;
        position = position + 2;
    }

    return counter;
}

//a)
bool isSmaller(const int& firstNum, const int& secondNum)
{
    int a = numberOfOnes(firstNum, true), b = numberOfOnes(secondNum, true);

    if (a == b)
    {
        return numberOfOnes(firstNum, false) < numberOfOnes(secondNum, false);
    }

    return a < b;
}

//b)
void sort(int arr[], const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (isSmaller(arr[i], arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//c)
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

void readArr(int arr[], const int& size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = readNumber();
    }
}

void printArr(int arr[], const int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* removeNonUnique(int array[], const int& size, int& newSize)
{
    bool* isElementUnique = new(std::nothrow) bool[size];
    if (!isElementUnique)
    {
        return nullptr;
    }

    for(int i = 0; i < size; i++)
    {
        isElementUnique[i] = true;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i != j && numberOfOnes(array[i], true) == numberOfOnes(array[j], true) &&
                numberOfOnes(array[i], false) == numberOfOnes(array[j], false))
            {
                isElementUnique[i] = false;
            }
        }

        if(isElementUnique[i])
        {
            newSize++;
        }
    }

    int* newArray = new(std::nothrow) int[newSize];
    if (!newArray)
    {
        delete[] isElementUnique;
        isElementUnique = nullptr;

        return nullptr;
    }

    int j = 0;

    for(int i = 0; i < size; i++)
    {
        if(isElementUnique[i])
        {
            newArray[j] = array[i];
            j++;
        }
    }

    delete[] isElementUnique;
    isElementUnique = nullptr;

    return newArray;
}

int main()
{
    int N;
    std::cout << "Enter N:" << std::endl;
    N = readNumber();

    int* array = new(std::nothrow) int[N];
    if (!array)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    std::cout << "Enter array:" << std::endl;
    readArr(array, N);

    sort(array, N);

    int newSize = 0;

    int* newArray = removeNonUnique(array, N, newSize);
    if (!newArray)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        delete[] array;
        array = nullptr;

        return 1;
    }

    std::cout << std::endl;
    printArr(array, N);
    printArr(newArray, newSize);

    delete[] array;
    array = nullptr;

    delete[] newArray;
    newArray = nullptr;

    return 0;
}

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

bool isPrimeNumber(int number)
{
    if (number < 2)
        return false;

    if (number % 2 == 0)
        return number == 2;

    for(int i = 3; i * i <= number; i += 2)
    {
        if(number % i == 0)
            return false;
    }

    return true;
}

//a)
bool isFriendlyNumbers(const long long& firstNumber, const long long& secondNumber)
{
    long long helperNumber = firstNumber ^ secondNumber;

    int n = numberOfDigitsInBinaryNotation(helperNumber);
    int counter = 0;

    while(n >= 0)
    {
        int temp = helperNumber & (1 << n);
        counter = (temp != 0) ? counter + 1 : counter; 
        n--;
    }

    return counter % 2 != 0 && isPrimeNumber(counter);
}

//b)
long long* removeFriendlyNumbers(long long* array, const int& N, int& newSize)
{
    bool* isFriendlyNum = new(std::nothrow) bool[N];
    if(!isFriendlyNum)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return nullptr;
    }

    for(int i = 0; i < N; i++)
    {
        isFriendlyNum[i] = false;
    }

    for(int i = 0; i < N; i++)
    {
        int tempSum = 0, tempIndex = -1;

        for(int j = 0; j < N; j++)
        {
            if (isFriendlyNumbers(array[i], array[j]) && !isFriendlyNum[i])
            {
                isFriendlyNum[i] = true;
                isFriendlyNum[j] = true;

                tempSum = array[i] + array[j];
                tempIndex = j;
            }
            if (isFriendlyNumbers(array[i], array[j]) && isFriendlyNum[i])
            {
                int currSum = array[i] + array[j];

                if(currSum < tempSum)
                {
                    isFriendlyNum[tempIndex] = false;

                    tempSum = currSum;
                    tempIndex = j;

                    isFriendlyNum[j] = true;
                }
                else if(currSum == tempSum && j < tempIndex)
                {
                    isFriendlyNum[tempIndex] = false;

                    tempSum = currSum;
                    tempIndex = j;

                    isFriendlyNum[j] = true;
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        if (!isFriendlyNum[i])
        {
            newSize++;
        }
    }

    long long* resultArray = new(std::nothrow) long long[newSize];
    if(!resultArray)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;

        delete[] isFriendlyNum;
        isFriendlyNum = nullptr;

        return nullptr;
    }

    int index = 0;

    for(int i = 0; i < N; i++)
    {
        if (!isFriendlyNum[i])
        {
            resultArray[index] = array[i];
            index++;
        }
    }

    delete[] isFriendlyNum;
    isFriendlyNum = nullptr;

    return resultArray;
}

//c)
void streamRecovery()
{
    if(!std::cin)
    {
        std::cout << "Invalid data!\n";
        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

void readArray(long long* array, const int& N)
{
    for(int i = 0; i < N; i++)
    {
        do
        {
            std::cin >> array[i];
            streamRecovery();
        } while (array[i] <= 0);
    }
}

void printArray(long long* array, const int& N)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int N;
    do
    {
        std::cout << "Enter N:";
        std::cin >> N;
        streamRecovery();
    } while (N <= 0);

    long long* array = new(std::nothrow) long long[N];
    if (!array)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    readArray(array, N);

    std::cout << "\n";
    printArray(array, N);

    int newSize = 0;

    long long* result = removeFriendlyNumbers(array, N, newSize);
    if (!result)
    {
        delete[] array;
        array = nullptr;

        return 1;
    }

    delete [] array;
    array = nullptr;

    printArray(result, newSize);

    delete [] result;
    result = nullptr;

    return 0;
}

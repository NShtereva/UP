#include <iostream>

typedef bool(*predicat)(const int&);

bool isPositive(const int& number)
{
    return number > 0;
}

bool isNegative(const int& number)
{
    return number < 0;
}

bool isZero(const int& number)
{
    return number == 0;
}

bool isEven(const int& number)
{
    return number % 2 == 0;
}

bool isOdd(const int& number)
{
    return number % 2 != 0;
}

int counter(const predicat* p, const int& numberOfPredicats, const int* array, const int& arraySize)
{
    int count = 0;

    for(int i = 0; i < numberOfPredicats; i++)
    {
        bool isCorrectPredicat = true;

        for(int j = 0; j < arraySize && isCorrectPredicat; j++)
        {
            if (!p[i](array[j]))
                isCorrectPredicat = false;
        }

        if (isCorrectPredicat)
            count++;
    }

    return count;
}

int main()
{
    int array[] = {1, 3, 5, 7, 9};
    predicat p[] = {isPositive, isNegative, isZero, isEven, isOdd};

    std::cout << counter(p, 5, array, 5) << std::endl;
    return 0;
}

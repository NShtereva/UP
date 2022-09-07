#include <iostream>

int length(const char* number)
{
    int i = 0;
    while (number[i] != '\0')
    {
        i++;
    }
    return i;
}

bool isValidNumber(const char* number)
{
    if (!(number[0] >= '1' && number[0] <= '9') && number[0] != '-')
    {
        return false;
    }

    for (int i = 1; i < length(number); i++)
    {
        if (!(number[i] >= '0' && number[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

void readNumber(char* number)
{
    do
    {
        std::cout << "Enter a number:\n";
        std::cin >> number;
    } while (!isValidNumber(number));
}

void printNumber(const char* number)
{
    std::cout << number;
}

int compare(const char* number1, const char* number2)
{
    if (number1[0] != '-' && number2[0] == '-')
    {
        return 1;
    }
    else if (number1[0] == '-' && number2[0] != '-')
    {
        return -1;
    }
    else if (number1[0] == '-' && number2[0] == '-')
    {
        if (length(number1) > length(number2))
        {
            return -1;
        }
        else if (length(number1) < length(number2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (length(number1) > length(number2))
        {
            return 1;
        }
        else if (length(number1) < length(number2))
        {
            return -1;
        }
        else
        {
            int i = 0;
            while (number1[i] != '\0')
            {
                if (number1[i] > number2[i])
                {
                    return 1;
                }

                if (number1[i] < number2[i])
                {
                    return -1;
                }

                i++;
            }
            return 0;
        }
    }
}

void printResultOfCompare(const char* number1, const char* number2)
{
    int result = compare(number1, number2);

    if (result == 0)
    {
        std::cout << "\n" << number1 << " == " << number2;
        std::cout << "\n" << number1 << " = " << number2;
    }
    else
    {
        std::cout << "\n" << number1 << " != " << number2;
        if (result == 1)
        {
            std::cout << "\n" << number1 << " > " << number2;
        }
        else if (result == -1)
        {
            std::cout << "\n" << number1 << " < " << number2;
        }
    }
}

int charToInt(char a)
{
    return a - '0';
}

int intToChar(char a)
{
    return a + '0';
}

void calculate(char& result, const int& temp, int& p)
{
    if (temp > 9)
    {
        result = intToChar(temp % 10);
        p = 1;
    }
    else
    {
        result = intToChar(temp);
        p = 0;
    }
}

char* addSymbolInFront(const char* number, int size, const char& symbol, int& k)
{
    char* r = new char[size + 1];

    k = 0;
    r[0] = symbol;

    for (int q = 1; q < size; q++)
    {
        r[q] = number[k];
        k++;
    }
    r[size] = '\0';

    return r;
}

//Assume that both numbers are positive, the other cases are considered in function getResultOfSum
char* sum(const char* number1, const char* number2)
{
    int size = std::max(length(number1), length(number2));
    char* result = new char[size + 1];

    int i = length(number1) - 1, j = length(number2) - 1, k = size - 1, p = 0;
    //The variable 'p' has a value of 1 if the current digit becomes greater than 9

    while (i >= 0 && j >= 0)
    {
        int temp = charToInt(number1[i]) + charToInt(number2[j]) + p;
        calculate(result[k], temp, p);
        i--;
        j--;
        k--;
    }

    if (i >= 0 && j < 0)
    {
        for (int q = i; q >= 0; q--)
        {
            int temp = charToInt(number1[q]) + p;
            calculate(result[k], temp, p);
            k--;
        }
    }
    else if (i < 0 && j >= 0)
    {
        for (int q = j; q >= 0; q--)
        {
            int temp = charToInt(number2[q]) + p;
            calculate(result[k], temp, p);
            k--;
        }
    }
    else if (i < 0 && j < 0 && p == 1)
    {
        char* r = new char[size + 2];
        r = addSymbolInFront(result, size + 1, '1', k);

        delete[] result;
        r[size + 1] = '\0';
        return r;
    }

    result[size] = '\0';
    return result;
}

//Assume that number1 >= number2 > 0, the other cases are considered in function getResultOfSubtraction
char* subtraction(const char* number1, const char* number2)
{
    int size = std::max(length(number1), length(number2));
    char* result = new char[size + 1];

    int i = length(number1) - 1, j = length(number2) - 1, k = size - 1, p = 0;
    //The variable 'p' has a value of -1 if we subtract a larger digit from a smaller digit

    while (j >= 0)
    {
        int temp1, temp2 = charToInt(number2[j]);
        bool flag = false;
        if (charToInt(number1[i]) == 0 && p == -1)
        {
            temp1 = 9;
            flag = true;
        }
        else
        {
            temp1 = charToInt(number1[i]) + p;
        }

        if (temp1 >= temp2)
        {
            result[k] = intToChar(temp1 - temp2);
            p = flag ? -1 : 0;
        }
        else
        {
            int temp = 10 + temp1;
            result[k] = intToChar(temp - temp2);
            p = -1;
        }

        i--;
        j--;
        k--;
    }

    for (int q = i; q >= 0; q--)
    {
        int temp = charToInt(number1[q]) + p;
        result[k] = intToChar(temp);
        k--;
        p = 0;
    }

    result[size] = '\0';
    return result;
}

char* copyWithoutFirstSymbol(const char* number, int size)
{
    char *num = new char[size + 1];
    int k = 1;

    for (int i = 0; i < size; i++)
    {
        num[i] = number[k];
        k++;
    }
    num[size] = '\0';

    return num;
}

char* getResultOfSum(const char* number1, const char* number2)
{
    if (number1[0] != '-' && number2[0] != '-')
    {
        char* s = sum(number1, number2);
        return s;
    }

    int size1 = length(number1) - 1, size2 = length(number2) - 1, size = std::max(size1, size2) + 1, k = 0;

    if (number1[0] == '-' && number2[0] == '-')
    {
        char* n1 = copyWithoutFirstSymbol(number1, size1);
        char* n2 = copyWithoutFirstSymbol(number2, size2);
        char* s = addSymbolInFront(sum(n1, n2), size + 1, '-', k);

        delete[] n1;
        delete[] n2;
        return s;
    }

    if (number1[0] != '-' && number2[0] == '-')
    {
        char* n2 = copyWithoutFirstSymbol(number2, size2);
        if (size1 + 1 >= size2)
        {
            char* s = subtraction(number1, n2);

            delete[] n2;
            return s;
        }
        else
        {
            char* s = addSymbolInFront(subtraction(n2, number1), size, '-', k);

            delete[] n2;
            return s;
        }
    }

    if (number1[0] == '-' && number2[0] != '-')
    {
        char* n1 = copyWithoutFirstSymbol(number1, size1);
        if (size1 > size2 + 1)
        {
            char* s = addSymbolInFront(subtraction(n1, number2), size, '-', k);

            delete[] n1;
            return s;
        }
        else
        {
            char* s = subtraction(number2, n1);

            delete[] n1;
            return s;
        }
    }

    //The performance of the function should not reach this order
    return nullptr;
}

char* getResultOfSubtraction(const char* number1, const char* number2)
{
    int size1 = length(number1), size2 = length(number2), k;

    if (number1[0] != '-' && number2[0] == '-')
    {
        char* result = getResultOfSum(number1, copyWithoutFirstSymbol(number2, size2 - 1));
        return result;
    }

    if (number1[0] == '-' && number2[0] != '-')
    {
        char* result = getResultOfSum(number1, addSymbolInFront(number2, size2 + 1, '-', k));
        return result;
    }

    if (number1[0] != '-' && number2[0] != '-')
    {
        if (size1 >= size2)
        {
            char* result = subtraction(number1, number2);
            return result;
        }

        char* temp = subtraction(number2, number1);
        int size = length(temp) + 1;
        char* result = new char[size + 1];

        result = addSymbolInFront(temp, size, '-', k);

        delete[] temp;
        return result;
    }

    if (number1[0] == '-' && number2[0] == '-')
    {
        if (size1 > size2)
        {
            char* temp = subtraction(copyWithoutFirstSymbol(number1, size1 - 1), copyWithoutFirstSymbol(number2, size2 - 1));
            int size = length(temp) + 1;
            char* result = new char[size + 1];

            result = addSymbolInFront(temp, size, '-', k);

            delete[] temp;
            return result;
        }
        else
        {
            char* result = subtraction(copyWithoutFirstSymbol(number2, size2 - 1), copyWithoutFirstSymbol(number1, size1 - 1));
            return result;
        }
    }

    //The performance of the function should not reach this order
    return nullptr;
}

char* multByDigit(const char* number, char digit)
{
    int size = length(number);
    char* result = new char[size + 1];

    int p = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = charToInt(number[i]) * charToInt(digit);

        result[i] = intToChar((temp + p) % 10);

        p = (temp + p > 9) ? ((temp + p) / 10) % 10 : 0;
    }
    result[size] = '\0';

    if (p != 0)
    {
        char* r = new char[size + 2];

        int k;

        r = addSymbolInFront(result, size + 1, intToChar(p), k);

        delete[] result;
        return r;
    }

    return result;
}

char* addZerosAtTheEnd(const char* number, int count)
{
    int size = length(number) + count;
    char* result = new char[size + 1];

    int k = 0;

    for (int i = 0; i < size - count; i++)
    {
        result[i] = number[k];
        k++;
    }

    for (int i = size - count; i < size; i++)
    {
        result[i] = '0';
    }
    result[size] = '\0';

    return result;
}

//Assume that number1 >= number2 > 0, the other cases are considered in function getResultOfMult
char* mult(const char* number1, const char* number2)
{
    int size1 = length(number1), size2 = length(number2), size = size1 + size2;
    char* result = new char[size + 1];
    result[0] = '0';
    result[1] = '\0';

    int count = 0, tempResSize = 0;

    for (int i = size2 - 1; i >= 0; i--)
    {
        char* temp1 = multByDigit(number1, number2[i]);

        char* temp2 = addZerosAtTheEnd(temp1, count);

        result = sum(result, temp2);
        result[tempResSize + length(temp2)] = '\0';

        delete[] temp1;
        delete[] temp2;

        count++;
        tempResSize = length(result);
    }

    return result;
}

char* getResultOfMult(const char* number1, const char* number2)
{
    int size1 = length(number1), size2 = length(number2), k;

    if (number1[0] != '-' && number2[0] != '-')
    {
        if (size1 >= size2)
        {
            char* result = mult(number1, number2);
            return result;
        }
        else
        {
            char* result = mult(number2, number1);
            return result;
        }
    }

    if (number1[0] == '-' && number2[0] == '-')
    {
        if (size1 >= size2)
        {
            char* result = mult(copyWithoutFirstSymbol(number1, size1 - 1), copyWithoutFirstSymbol(number2, size2 - 1));
            return result;
        }
        else
        {
            char* result = mult(copyWithoutFirstSymbol(number2, size2 - 1), copyWithoutFirstSymbol(number1, size1 - 1));
            return result;
        }
    }

    if (number1[0] != '-' && number2[0] == '-')
    {
        if (size1 >= size2 - 1)
        {
            char* temp = mult(number1, copyWithoutFirstSymbol(number2, size2 - 1));
            int size = length(temp) + 1;
            char* result = new char[size + 1];

            result = addSymbolInFront(temp, size, '-', k);

            delete[] temp;
            return result;
        }
        else
        {
            char* temp = mult(copyWithoutFirstSymbol(number2, size2 - 1), number1);
            int size = length(temp) + 1;
            char* result = new char[size + 1];

            result = addSymbolInFront(temp, size, '-', k);

            delete[] temp;
            return result;
        }
    }

    if (number1[0] == '-' && number2[0] != '-')
    {
        if (size1 - 1 >= size2)
        {
            char* temp = mult(copyWithoutFirstSymbol(number1, size1 - 1), number2);
            int size = length(temp) + 1;
            char* result = new char[size + 1];

            result = addSymbolInFront(temp, size, '-', k);

            delete[] temp;
            return result;
        }
        else
        {
            char* temp = mult(number2, copyWithoutFirstSymbol(number1, size1 - 1));
            int size = length(temp) + 1;
            char* result = new char[size + 1];

            result = addSymbolInFront(temp, size, '-', k);

            delete[] temp;
            return result;
        }
    }

    return nullptr;
}

int main()
{
    char number1[8193], number2[8193];
    readNumber(number1);
    readNumber(number2);
    
    printResultOfCompare(number1, number2);

    char* s = getResultOfSum(number1, number2);
    std::cout << "\n" << number1 << " + " << number2 << " = ";
    printNumber(s);
    delete[] s;

    char* subtraction = getResultOfSubtraction(number1, number2);
    std::cout << "\n" << number1 << " - " << number2 << " = ";
    printNumber(subtraction);
    delete[] subtraction;

    char* mult = getResultOfMult(number1, number2);
    std::cout << "\n" << number1 << " * " << number2 << " = ";
    printNumber(mult);
    delete[] mult;

    return 0;
}

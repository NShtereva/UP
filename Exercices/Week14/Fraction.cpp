#include <iostream>

struct Fraction 
{
    int num;
    int denom;

    Fraction();
    Fraction(int _num, int _denom);
};

Fraction::Fraction()
{
    num = 0;
    denom = 1;
}

Fraction::Fraction(int _num, int _denom)
{
    num = _num;

    if(_denom != 0)
    {
        denom = _denom;
    }
    else
    {
        denom = 1;
    }    
}

//task 0:
void readFraction(Fraction& f)
{
    std::cout << "Enter fraction:\n";

    std::cin >> f.num;
    do
    {
        std::cin >> f.denom;
    } while (f.denom == 0);
}

int gcd(int a, int b)
{
    if(a == b) 
    {
        return a;
    }
    else if(a > b)
    {
        return gcd(a - b, b);
    }
    return gcd(a, b - a);
}

Fraction simplification(const Fraction& f)
{
    Fraction result;

    if(f.num != 0)
    {
        result.num = f.num / gcd(abs(f.num), abs(f.denom));
        result.denom = f.denom / gcd(abs(f.num), abs(f.denom));
    }
    
    return result;
}

void printFraction(Fraction& f)
{
    Fraction result = simplification(f);
    std::cout << result.num << "/" << result.denom;
}

//task 1:
int lcm(const int& a, const int& b)
{
    int result;

    for(int i = 1; i <= a * b; i++)
    {
        if(i % a == 0 && i % b == 0)
        {
            result = i;
            break;
        }
    }

    return result;
}

Fraction sum(const Fraction& f1, const Fraction& f2)
{
    Fraction result;

    int denom = lcm (f1.denom, f2.denom);

    result.num = f1.num * (denom / f1.denom) + f2.num * (denom / f2.denom);
    result.denom = denom;

    return simplification(result);
}

Fraction sub(const Fraction& f1, const Fraction& f2)
{
    Fraction result;

    int denom = lcm (f1.denom, f2.denom);

    result.num = f1.num * (denom / f1.denom) - f2.num * (denom / f2.denom);
    result.denom = denom;

    return simplification(result);
}

Fraction mult(const Fraction& f1, const Fraction& f2)
{
    Fraction result;

    result.num = f1.num * f2.num;
    result.denom = f1.denom * f2.denom;

    return simplification(result);
}

Fraction div(const Fraction& f1, const Fraction& f2)
{
    Fraction tempF2(f2.denom, f2.num);

    Fraction result = mult(f1, tempF2);
    return simplification(result);
}

//task 2:
bool isEqual(const Fraction& f1, const Fraction& f2)
{
    return f1.num * f2.denom == f2.num * f1.denom;
}

//task 3:
bool isSmaller(Fraction f1, Fraction f2)
{
    return f1.num * f2.denom < f2.num * f1.denom;
}

bool isLarger(Fraction f1, Fraction f2)
{
    return f1.num * f2.denom > f2.num * f1.denom;
}

void sort(Fraction* arr, const int& n, bool (*cmp) (Fraction, Fraction))
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cmp(arr[i], arr[j]))
            {
                Fraction temp (arr[i].num, arr[i].denom);

                arr[i].num = arr[j].num;
                arr[i].denom = arr[j].denom;

                arr[j].num = temp.num;
                arr[j].denom = temp.denom;
            }
        }
    }
}

void printArr(Fraction* arr, const int& n)
{
    for(int i = 0; i < n; i++)
    {
        printFraction(arr[i]);
        if(i < n - 1)
        {
            std::cout << ", ";
        }
    }
}

int main()
{
    Fraction f1, f2;

    readFraction(f1);
    readFraction(f2);

    //task 1:
    Fraction resultSum = sum(f1, f2);
    std::cout << "\nsum: ";
    printFraction(resultSum);

    Fraction resultSub = sub(f1, f2);
    std::cout << "\nsub: ";
    printFraction(resultSub);

    Fraction resultMult = mult(f1, f2);
    std::cout << "\nmult: ";
    printFraction(resultMult);

    Fraction resultDiv = div(f1, f2);
    std::cout << "\ndiv: ";
    printFraction(resultDiv);

    //task 2:
    if(isEqual(f1, f2))
    {
        std::cout << "\nThe fractions are equal!\n";
    }
    else
    {
        std::cout << "\nFractions are not equal!\n";
    }

    //task 3:
    Fraction f3(5, 9), f4(1, 7);
    Fraction arr[4] = {f1, f2, f3, f4};

    std::cout << "\nSort ascending:\n";
    sort(arr, 4, isLarger);
    printArr(arr, 4);

    std::cout << "\n\nSort descending:\n";
    sort(arr, 4, isSmaller);
    printArr(arr, 4);
    return 0;
}

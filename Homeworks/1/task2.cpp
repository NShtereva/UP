#include <iostream>

int getDigit(const int& num, const int& position)
{
    switch (position)
    {
        case 0: return (num / 1) % 2;
        case 1: return (num / 2) % 2;
        case 2: return (num / 4) % 2;
        case 3: return (num / 8) % 2;
        case 4: return (num / 16) % 2;
        case 5: return (num / 32) % 2;
        case 6: return (num / 64) % 2;
        case 7: return (num / 128) % 2;
        case 8: return (num / 256) % 2;
        case 9: return (num / 512) % 2;
        case 10: return (num / 1024) % 2;
        case 11: return (num / 2048) % 2;
        case 12: return (num / 4096) % 2;
    }

    return 2;
}

int getH(const int& num)
{
    int firstDigit = getDigit(num, 10) + 2 * getDigit(num, 11);
    int secondDigit = getDigit(num, 6) + 2 * getDigit(num, 7) + 4 * getDigit(num, 8) + 8 * getDigit(num, 9);

    return firstDigit * 10 + secondDigit;
}

int getMin(const int& num)
{
    return getDigit(num, 0) + 2 * getDigit(num, 1) + 4 * getDigit(num, 2) + 
                                       8 * getDigit(num, 3) + 16 * getDigit(num, 4) + 32 * getDigit(num, 5);
}

bool isValidTime(const int& num)
{
    int f24 = getDigit(num, 12), h = getH(num), min = getMin(num);

    if(f24)
    {
        return (h >= 0 && h < 24) && (min >= 0 && min < 60);  
    }
    return (h > 0 && h <= 12) && (min >= 0 && min < 60);  
}

void diff(const int& h1, const int& min1, const int& h2, const int& min2)
{
    std::cout << "diff ";

    if(h1 > h2)
    {
        if(min1 - min2 < 0)
        {
            std::cout << h1 - 1 - h2 << ":" << min1 + 60 - min2 << std::endl;
            return;
        }
        std::cout << h1 - h2 << ":" << min1 - min2 << std::endl;
    }
    else if(h1 < h2)
    {
        if(min2 - min1 < 0)
        {
            std::cout << h2 - 1 - h1 << ":" << min2 + 60 - min1 << std::endl;
            return;
        }
        std::cout << h2 - h1 << ":" << min2 - min1 << std::endl;
    }
    else
    {
        std::cout << "0:" << std::abs(min1 - min2) << std::endl;
    }
}

int main()
{
    int num1, num2;
    std::cout << "first number:" << std::endl;
    std::cin >> num1;
    std::cout << "second number:" << std::endl;
    std::cin >> num2;
    
    if(!isValidTime(num1) || !isValidTime(num2))
    {
        std::cout << "\nInvalid time!" << std::endl;
        return 1;
    }
    
    std::cout << std::endl;
    
    int h1 = getH(num1), min1 = getMin(num1), h2 = getH(num2), min2 = getMin(num2);
    std::cout << h1 << ":" << min1 << std::endl;
    std::cout << h2 << ":" << min2 << std::endl;
    
    diff(h1, min1, h2, min2);
    return 0;
}

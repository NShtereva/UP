#include <iostream>

int main()
{
    unsigned short int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    unsigned short int result = 0;

    for(int i = 0; i < 16; i++)
    {
        if(num & (1 << i))
            result = result | (1 << (15 - i));
    }

    std::cout << std::endl;
    std::cout << result << std::endl;
    return 0;
}
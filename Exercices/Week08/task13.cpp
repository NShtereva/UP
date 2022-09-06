#include <iostream>
#include <cstring>

int main()
{
    const unsigned SIZE = 256;
    char str[SIZE], num[SIZE];

    std::cout << "str: ";
    std::cin >> str;
    std::cout << std::endl;

    int j = 0, len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num[j] = str[i];
            j++;
        }
    }
    num[j] = '\0';

    int sum = 0;
    for (int i = 0; i < j; i++)
    {
        sum = sum + (num[i] - '0');
    }

    std::cout << "sum = " << sum << "\n";
    return 0;
}

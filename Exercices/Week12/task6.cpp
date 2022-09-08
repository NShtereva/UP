#include <iostream>
#include <cstring>

bool helper(int i, int j, const char* str)
{
    if(i >= j)
    {
        return true;
    }

    if(str[i] != str[j])
    {
        return false;
    }

    return helper(i + 1, j - 1, str);
}

bool isPalindrome(char* str)
{
    if(strlen(str) < 2)
    {
        return true;
    }
    return helper(0, strlen(str) - 1, str);
}

int main()
{
    const size_t MAX_LEN = 256;
    char str[MAX_LEN];

    std::cout << "Enter string:" << std::endl;
    std::cin.getline(str, MAX_LEN);

    std::cout << std::endl;
    std::cout << std::boolalpha << isPalindrome(str) << std::endl;
    return 0;
}

#include <iostream>
#include <cstring>

void concatStr(const char* str1, const char* str2, char* concat)
{
    int len1 = strlen(str1);
    for (int i = 0; i < len1; i++)
    {
        concat[i] = str1[i];
    }

    int len2 = strlen(str2);
    for (int i = 0; i < len2; i++)
    {
        concat[len1] = str2[i];
        len1++;
    }

    concat[len1] = '\0';
}

int main()
{
    const unsigned SIZE = 256;
    char str1[SIZE], str2[SIZE], concat[2 * SIZE + 1];

    std::cout << "str1: ";
    std::cin >> str1;
    std::cout << "str2: ";
    std::cin >> str2;
    std::cout << "\n";

    concatStr(str1, str2, concat);
    std::cout << "concatStr: " << concat << "\n";
    return 0;
}

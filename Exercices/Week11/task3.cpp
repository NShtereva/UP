#include <iostream>

int length(const char* a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    return i;
}

int counter(const char* str, const char* word)
{
    int count = 0;
    int lenS = length(str), lenW = length(word);
    
    for(int i = 0; i < lenS; i++)
    {
        if(str[i] == word[0] && i + lenW - 1 < lenS)
        {
            bool flag = true;

            for(int j = 0; j < lenW && flag; j++)
            {
                if(str[i + j] != word[j])
                    flag = false;
            }

            if(flag)
            {
                count++;
                i = i + lenW - 1;
            }
        }
    }

    return count;
}

int main()
{
    char word[10], str[256];

    std::cout<< "Enter string:" << std::endl;
    std::cin.getline(str, 256);

    std::cout<< "Enter word:" << std::endl;
    std::cin >> word;

    std::cout << std::endl;
    std::cout << counter(str, word) << std::endl;
    return 0;
}

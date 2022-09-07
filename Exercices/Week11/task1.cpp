#include <iostream>
#include <cstring>

int main()
{
    const size_t MAX_LEN = 101;
    char str[MAX_LEN];

    std::cout << "Enter string:\n";
    std::cin.getline(str, MAX_LEN);
    
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
            str[i] = '\n';
    }

    std::cout << std::endl;
    std::cout << str << std::endl;
    return 0;
}
